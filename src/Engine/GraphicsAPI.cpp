#include "GraphicsAPI.hpp"
#include "OpenGL.hpp"
#include <ErrorCodes.hpp>
#include <Platform.hpp>
#include <glad/glad.hpp>
#include <log.hpp>
#include <stdlib.h>

namespace LT {

    GraphicsAPI api = {};

    // VULKAN declarations
    static void VK_Init();
    static void VK_SetViewport(const Rect* in_value) {}

    void GraphicsAPI_Init(const GRAPHIC_API in_api) {
        switch (in_api) {
        case GRAPHIC_API::OPENGL: {
          LoadProc proc = Platform::InitOpenGL();
          if (gladLoadGLLoader(proc) == 0) {
            log_fatal("Could not initialize glad.");
            exit(ERROR_GRAPHICS_API_INITIALIZATION);
            }
            api.clearScreenColor8 = GL_ClearScreenColor8;
            api.clearScreenColor = GL_ClearScreenColor;
            api.clearScreen = GL_ClearScreen;
            api.enableAlphaBlending = GL_EnableAlphaBlending;
            api.enableDepthTesting = GL_EnableDepthTesting;
            api.enableStencilTesting = GL_EnableStencilTesting;
            api.enableScissorTesting = GL_EnableScissorTesting;
            api.setScissor = GL_SetScissor;
            api.setViewport = GL_SetViewport;
            break;
        }
        case GRAPHIC_API::VULKAN: {
            log_fatal("API %d not implemented!", in_api);
            exit(ERROR_GRAPHICS_API_NOT_IMPLEMENTED);
            api.setViewport = VK_SetViewport;
        }
        }
        api.swapBuffers = Platform::GetPlatformSwapBuffer();

        log_info("GraphicsAPI initialized.");
    }

    void VK_Init() {

    }
}