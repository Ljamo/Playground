#include <pch.h>
#include "Renderer.h"

#ifdef PG_ENABLE_RENDERER_OPENGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif

#ifdef PG_ENABLE_RENDERER_VULKAN
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#endif

// Factory function to create a renderer
std::shared_ptr<Renderer> CreateRenderer(RenderAPI renderAPI) {
    switch (renderAPI)
    {
#ifdef PG_ENABLE_RENDERER_OPENGL

    case (RenderAPI::OpenGL):
    {
        return std::make_shared<OpenGLRenderer>();

    }
#endif
#ifdef PG_ENABLE_RENDERER_VULKAN
    case (RenderAPI::Vulkan):
    {
        return std::make_shared<VulkanRenderer>();

    }
#endif
    }

    std::cerr << "Invalid Renderer API selected!" << std::endl;
    return nullptr;
}