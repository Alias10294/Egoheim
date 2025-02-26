#ifndef INPUTACTION_HPP
#define INPUTACTION_HPP

enum class InputAction
{
    INPUTACTION_MIN = -1, 
    
    MOVE_UP         = 0,
    MOVE_DOWN       = 1, 
    MOVE_LEFT       = 2, 
    MOVE_RIGHT      = 3, 

    DODGE           = 4, 
    ATTACK          = 5, 
    PARRY           = 6, 
    LABILITY        = 7, // Q or LT/L1 ability (by default)
    RABILITY        = 8, // E or RT/R1 ability (by default)
    PAUSE           = 9, 

    CLICK           = 10, 
    BACK            = 11, 
    CURSOR_MOTION   = 12, 

    INPUTACTION_MAX = 13 
};

[[nodiscard]] inline const InputAction StringToInputAction(const std::string& str)
{
    if (str == std::string("MOVE_UP"))       return InputAction::MOVE_UP;
    if (str == std::string("MOVE_DOWN"))     return InputAction::MOVE_DOWN;
    if (str == std::string("MOVE_LEFT"))     return InputAction::MOVE_LEFT;
    if (str == std::string("MOVE_RIGHT"))    return InputAction::MOVE_RIGHT;

    if (str == std::string("DODGE"))         return InputAction::DODGE;
    if (str == std::string("ATTACK"))        return InputAction::ATTACK;
    if (str == std::string("PARRY"))         return InputAction::PARRY;
    if (str == std::string("LABILITY"))      return InputAction::LABILITY;
    if (str == std::string("RABILITY"))      return InputAction::RABILITY;
    if (str == std::string("PAUSE"))         return InputAction::PAUSE;

    if (str == std::string("CLICK"))         return InputAction::CLICK;
    if (str == std::string("BACK"))          return InputAction::BACK;
    if (str == std::string("CURSOR_MOTION")) return InputAction::CURSOR_MOTION;

    return InputAction::INPUTACTION_MIN;
}
[[nodiscard]] inline const std::string InputActionToString(const InputAction action)
{
    switch (action)
    {
    case InputAction::MOVE_UP:       return std::string("MOVE_UP");
    case InputAction::MOVE_DOWN:     return std::string("MOVE_DOWN");
    case InputAction::MOVE_LEFT:     return std::string("MOVE_LEFT");
    case InputAction::MOVE_RIGHT:    return std::string("MOVE_RIGHT");

    case InputAction::DODGE:         return std::string("DODGE");
    case InputAction::ATTACK:        return std::string("ATTACK");
    case InputAction::PARRY:         return std::string("PARRY");
    case InputAction::LABILITY:      return std::string("LABILITY");
    case InputAction::RABILITY:      return std::string("RABILITY");
    case InputAction::PAUSE:         return std::string("PAUSE");

    case InputAction::CLICK:         return std::string("CLICK");
    case InputAction::BACK:          return std::string("BACK");
    case InputAction::CURSOR_MOTION: return std::string("CURSOR_MOTION");

    default:                         return std::string();
    }
}

#endif