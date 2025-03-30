#include <pch.h>
#include "Application.h"

bool Application::s_Running = true;

void Application::Run()
{
    // TODO turn this into loop
    while (s_Running && glfwCreateCursor && !m_Window.ShouldWindowClose())
    {


        m_Window.OnUpdate();
    }
}