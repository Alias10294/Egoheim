#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "SDL.h"
#include "../event/EventDispatcher.hpp"
#include "DesktopState.hpp"
#include "ControllerState.hpp"
#include "InputConfig.hpp"
#include "DesktopInput.hpp"
#include "ControllerInput.hpp"

constexpr std::size_t NBMAX_CONTROLLERS = 2;

class InputManager
{
public:
    InputManager(InputContext& context, EventDispatcher& dispatcher);
    ~InputManager();

    void ProcessInputs();

private:
    InputContext& m_context;
    EventDispatcher& m_dispatcher;

    DesktopState m_desktopState;
    std::array<ControllerState, NBMAX_CONTROLLERS> m_controllerStates;

    InputConfig<DesktopInput> m_desktopInputConfig;
    std::array<InputConfig<ControllerInput>, NBMAX_CONTROLLERS> m_controllerInputConfigs;

    void HandleKeyboardEvent(const SDL_KeyboardEvent& event);

    void HandleMouseButtonEvent(const SDL_MouseButtonEvent& event);
    void HandleMouseWheelEvent(const SDL_MouseWheelEvent& event);
    void HandleMouseMotionEvent(const SDL_MouseMotionEvent& event);

    void HandleControllerAddedEvent(const SDL_ControllerDeviceEvent& event);
    void HandleControllerRemovedEvent(const SDL_ControllerDeviceEvent& event);

    void HandleControllerButtonEvent(const SDL_ControllerButtonEvent& event); 
    void HandleControllerAxisEvent(const SDL_ControllerAxisEvent& event);

    [[nodiscard]] const bool IsKeyPressed(const SDL_Scancode scancode) const noexcept;
    [[nodiscard]] const bool IsKeyJustPressed(const SDL_Scancode scancode) const noexcept;
    [[nodiscard]] const bool IsKeyJustReleased(const SDL_Scancode scancode) const noexcept;

    [[nodiscard]] const bool IsMouseButtonPressed(const Uint8 button) const noexcept;
    [[nodiscard]] const bool IsMouseButtonJustPressed(const Uint8 button) const noexcept;
    [[nodiscard]] const bool IsMouseButtonJustReleased(const Uint8 button) const noexcept;

    [[nodiscard]] const bool IsControllerButtonPressed(const SDL_GameControllerButton button, const int controllerIndex) const noexcept;
    [[nodiscard]] const bool IsControllerButtonJustPressed(const SDL_GameControllerButton button, const int controllerIndex) const noexcept;
    [[nodiscard]] const bool IsControllerButtonJustReleased(const SDL_GameControllerButton button, const int controllerIndex) const noexcept;

    [[nodiscard]] const ButtonInputEvent TranslateToKeyboardEvent(const SDL_Scancode scancode) const noexcept;

    [[nodiscard]] const ButtonInputEvent TranslateToMouseButtonEvent(const Uint8 button) const noexcept;
    [[nodiscard]] const AxisInputEvent TranslateToMouseWheelEvent() const noexcept;
    [[nodiscard]] const CursorMotionInputEvent TranslateToCursorMotionEvent() const noexcept;

    [[nodiscard]] const DeviceInputEvent TranslateToControllerAddedEvent(const int controllerIndex) const noexcept;
    [[nodiscard]] const DeviceInputEvent TranslateToControllerRemovedEvent(const int controllerIndex) const noexcept;

    [[nodiscard]] const ButtonInputEvent TranslateToControllerButtonEvent(const SDL_GameControllerButton button, const int controllerIndex) const noexcept;
    [[nodiscard]] const AxisInputEvent TranslateToControllerAxisEvent(const SDL_GameControllerAxis axis, const int controllerIndex) const noexcept;
    
};

#endif