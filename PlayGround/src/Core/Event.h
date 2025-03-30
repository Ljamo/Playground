#pragma once

enum EventType
{
	None, WindowResize, WindowClose, WindowMaximize, WindowMinimize,
	KeyboardPress, KeyPress, KeyRelease,
	MouseMoved, MouseLeftClick, MouseRightClick, MouseScroll, MouseScrollClick
};

class Event
{
public:
	bool IsKeyPressed(GLFWwindow* window);
	bool IsMouseClicked();
private:
};