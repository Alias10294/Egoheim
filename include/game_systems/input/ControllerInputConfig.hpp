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

    bool Load(const std::string& config, const InputContext context);
    bool Save(const std::string& config, const InputContext context);

private:
    std::map<InputContext, std::map<InputAction, std::vector<ControllerInput>>> m_bindings{};
};

#endif