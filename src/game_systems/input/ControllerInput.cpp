#include "ControllerInput.hpp"

ControllerInput::ControllerInput(const ControllerInputType type, const long value)
    : Input<ControllerInputType, ControllerInput>(type, value)
{}

const std::string ControllerInput::GetConfigFileImpl()
{
    return std::string("controller-input-config.json"); 
}

const std::string ControllerInput::InputEnumToStringImpl(const ControllerInputType type)
{
    switch (type)
    {
    case ControllerInputType::BUTTON:  return std::string("button");
    case ControllerInputType::AXIS:    return std::string("axis");
    case ControllerInputType::INVALID: return std::string();
    }
    return std::string();
}
const ControllerInputType ControllerInput::StringToInputEnumImpl(const std::string& typeStr)
{
    if      (typeStr == std::string("button")) return ControllerInputType::BUTTON;
    else if (typeStr == std::string("axis"))   return ControllerInputType::AXIS;
    else                                       return ControllerInputType::INVALID;
}