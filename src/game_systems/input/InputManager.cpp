#include "InputManager.hpp"

InputManager::InputManager(InputContext& context, EventDispatcher& dispatcher)
    : m_context(context), 
      m_dispatcher(dispatcher),
      m_desktopState(), 
      m_controllerStates{ ControllerState(), ControllerState() }, 
      m_desktopInputConfig(), 
      m_controllerInputConfigs{ InputConfig<ControllerInput>(), InputConfig<ControllerInput>() }
{ }
InputManager::~InputManager()
{ }

void InputManager::ProcessInputs()
{ 
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYUP:
        case SDL_KEYDOWN:
            HandleKeyboardEvent(event.key);
            m_dispatcher.Dispatch(TranslateToKeyboardEvent(event.key.keysym.scancode));
            break;
        
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEBUTTONDOWN:
            HandleMouseButtonEvent(event.button);
            m_dispatcher.Dispatch(TranslateToMouseButtonEvent(event.button.button));
            break;
        case SDL_MOUSEWHEEL:
            HandleMouseWheelEvent(event.wheel);
            m_dispatcher.Dispatch(TranslateToMouseWheelEvent());
            break;
        case SDL_MOUSEMOTION:
            HandleMouseMotionEvent(event.motion);
            m_dispatcher.Dispatch(TranslateToCursorMotionEvent());
            break;
        
        case SDL_CONTROLLERDEVICEADDED:
            HandleControllerAddedEvent(event.cdevice);
            m_dispatcher.Dispatch(TranslateToControllerAddedEvent(event.cdevice.which));
            break;
        case SDL_CONTROLLERDEVICEREMOVED:
            HandleControllerRemovedEvent(event.cdevice);
            m_dispatcher.Dispatch(TranslateToControllerRemovedEvent(event.cdevice.which));
            break;
        
        case SDL_CONTROLLERBUTTONUP:
        case SDL_CONTROLLERBUTTONDOWN:
            HandleControllerButtonEvent(event.cbutton);
            m_dispatcher.Dispatch(TranslateToControllerButtonEvent((SDL_GameControllerButton)event.cbutton.button, event.cdevice.which));
            break;
        case SDL_CONTROLLERAXISMOTION:
            HandleControllerAxisEvent(event.caxis);
            m_dispatcher.Dispatch(TranslateToControllerAxisEvent((SDL_GameControllerAxis)event.caxis.axis, event.cdevice.which));
            break;

        default:
            break;
        }
    }
}

void InputManager::HandleKeyboardEvent(const SDL_KeyboardEvent& event)
{
    m_desktopState.keyboard.current[event.keysym.scancode] = event.state == SDL_PRESSED;
}
void InputManager::HandleMouseButtonEvent(const SDL_MouseButtonEvent& event)
{
    m_desktopState.mouse.current[event.button] = event.state == SDL_PRESSED;
}
void InputManager::HandleMouseMotionEvent(const SDL_MouseMotionEvent& event)
{
    m_desktopState.mouse.x = event.x;
    m_desktopState.mouse.y = event.y;
}
void InputManager::HandleMouseWheelEvent(const SDL_MouseWheelEvent& event)
{
    m_desktopState.mouse.wheelDelta = event.y;
}
void InputManager::HandleControllerAddedEvent(const SDL_ControllerDeviceEvent& event)
{
    if (SDL_IsGameController(event.which))
        return;
    
    for (std::size_t i = 0; i < NBMAX_CONTROLLERS; i++)
    {
        if (m_controllerStates[i].controller != nullptr)
            continue;
        
        SDL_GameController* controller = SDL_GameControllerOpen(event.which);
        if (controller)
        {
            SDL_JoystickID joystickID = SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controller));
            ControllerState controllerState = ControllerState{ controller, joystickID, {}, {}, {} };
            controllerState.previous.fill(false);
            controllerState.current.fill(false);
            controllerState.axisValues.fill(0);
            m_controllerStates[i] = controllerState;
        }
        break;
    }
}
void InputManager::HandleControllerRemovedEvent(const SDL_ControllerDeviceEvent& event)
{
    for (ControllerState& state : m_controllerStates)
    {
        if (state.joystickID == event.which && state.controller)
        {
            SDL_GameControllerClose(state.controller);
            state.controller = nullptr;
        }
        state.joystickID = -1;
        break;
    }
}
void InputManager::HandleControllerButtonEvent(const SDL_ControllerButtonEvent& event)
{
    for (ControllerState& state : m_controllerStates)
    {
        if (state.joystickID == event.which)
        {
            state.current[event.button] = event.state == SDL_PRESSED;
            break;
        }
    }
}
void InputManager::HandleControllerAxisEvent(const SDL_ControllerAxisEvent& event)
{
    for (ControllerState& state : m_controllerStates)
    {
        if (state.joystickID == event.which)
        {
            state.axisValues[event.axis] = event.value;
            break;
        }
    }
}

