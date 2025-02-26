#ifndef INPUTCONTEXT_HPP
#define INPUTCONTEXT_HPP

enum class InputContext
{
    INPUTCONTEXT_MIN = -1,

    MENU             = 0, 
    COMBAT           = 1, 

    INPUTCONTEXT_MAX = 2
};

[[nodiscard]] inline const InputContext StringToInputContext(const std::string& str)
{
    if (str == std::string("MENU"))   return InputContext::MENU;
    if (str == std::string("COMBAT")) return InputContext::COMBAT;

    return InputContext::INPUTCONTEXT_MIN;
}
[[nodiscard]] inline const std::string InputContextToString(const InputContext context)
{
    switch (context)
    {
    case InputContext::MENU:   return std::string("MENU");
    case InputContext::COMBAT: return std::string("COMBAT");

    default:                   return std::string();
    }
}

#endif