#include <fstream>
#include <string>

#include "ControllerInputConfig.hpp"
#include "nlohmann/json.hpp"

ControllerInputConfig::~ControllerInputConfig()
{}

bool ControllerInputConfig::Load(const std::string& config, const InputContext context)
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
            ControllerInputType inputType;
            if      (inputTypeStr == "button") inputType = ControllerInputType::BUTTON;
            else if (inputTypeStr == "axis")   inputType = ControllerInputType::AXIS;
            
            long inputValue = 0;
            if      (input["input-value"].is_number()) inputValue = input["input-value"].get<long>();
            else if (input["input-value"].is_string()) inputValue = std::stol(input["input-value"].get<std::string>());

            m_bindings[context][action].push_back({ inputType, inputValue });
        }
    }
    return true;
}
bool ControllerInputConfig::Save(const std::string& config, const InputContext context)
{
    std::ifstream inFile("controller-input-config.json");
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
    
    for (auto& bindings : m_bindings[context])
    {
        const std::string actionStr = InputActionToString(bindings.first);
        jBindings[contextStr][config][actionStr] = nlohmann::json::array();
        for (ControllerInput input : bindings.second)
        {
            nlohmann::json jInput;
            std::string inputTypeStr;
            switch (input.type)
            {
            case ControllerInputType::BUTTON: inputTypeStr = "button"; break;
            case ControllerInputType::AXIS:   inputTypeStr = "axis"; break;
            
            default:                            inputTypeStr = ""; break;
            }

            jInput["input-type"]  = inputTypeStr;
            jInput["input-value"] = input.value;

            jBindings[contextStr][config][actionStr].push_back(jInput);
        }
    }

    std::ofstream outFile("controller-input-config.json");
    if (!outFile.is_open())
        return false;
    
    outFile << std::setw(4) << jBindings;
    outFile.close();

    return true;
}