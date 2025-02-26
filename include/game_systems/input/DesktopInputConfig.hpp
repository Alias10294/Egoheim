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
    DesktopInputConfig();
    ~DesktopInputConfig();

    bool Load(const std::string& config, const InputContext context);
    bool Save(const std::string& config, const InputContext context);

private:
    std::map<InputContext, std::map<InputAction, std::vector<DesktopInput>>> m_bindings;
};

#endif