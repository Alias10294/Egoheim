#ifndef CONTROLLERINPUT_HPP
#define CONTROLLERINPUT_HPP

#include <string>

#include "Input.hpp"

enum class ControllerInputType
{
    BUTTON  = 0,
    AXIS    = 1, 
    INVALID = 2
};

class ControllerInput : public Input<ControllerInputType, ControllerInput>
{
public:
    ControllerInput(const ControllerInputType type, const long value = 0L);
    ~ControllerInput() = default;

    [[nodiscard]] static const std::string GetConfigFileImpl();

    [[nodiscard]] static const std::string InputEnumToStringImpl(const ControllerInputType type);
    [[nodiscard]] static const ControllerInputType StringToInputEnumImpl(const std::string& typeStr);
};

#endif