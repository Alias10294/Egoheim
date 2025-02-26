#ifndef GLOBALEVENT_HPP
#define GLOBALEVENT_HPP

#include <iostream>
#include <variant>

#include "../input/InputAction.hpp"

struct ButtonInputEvent
{
    int controllerIndex; 
    InputAction action; 
    bool isPressed; 
    bool isJustPressed; 
    bool isJustReleased; 
};
struct AxisInputEvent
{
    int controllerIndex; 
    InputAction action; 
    short value; 
};
struct RegularInputEvent
{
    int controllerIndex; 
    InputAction action; 
};

using InputEvent = std::variant
<
    ButtonInputEvent, 
    AxisInputEvent, 
    RegularInputEvent 
>;


using Event = std::variant
<
    InputEvent
>;

#endif