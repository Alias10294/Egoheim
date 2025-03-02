#ifndef DESKTOPINPUTCONFIG_HPP
#define DESKTOPINPUTCONFIG_HPP

#include <map>
#include <vector>

#include "SDL.h"
#include "InputAction.hpp"
#include "InputContext.hpp"

enum class DesktopInputType
{
    KEY         = 0, 
    MOUSEBUTTON = 1, 
    MOUSEWHEEL  = 2 
};

struct DesktopInput
{
    DesktopInputType type;
    long value;
};

class DesktopInputConfig
{
public:
    ~DesktopInputConfig();
    
    [[nodiscard]] const InputAction GetActionFromScancode(const InputContext context, const SDL_Scancode scancode) const;
    [[nodiscard]] const InputAction GetActionFromMouseButton(const InputContext context, const Uint8 mouseButton) const;

    const bool Load(const std::string& config, const InputContext context);
    const bool Save(const std::string& config, const InputContext context) const;

private:
    std::map<InputContext, std::map<InputAction, std::vector<DesktopInput>>> m_bindings{};
};

#endif