const bool InputManager::IsKeyPressed(const SDL_Scancode scancode) const noexcept
{
    return  m_desktopState.keyboard.current [static_cast<std::size_t>(scancode)];
}
const bool InputManager::IsKeyJustPressed(const SDL_Scancode scancode) const noexcept
{
    return  m_desktopState.keyboard.current [static_cast<std::size_t>(scancode)]
        && !m_desktopState.keyboard.previous[static_cast<std::size_t>(scancode)];
}
const bool InputManager::IsKeyJustReleased(const SDL_Scancode scancode) const noexcept
{
    return !m_desktopState.keyboard.current [static_cast<std::size_t>(scancode)]
        &&  m_desktopState.keyboard.previous[static_cast<std::size_t>(scancode)];
}

const bool InputManager::IsMouseButtonPressed(const Uint8 button) const noexcept
{
    return  m_desktopState.mouse.current [static_cast<std::size_t>(button)];
}
const bool InputManager::IsMouseButtonJustPressed(const Uint8 button) const noexcept
{
    return  m_desktopState.mouse.current [static_cast<std::size_t>(button)]
        && !m_desktopState.mouse.previous[static_cast<std::size_t>(button)];
}
const bool InputManager::IsMouseButtonJustReleased(const Uint8 button) const noexcept
{
    return !m_desktopState.mouse.current [static_cast<std::size_t>(button)]
        &&  m_desktopState.mouse.previous[static_cast<std::size_t>(button)];
}

const bool InputManager::IsControllerButtonPressed(const SDL_GameControllerButton button, const int controllerIndex) const noexcept
{
    return  m_controllerStates[controllerIndex].current [static_cast<std::size_t>(button)];
}
const bool InputManager::IsControllerButtonJustPressed(const SDL_GameControllerButton button, const int controllerIndex) const noexcept
{
    return  m_controllerStates[controllerIndex].current [static_cast<std::size_t>(button)]
        && !m_controllerStates[controllerIndex].previous[static_cast<std::size_t>(button)];
}
const bool InputManager::IsControllerButtonJustReleased(const SDL_GameControllerButton button, const int controllerIndex) const noexcept
{
    return !m_controllerStates[controllerIndex].current [static_cast<std::size_t>(button)]
        &&  m_controllerStates[controllerIndex].previous[static_cast<std::size_t>(button)];
}

const ButtonInputEvent InputManager::TranslateToKeyboardEvent(const SDL_Scancode scancode) const noexcept
{
    return ButtonInputEvent
    {
        -1, 
        m_desktopInputConfig.GetActionFrom<SDL_Scancode>(m_context, scancode), 
        IsKeyPressed(scancode), 
        IsKeyJustPressed(scancode), 
        IsKeyJustReleased(scancode)
    };
}

const ButtonInputEvent InputManager::TranslateToMouseButtonEvent(const Uint8 button) const noexcept
{
    return ButtonInputEvent
    {
        -1, 
        m_desktopInputConfig.GetActionFrom<Uint8>(m_context, button), 
        IsMouseButtonPressed(button), 
        IsMouseButtonJustPressed(button), 
        IsMouseButtonJustReleased(button)
    };
}
const AxisInputEvent InputManager::TranslateToMouseWheelEvent() const noexcept
{
    return AxisInputEvent
    {
        -1, 
        InputAction::MOUSE_WHEEL, 
        m_desktopState.mouse.wheelDelta
    };
}
const CursorMotionInputEvent InputManager::TranslateToCursorMotionEvent() const noexcept
{
    return CursorMotionInputEvent
    {
        -1, 
        InputAction::CURSOR_MOTION, 
        m_desktopState.mouse.x, 
        m_desktopState.mouse.y
    };
}

const DeviceInputEvent InputManager::TranslateToControllerAddedEvent(const int controllerIndex) const noexcept
{
    return DeviceInputEvent 
    {
        controllerIndex, 
        InputAction::DEVICE_ADDED
    };
}
const DeviceInputEvent InputManager::TranslateToControllerRemovedEvent(const int controllerIndex) const noexcept
{
    return DeviceInputEvent
    {
        controllerIndex, 
        InputAction::DEVICE_REMOVED
    };
}

const ButtonInputEvent InputManager::TranslateToControllerButtonEvent(const SDL_GameControllerButton button, const int controllerIndex) const noexcept
{
    return ButtonInputEvent
    {
        controllerIndex, 
        m_controllerInputConfigs[controllerIndex].GetActionFrom<SDL_GameControllerButton>(m_context, button), 
        IsControllerButtonPressed(button, controllerIndex), 
        IsControllerButtonJustPressed(button, controllerIndex), 
        IsControllerButtonJustReleased(button, controllerIndex)
    };
}
const AxisInputEvent InputManager::TranslateToControllerAxisEvent(const SDL_GameControllerAxis axis, const int controllerIndex) const noexcept
{
    return AxisInputEvent
    {
        controllerIndex, 
        m_controllerInputConfigs[controllerIndex].GetActionFrom<SDL_GameControllerAxis>(m_context, axis, m_controllerStates[controllerIndex].axisValues[static_cast<std::size_t>(axis)]), 
        m_controllerStates[controllerIndex].axisValues[static_cast<std::size_t>(axis)]
    };
}