#pragma once

#include "defines.hpp"

#include <GLFW/glfw3.h>

namespace game {
    struct windowProperties {
        u32 width, height;
        const char* title;
        u32 xpos, ypos;
        bool resizable, vsync, startFullscreen;

        windowProperties() = default;

        windowProperties(u32 width, u32 height, const char* title, u32 xpos = 0, u32 ypos = 30,
                         bool resizable = true, bool vsync = true, bool startFullScreen = false)
            : width(width),
              height(height),
              title(title),
              xpos(xpos),
              ypos(ypos),
              resizable(resizable),
              vsync(vsync),
              startFullscreen(startFullScreen) {
        }
    };
    class window {
       public:
        window();

        window(const windowProperties& props);

        ~window();

        void update();

        inline const windowProperties& getProperties() const {
            return mProps;
        }
        inline GLFWwindow* getGLFWInstance() const {
            return mGLFWInstance;
        }

        inline bool isOpen() const {
            return !glfwWindowShouldClose(mGLFWInstance);
        }

        void
        setWidth(u32 width);

        void setHeight(u32 height);

        void setSize(u32 width, u32 height);

        void setTitle(const char* title);

        void setXPos(u32 xpos);

        void setYPos(u32 ypos);

        void setPos(u32 xpos, u32 ypos);

       private:
        GLFWwindow* mGLFWInstance;

        void init(const windowProperties& props);

        void shutdown();

        windowProperties mProps;
    };
}  // namespace game