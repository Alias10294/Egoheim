#ifndef DESKTOPINPUT_HPP
#define DESKTOPINPUT_HPP

#include <string>

#include "Input.hpp"

enum class DesktopInputType
{
    KEY         = 0, 
    MOUSEBUTTON = 1, 
    MOUSEWHEEL  = 2, 
    INVALID     = 3
};

class DesktopInput : public Input<DesktopInputType, DesktopInput>
{
public:
    DesktopInput(const DesktopInputType type, const long value = 0L);
    ~DesktopInput() = default;

    [[nodiscard]] static const std::string GetConfigFileImpl();

    [[nodiscard]] static const std::string InputEnumToStringImpl(const DesktopInputType type);
    [[nodiscard]] static const DesktopInputType StringToInputEnumImpl(const std::string& typeStr);
};

#endif