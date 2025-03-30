#include "Window.h"

class Application
{
public:
    Application(unsigned int w, unsigned int h, RenderAPI renderApi, RenderType renderType)
        : m_Width(w), m_Height(h), m_RenderType(renderType), m_Window(w, h, renderType, renderApi), m_RenderAPI(renderApi) {}
    void Run();

    static void EndApplication() { s_Running = false; }
private:
    unsigned int m_Width, m_Height;
    const RenderType m_RenderType;
    Window m_Window;

    const RenderAPI m_RenderAPI;

    static bool Application::s_Running;
};