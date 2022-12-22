#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "defines.hpp"

int main () {
    ASSERT_MSG(glfwInit(), "Failed to initialize GLFW.")

    GLFWwindow* window = glfwCreateWindow(1280, 720, "2D Game", nullptr, nullptr);

    ASSERT_MSG(window, "ailed to create GLFW window.");

    glfwMakeContextCurrent(window);

    ASSERT_MSG(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to load glad");

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

}