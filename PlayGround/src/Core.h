#ifdef USE_OPENGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#elif defined(USE_VULKAN)
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h> // Needed for Vulkan surface creation
#endif
