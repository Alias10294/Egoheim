#include "../../includes/GameManagers/InputManager.h"

InputManager::InputManager()
	: m_mouseX(0), m_mouseY(0), m_mouseWheelDelta(0)
{
	for (int i = 0; i < NB_SCANCODES; i++)
	{
		m_currentKeyStates[i] = false;
		m_previousKeyStates[i] = false;
	}
	for (int i = 0; i < NB_MOUSE_BUTTONS; i++)
	{
		m_currentMouseButtonStates[i] = false;
		m_previousMouseButtonStates[i] = false;
	}
}
InputManager::~InputManager() 
{
	Quit();
}

void InputManager::Init()
{
	for (int i = 0; i < NB_CONTROLLERS; i++)
	{
		if (SDL_IsGameController(i))
			HandleControllerDeviceAdded(i);
	}
}
void InputManager::Quit()
{
	for (ControllerInput controllerInfo : m_controllerInput)
	{
		if (controllerInfo.controller)
			HandleControllerDeviceRemoved(controllerInfo.joystickID);
	}
}

void InputManager::HandleEvent(SDL_Event& event)
{
	switch (event.type)
	{
	case SDL_KEYUP:
		HandleKeyboardEvent(event.key);
		break;

	case SDL_MOUSEMOTION:
		HandleMouseMotionEvent(event.motion);
		break;
	case SDL_MOUSEBUTTONUP:
		HandleMouseButtonEvent(event.button);
		break;
	case SDL_MOUSEWHEEL:
		HandleMouseWheelEvent(event.wheel);
		break;

	case SDL_CONTROLLERDEVICEADDED:
		HandleControllerDeviceAdded(event.cdevice.which);
		break;
	case SDL_CONTROLLERDEVICEREMOVED:
		HandleControllerDeviceRemoved(event.cdevice.which);
		break;
	case SDL_CONTROLLERBUTTONUP:
		HandleControllerButtonEvent(event.cbutton);
		break;
	case SDL_CONTROLLERAXISMOTION:
		HandleControllerAxisEvent(event.caxis);
		break;
	
	default:
		break;
	}
}
void InputManager::UpdatePreviousStates()
{
	for (int i = 0; i < NB_SCANCODES; i++)
		m_previousKeyStates[i] = m_currentKeyStates[i];
	for (int i = 0; i < NB_MOUSE_BUTTONS; i++)
		m_previousMouseButtonStates[i] = m_currentMouseButtonStates[i];

	for (int i = 0; i < NB_CONTROLLERS; i++)
	{
		for (const auto& button : m_controllerInput[i].currentButtonStates)
			m_controllerInput[i].previousButtonStates[button.first] = m_controllerInput[i].currentButtonStates[button.first];
	}
}

bool InputManager::IsKeyPressed(SDL_Scancode scancode) const
{
	return m_currentKeyStates[scancode];
}
bool InputManager::IsKeyJustPressed(SDL_Scancode scancode) const
{
	return m_currentKeyStates[scancode] && !m_previousKeyStates[scancode];
}
bool InputManager::IsKeyJustReleased(SDL_Scancode scancode) const
{
	return !m_currentKeyStates[scancode] && m_previousKeyStates[scancode];
}

bool InputManager::IsMouseButtonPressed(int button) const
{
	return m_currentMouseButtonStates[--button];
}
bool InputManager::IsMouseButtonJustPressed(int button) const
{
	--button;
	return m_currentMouseButtonStates[button] && !m_previousMouseButtonStates[button];
}
bool InputManager::IsMouseButtonJustReleased(int button) const
{
	--button;
	return !m_currentMouseButtonStates[button] && m_previousMouseButtonStates[button];
}
int InputManager::GetMouseX() const
{
	return m_mouseX;
}
int InputManager::GetMouseY() const
{
	return m_mouseY;
}

