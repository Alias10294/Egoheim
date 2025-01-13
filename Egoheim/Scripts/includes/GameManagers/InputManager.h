#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL2/SDL.h>
#include <vector>
#include <unordered_map>

constexpr const int NUM_SCANCODES = SDL_NUM_SCANCODES;
constexpr const int NB_MOUSE_BUTTONS = 5;
constexpr const int NB_CONTROLLERS = 2;

class InputManager 
{
public:
    InputManager();
    ~InputManager();

    void Init();
    void Quit();

    void HandleEvent(SDL_Event& event);
    void UpdatePreviousStates();

    bool IsKeyPressed(SDL_Scancode scancode) const;
    bool IsKeyJustPressed(SDL_Scancode scancode) const;
    bool IsKeyJustReleased(SDL_Scancode scancode) const;

    bool IsMouseButtonPressed(int button) const;
    bool IsMouseButtonJustPressed(int button) const;
    bool IsMouseButtonJustReleased(int button) const;
    int GetMouseX() const;
    int GetMouseY() const;

    bool IsControllerButtonPressed(int controllerIndex, SDL_GameControllerButton button) const;
    bool IsControllerButtonJustPressed(int controllerIndex, SDL_GameControllerButton button) const;
    bool IsControllerButtonJustReleased(int controllerIndex, SDL_GameControllerButton button) const;
    int GetControllerAxis(int controllerIndex, SDL_GameControllerAxis axis) const;


private:
    void HandleKeyboardEvent(const SDL_KeyboardEvent& keyboardEvent);
    void HandleMouseMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent);
    void HandleMouseButtonEvent(const SDL_MouseButtonEvent& mouseButtonEvent);
    void HandleMouseWheelEvent(const SDL_MouseWheelEvent& mouseWheelEvent);
    void HandleControllerDeviceAdded(int deviceIndex);
    void HandleControllerDeviceRemoved(SDL_JoystickID joystickID);
    void HandleControllerButtonEvent(const SDL_ControllerButtonEvent& cbuttonEvent);
    void HandleControllerAxisEvent(const SDL_ControllerAxisEvent& caxisEvent);

    bool m_currentKeyStates[NUM_SCANCODES];
    bool m_previousKeyStates[NUM_SCANCODES];

    bool m_currentMouseButtonStates[NB_MOUSE_BUTTONS];
    bool m_previousMouseButtonStates[NB_MOUSE_BUTTONS];
    int m_mouseX;
    int m_mouseY;
    int m_mouseWheelDelta;


    struct ControllerInput
    {
        SDL_GameController* controller = nullptr;
        SDL_JoystickID joystickID = -1;

        std::unordered_map<SDL_GameControllerButton, bool> currentButtonStates;
        std::unordered_map<SDL_GameControllerButton, bool> previousButtonStates;

        std::unordered_map<SDL_GameControllerAxis, int> axisValues;
    };
    ControllerInput m_controllerInput[NB_CONTROLLERS];
};

#endif INPUTMANAGER_H
