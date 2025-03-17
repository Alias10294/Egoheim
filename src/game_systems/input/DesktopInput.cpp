#include "DesktopInput.hpp"

DesktopInput::DesktopInput(const DesktopInputType type, const long value)
    : Input<DesktopInputType, DesktopInput>(type, value)
{}

const std::string DesktopInput::GetConfigFileImpl()
{
    return std::string("config/input/desktop-input-config.json"); 
}

const std::string DesktopInput::InputEnumToStringImpl(const DesktopInputType type)
{
    switch (type)
    {
    case DesktopInputType::KEY:         return std::string("key");
    case DesktopInputType::MOUSEBUTTON: return std::string("mouse-button");
    case DesktopInputType::MOUSEWHEEL:  return std::string("mouse-wheel");
    case DesktopInputType::INVALID:     return std::string();
    }
    return std::string();
}
const DesktopInputType DesktopInput::StringToInputEnumImpl(const std::string& typeStr)
{
    if      (typeStr == std::string("key"))          return DesktopInputType::KEY;
    else if (typeStr == std::string("mouse-button")) return DesktopInputType::MOUSEBUTTON;
    else if (typeStr == std::string("mouse-wheel"))  return DesktopInputType::MOUSEWHEEL;
    else                                             return DesktopInputType::INVALID;
}