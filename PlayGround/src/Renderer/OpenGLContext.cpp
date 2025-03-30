#include "pch.h"
#include "OpenGLContext.h"

// OpenGLContext::OpenGLContext(int w, int h)
// {
// 	Init(w, h);
// }
/*
void OpenGLContext::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    std::cout << "Frame Callback\n";

    OpenGLContext* context = static_cast<OpenGLContext*>(glfwGetWindowUserPointer(window));
    if (context)
    {
        context->SetViewport(width, height);
    }
}

bool OpenGLContext::Init(int w, int h)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(w, h, "LearnOpenGL", NULL, NULL);
    if (m_Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    SetViewport(w, h);

    glfwSetWindowUserPointer(m_Window, this);  // Store the OpenGLContext instance
    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

    return true;
}

void OpenGLContext::OnUpdate()
{
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

void OpenGLContext::SetViewport(int xi, int yi, int w, int h)
{
    glViewport(xi, yi, w, h);
}

void OpenGLContext::SetViewport(int w, int h)
{
    glViewport(0, 0, w, h);
}
*/