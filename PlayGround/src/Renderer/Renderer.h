#include "pch.h"
#include "OpenGLContext.h"

enum RenderType
{
    Headerless, Windowed
};

enum RenderAPI
{
    None, OpenGL, Vulkan
};

// Abstract base class
class Renderer {
public:
    virtual ~Renderer() = default;  // Virtual destructor for proper cleanup
    virtual bool SetViewport(uint32_t w, uint32_t h) = 0;
    virtual bool SetViewport(uint32_t xi, uint32_t yi, uint32_t w, uint32_t h) = 0;
};

// OpenGLRenderer implementation
class OpenGLRenderer : public Renderer {
public:
    bool SetViewport(uint32_t w, uint32_t h) override {
        std::cout << "Setting OpenGL viewport: " << w << "x" << h << "\n";
        glViewport(0, 0, w, h);
        return true;
    }

    bool SetViewport(uint32_t xi, uint32_t yi, uint32_t w, uint32_t h) override {
        std::cout << "Setting OpenGL viewport with offset: " << xi << "," << yi << " " << w << "x" << h << "\n";
        glViewport(xi, yi, w, h);
        return true;
    }
};

// VulkanRenderer implementation (TODO)
class VulkanRenderer : public Renderer {
public:
    bool SetViewport(uint32_t w, uint32_t h) override {
        std::cout << "Vulkan SetViewport not implemented\n";
        return false;
    }

    bool SetViewport(uint32_t xi, uint32_t yi, uint32_t w, uint32_t h) override {
        std::cout << "Vulkan SetViewport not implemented\n";
        return false;
    }
};

std::shared_ptr<Renderer> CreateRenderer(RenderAPI renderAPI);