#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "core/window.hpp"

int main () {
    game::window window = game::window(game::windowProperties(1280, 720, "2D Game"));

    while(window.isOpen()) {
        window.update();
    }
}