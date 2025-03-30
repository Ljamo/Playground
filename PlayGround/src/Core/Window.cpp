#include <pch.h>
#include "Window.h"

#include <vulkan/vulkan.h>

std::shared_ptr<Renderer> Window::m_Renderer;

Window::Window(unsigned int w, unsigned int h, RenderType renderType, RenderAPI renderApi)
    : m_Width(w), m_Height(h), m_RenderType(renderType), m_RenderAPI(renderApi)
{
    std::cout << "Dimensions: " << m_Width << " x " << m_Height << "\n";
    std::string rType = m_RenderType == RenderType::Headerless ? "Headerless" : "Windowed";
    std::cout << "Render Mode: " << rType << "\n";
    switch(m_RenderType)
    {
        case RenderType::Headerless:
        {
            InitHeaderless();
            break;
        }
        case RenderType::Windowed:
        {
            InitWindowed();
            break;
        }
        default:
        {
            InitHeaderless();
            break;
        }
    }
}

Window::~Window()
{
    // delete m_WindowHandle;
    glfwTerminate();
    m_Window = nullptr;
}

void Window::OnUpdate()
{
    // processInput(window);
    if (!m_RenderType == RenderType::Headerless)
    {
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
        if (m_RenderAPI == RenderAPI::OpenGL)
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }
        if (m_RenderAPI == RenderAPI::Vulkan)
        {

        }
    }
}

void Window::InitHeaderless()
{
    std::cout << "Initiated Headerless.\n";
}

void Window::InitWindowed()
{
    std::cout << "Initiated Windowed Rendering.\n";

    // Failsafe needs to be implemented in here
    if (!CreateWindow())
    {
        throw std::runtime_error("Could not create window!");
        // ShutDown();
    }
}

bool Window::CreateWindow()
{
    glfwInit();

    m_Renderer = CreateRenderer(m_RenderAPI);

    switch (m_RenderAPI)
    {
    case RenderAPI::OpenGL:
    {
        if (!InitGlad())
            return false;
        break;
    }
    case RenderAPI::Vulkan:
    {
        if (!InitVulkan())
            return false;
        break;
    }
    default:
    {
        throw std::runtime_error("Must have a RenderAPI for windowed mode!");

        return false;
        //ShutDown();
        break;
    }
    }

    glfwMakeContextCurrent(m_Window);
    
    glfwSetWindowUserPointer(m_Window, this);  // Store the OpenGLContext instance
    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);    

    // glfwSetWindowUserPointer(m_Window, this);  // Store the OpenGLContext instance
    // glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

    return true;
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    std::cout << "Frame Callback: " << std::to_string(width) << " x " << std::to_string(height) << "\n";

    // Window* context = static_cast<Window*>(glfwGetWindowUserPointer(window));
    // if (context)
    // {
    //     context->SetViewport(width, height);
    // }
}

void Window::ShutDown()
{
    // TODO shutdown

}

bool Window::ShouldWindowClose()
{
    if (m_RenderType == RenderType::Headerless)
        return false;
    else
        return glfwWindowShouldClose(m_Window);
}

bool Window::InitGlad()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(m_Width, m_Height, "OpenGL Window", NULL, NULL);
    if (m_Window == NULL)
    {
        throw std::runtime_error("Could not create OpenGL window!");
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Could not initialize Glad!");
        return false;
    }

    // TODO maybe not include this?
    // glViewport(0, 0, m_Width, m_Height);

    return true;
}

bool Window::InitVulkan()
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    m_Window = glfwCreateWindow(m_Width, m_Height, "Vulkan Window", NULL, NULL);
    if (m_Window == NULL)
    {
        throw std::runtime_error("Could not create Vulkan window!");
        glfwTerminate();
        return false;
    }

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << "Extension count: " << extensionCount << "\n";
    
}