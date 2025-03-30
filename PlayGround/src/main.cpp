#include <pch.h>
#include "Core/Application.h"
#include <cctype>
#include <vector>

struct AppSettings {
    int width = 720;  // Default width
    int height = 460; // Default height
    RenderType renderType = RenderType::Windowed;
    RenderAPI renderAPI = RenderAPI::OpenGL; // 0 = OpenGL, 1 = Vulkan
};

void ParseCommandLineArgs(int argc, char* argv[], AppSettings& settings) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-d" && i + 2 < argc) {
            settings.width = std::stoi(argv[i + 1]);
            settings.height = std::stoi(argv[i + 2]);
            i += 2;
        }
        else if (arg == "-a" && i + 1 < argc) {
            std::string api = argv[i + 1];

            // Convert API name to lowercase
            for (auto& c : api)
                c = std::tolower(c);

            if (api == "vulkan") {
                settings.renderAPI = RenderAPI::Vulkan;
            }
            else if (api == "opengl") {
                settings.renderAPI = RenderAPI::OpenGL;
            }
            else {
                std::cerr << "Error: Unknown render API '" << api << "'. Defaulting to OpenGL.\n";
                settings.renderAPI = RenderAPI::OpenGL;
            }

            i += 1;
        }
        else if (arg == "-h") {
            settings.renderType = RenderType::Headerless;
        }
    }
}

int main(int argc, char** argv)
{
    AppSettings appSettings;
    // std::vector<std::string> args = { "none", "-a", "vulkan" };
    // 
    // // Fake argc and argv for testing
    // int fake_argc = static_cast<int>(args.size());
    // char** fake_argv = new char* [fake_argc];
    // 
    // for (int i = 0; i < fake_argc; i++) {
    //     fake_argv[i] = const_cast<char*>(args[i].c_str());
    // }

    // Call your actual argument-parsing function
    ParseCommandLineArgs(argc, argv, appSettings);

    // Application* app = nullptr;
    std::shared_ptr<Application>app;
    app = std::make_shared<Application>(appSettings.width, appSettings.height, appSettings.renderAPI, appSettings.renderType);

    app->Run();

    std::cout << "Ended Application\n";
    // std::cin.get();
    return 0;
}