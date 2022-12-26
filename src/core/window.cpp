#include "window.hpp"
#include "defines.hpp"
#include <GLFW/glfw3.h>

namespace game
{
    window::window()
    {
        init(mProps);
    }

    window::window(const windowProperties &props)
    {
    }

    window::~window()
    {
        shutdown();
    }

    void window::update()
    {
        glfwPollEvents();
        glfwSwapBuffers(mGLFWInstance);
    }

    void window::setWidth(u32 width)
    {
        mProps.width = width;
        glfwSetWindowSize(mGLFWInstance, mProps.width, mProps.height);
    }
    void window::setHeight(u32 height)
    {
        mProps.height = height;
        glfwSetWindowSize(mGLFWInstance, mProps.width, mProps.height);
    }
    void window::setSize(u32 width, u32 height)
    {
        mProps.width = width;
        mProps.height = height;
        glfwSetWindowSize(mGLFWInstance, mProps.width, mProps.height);
    }
    void window::setTitle(const char *title)
    {
        mProps.title = title;
        glfwSetWindowTitle(mGLFWInstance, title);
    }
    void window::setXPos(u32 xpos)
    {
        mProps.xpos = xpos;
        glfwSetWindowPos(mGLFWInstance, mProps.xpos, mProps.ypos);
    }
    void window::setYPos(u32 ypos)
    {
        mProps.ypos = ypos;
        glfwSetWindowPos(mGLFWInstance, mProps.xpos, mProps.ypos);
    }

    void window::setPos(u32 xpos, u32 ypos)
    {
        mProps.xpos = xpos;
        mProps.ypos = ypos;
        glfwSetWindowPos(mGLFWInstance, mProps.xpos, mProps.ypos);
    }
    void window::init(const windowProperties &props)
    {
        ASSERT_MSG(glfwInit(), "Failed to initialize GLFW.");

        if (props.resizable) 
        {
            glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        }

        mGLFWInstance = glfwCreateWindow(props.width, props.height, props.title, props.startFullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);

        ASSERT_MSG(mGLFWInstance, "Failed to create GLFW window.");

        glfwMakeContextCurrent(mGLFWInstance);
        glfwSwapInterval(props.vsync);

        setPos(props.xpos, props.ypos);
        

    }
    void window::shutdown()
    {
        glfwDestroyWindow(mGLFWInstance);
        glfwTerminate();
    }
}