#include <fstream>
#include <string>

#include "DesktopInputConfig.hpp"
#include "nlohmann/json.hpp"

DesktopInputConfig::DesktopInputConfig()
{}
DesktopInputConfig::~DesktopInputConfig()
{}

bool DesktopInputConfig::Load(const std::string& config, const InputContext context)
{
    std::ifstream file("desktop-input-config.json");
    if (!file.is_open())
        return false;
    
    nlohmann::json jBindings; 
    file >> jBindings; 
    file.close();
    m_bindings.clear();

    const std::string contextStr = InputContextToString(context);
    if (jBindings.find(contextStr) == jBindings.end())
        return false;
    
    if (jBindings[contextStr].find(config) == jBindings[contextStr].end())
        return false;
    
    for (auto& [actionStr, inputs] : jBindings[contextStr][config].items())
    {
        const InputAction action = StringToInputAction(actionStr);
        if (action == InputAction::INPUTACTION_MIN)
            continue;
        
        for (auto& input : inputs)
        {
            if (input.find("input-type")  == input.end()) continue;
            if (input.find("input-value") == input.end()) continue;
            
            const std::string inputTypeStr = input["input-type"].get<std::string>();
            DesktopInputType inputType;
            if      (inputTypeStr == "key")          inputType = DesktopInputType::KEY;
            else if (inputTypeStr == "mouse-button") inputType = DesktopInputType::MOUSEBUTTON;
            else if (inputTypeStr == "mouse-wheel")  inputType = DesktopInputType::MOUSEWHEEL;
            
            long inputValue = 0;
            if      (input["input-value"].is_number()) inputValue = input["input-value"].get<long>();
            else if (input["input-value"].is_string()) inputValue = std::stol(input["input-value"].get<std::string>());

            m_bindings[context][action].push_back({ inputType, inputValue });
        }
    }
    return true;
}
bool DesktopInputConfig::Save(const std::string& config, const InputContext context)
{
    std::ifstream inFile("desktop-input-config.json");
    if (!inFile.is_open())
        return false;
    
    nlohmann::json jBindings; 
    inFile >> jBindings; 
    inFile.close();

    const std::string contextStr = InputContextToString(context);
    if (jBindings.find(contextStr) == jBindings.end())
        return false;
    
    if (jBindings[contextStr].find(config) != jBindings[contextStr].end())
        jBindings[contextStr][config] = nlohmann::json::object();
    
    for (auto& [action, inputs] : m_bindings[context])
    {
        const std::string actionStr = InputActionToString(action);
        jBindings[contextStr][config][actionStr] = nlohmann::json::array();
        for (DesktopInput input : inputs)
        {
            nlohmann::json jInput;
            std::string inputTypeStr;
            switch (input.type)
            {
            case DesktopInputType::KEY:         inputTypeStr = "key"; break;
            case DesktopInputType::MOUSEBUTTON: inputTypeStr = "mouse-button"; break;
            case DesktopInputType::MOUSEWHEEL:  inputTypeStr = "mouse-wheel"; break;
            
            default:                            inputTypeStr = ""; break;
            }

            jInput["input-type"]  = inputTypeStr;
            jInput["input-value"] = input.value;

            jBindings[contextStr][config][actionStr].push_back(jInput);
        }
    }

    std::ofstream outFile("desktop-input-config.json");
    if (!outFile.is_open())
        return false;
    
    outFile << std::setw(4) << jBindings;
    outFile.close();

    return true;
}