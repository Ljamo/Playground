#include "Renderer/Renderer.h"
#include "pch.h"

class Window
{
public:
    Window(unsigned int w, unsigned int h, RenderType renderType, RenderAPI renderApi);
    ~Window();
    void OnUpdate();

    bool ShouldWindowClose();

    Window(const Window&) = delete;
    Window &operator=(const Window &) = delete;

private:
    void InitHeaderless();
    void InitWindowed();
    bool CreateWindow();
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void ShutDown();

    bool InitGlad();
    bool InitVulkan();

    static std::shared_ptr<Renderer>& GetRenderer() 
    { 
        if (m_Renderer) return m_Renderer; 
        else throw std::runtime_error("Renderer is not initialized!"); }

private:
    const unsigned int m_Width, m_Height;
    const RenderType m_RenderType;
    static std::shared_ptr<Renderer> m_Renderer;

    // Should make this shared_ptr
    // WindowHandle* m_WindowHandle = nullptr;
    RenderAPI m_RenderAPI;
    GLFWwindow* m_Window = nullptr;
};