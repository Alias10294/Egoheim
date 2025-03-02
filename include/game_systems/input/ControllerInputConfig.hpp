#ifndef CONTROLLERINPUTCONFIG_HPP
#define CONTROLLERINPUTCONFIG_HPP

#include <map>
#include <vector>

#include "SDL.h"
#include "InputAction.hpp"
#include "InputContext.hpp"

enum class ControllerInputType
{
    BUTTON = 0, 
    AXIS   = 1
};

struct ControllerInput
{
    ControllerInputType type;
    long value;
};

class ControllerInputConfig
{
public:
    ~ControllerInputConfig();

    [[nodiscard]] const InputAction GetActionFromButton(const InputContext context, const SDL_GameControllerButton button) const;
    [[nodiscard]] const InputAction GetActionFromAxis(const InputContext context, const SDL_GameControllerAxis axis, const unsigned short value) const;

    const bool Load(const std::string& config, const InputContext context);
    const bool Save(const std::string& config, const InputContext context) const;

private:
    const InputAction GetActualAction(const InputAction action, const unsigned short value) const;

    std::map<InputContext, std::map<InputAction, std::vector<ControllerInput>>> m_bindings{};
};

#endif