bool InputManager::IsControllerButtonPressed(int controllerIndex, SDL_GameControllerButton cbutton) const
{
	if (controllerIndex >= 0) 
		return m_controllerInput[controllerIndex].currentButtonStates.at(cbutton);
	return false;
}
bool InputManager::IsControllerButtonJustPressed(int controllerIndex, SDL_GameControllerButton cbutton) const
{
	if (controllerIndex >= 0)
		return m_controllerInput[controllerIndex].currentButtonStates.at(cbutton) && !m_controllerInput[controllerIndex].previousButtonStates.at(cbutton);
	return false;
}
bool InputManager::IsControllerButtonJustReleased(int controllerIndex, SDL_GameControllerButton cbutton) const
{
	if (controllerIndex >= 0)
		return !m_controllerInput[controllerIndex].currentButtonStates.at(cbutton) && m_controllerInput[controllerIndex].previousButtonStates.at(cbutton);
	return false;
}
int InputManager::GetControllerAxis(int controllerIndex, SDL_GameControllerAxis axis) const
{
	if (controllerIndex >= 0)
		return m_controllerInput[controllerIndex].axisValues.at(axis);
	return 0;
}


void InputManager::HandleKeyboardEvent(const SDL_KeyboardEvent& keyboardEvent)
{
	m_currentKeyStates[keyboardEvent.keysym.scancode] = keyboardEvent.state == SDL_PRESSED;
}
void InputManager::HandleMouseMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent)
{
	m_mouseX = mouseMotionEvent.x;
	m_mouseY = mouseMotionEvent.y;
}
void InputManager::HandleMouseButtonEvent(const SDL_MouseButtonEvent& mouseButtonEvent)
{
	m_currentMouseButtonStates[mouseButtonEvent.button - 1] = mouseButtonEvent.state == SDL_PRESSED;
}
void InputManager::HandleMouseWheelEvent(const SDL_MouseWheelEvent& mouseWheelEvent)
{
	m_mouseWheelDelta = mouseWheelEvent.y;
}
void InputManager::HandleControllerDeviceAdded(int deviceIndex)
{
	for (int i = 0; i < NB_CONTROLLERS; i++)
	{
		if (m_controllerInput[i].controller == nullptr)
		{
			SDL_GameController* controller = SDL_GameControllerOpen(deviceIndex);
			if (controller)
			{
				ControllerInput controllerInfo;
				controllerInfo.controller = controller;
				controllerInfo.joystickID = SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controller));

				for (int button = SDL_CONTROLLER_BUTTON_A; button < SDL_CONTROLLER_BUTTON_MAX; button++)
				{
					controllerInfo.currentButtonStates[(SDL_GameControllerButton)button] = false;
					controllerInfo.previousButtonStates[(SDL_GameControllerButton)button] = false;
				}
				for (int axis = SDL_CONTROLLER_AXIS_LEFTX; axis < SDL_CONTROLLER_AXIS_MAX; axis++)
					controllerInfo.axisValues[(SDL_GameControllerAxis)axis] = 0;
			}
		}
		break;
	}
}
void InputManager::HandleControllerDeviceRemoved(SDL_JoystickID joystickID)
{
	for (int i = 0; i < NB_CONTROLLERS; i++)
	{
		if (m_controllerInput[i].joystickID == joystickID)
		{
			if (m_controllerInput[i].controller)
			{
				SDL_GameControllerClose(m_controllerInput[i].controller);
				m_controllerInput[i].controller = nullptr;
			}
			m_controllerInput[i].joystickID = -1;
			break;
		}
	}
}
void InputManager::HandleControllerButtonEvent(const SDL_ControllerButtonEvent& cbuttonEvent)
{
	for (ControllerInput controllerInfo : m_controllerInput)
	{
		if (controllerInfo.joystickID == cbuttonEvent.which)
			controllerInfo.currentButtonStates[(SDL_GameControllerButton)cbuttonEvent.button] = cbuttonEvent.state == SDL_PRESSED;
	}
}
void InputManager::HandleControllerAxisEvent(const SDL_ControllerAxisEvent& caxisEvent)
{
	for (ControllerInput controllerInfo : m_controllerInput)
	{
		if (controllerInfo.joystickID == caxisEvent.which)
			controllerInfo.axisValues[(SDL_GameControllerAxis)caxisEvent.axis] = caxisEvent.value;
	}
}