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
    int value; 
};
struct CursorMotionInputEvent
{
    int controllerIndex;
    InputAction action = InputAction::CURSOR_MOTION;
    int x;
    int y;
};
struct DeviceInputEvent
{
    int controllerIndex;
    InputAction action;
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
    CursorMotionInputEvent, 
    DeviceInputEvent
>;


using Event = std::variant
<
    InputEvent
>;

#endif