#ifndef INPUTCONFIG_HPP
#define INPUTCONFIG_HPP

#include <concepts>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "nlohmann/json.hpp"
#include "InputContext.hpp"
#include "InputAction.hpp"

template<typename T>
concept CanBeLong = std::convertible_to<T, long>;

template<typename InputType>
class InputConfig
{
public:
    InputConfig()
        : m_bindings()
    {
        Load("default", InputContext::MENU);
        Load("default", InputContext::COMBAT);
    }
    ~InputConfig() = default;

    template<CanBeLong InputId>
    [[nodiscard]] inline const InputAction GetActionFrom(const InputContext context, const InputId id, const unsigned short value = 0L) const
    {
        for (auto& bindings : m_bindings.at(context))
        {
            auto it = std::find_if
            (
                bindings.second.begin(), 
                bindings.second.end(), 
                [id](const InputType& input)
                {
                    return input.value == static_cast<long>(id);
                }
            );
            if (it != bindings.second.end())
                return GetActualAction(bindings.first, value);
        }
        return InputAction::INPUTACTION_MAX;
    }

    inline const bool Load(const std::string& config, const InputContext context)
    {
        std::ifstream inFile(InputType::GetConfigFile());
        if (!inFile.is_open())
            return false;
        
        nlohmann::json jBindings; 
        inFile >> jBindings; 
        inFile.close(); 
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

                m_bindings[context][action].emplace_back
                (
                    InputType::StringToInputEnum(input["input-type"].get<std::string>()), 
                    input["input-value"].get<long>() 
                );
            }
        }
        return true;
    }
    inline const bool Save(const std::string& config, const InputContext context) const
    {
        std::ifstream inFile(InputType::GetConfigFile());
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
        
        for (auto& bindings : m_bindings.at(context))
        {
            const std::string actionStr = InputActionToString(bindings.first);
            jBindings[contextStr][config][actionStr] = nlohmann::json::array();
            for (InputType input : bindings.second)
            {
                nlohmann::json jInput;

                jInput["input-type"]  = InputType::InputEnumToString(input.type);
                jInput["input-value"] = input.value;

                jBindings[contextStr][config][actionStr].push_back(jInput);
            }
        }

        std::ofstream outFile(InputType::GetConfigFile());
        if (!outFile.is_open())
            return false;
        
        outFile << std::setw(4) << jBindings;
        outFile.close();

        return true;
    }

private:
    [[nodiscard]] inline const InputAction GetActualAction(const InputAction action, const unsigned short value) const
    {
        // TODO
        return InputAction::INPUTACTION_MIN;
    }
    std::unordered_map<InputContext, std::unordered_map<InputAction, std::vector<InputType>>> m_bindings;
};

#endif