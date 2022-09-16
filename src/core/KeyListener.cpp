#include "../../include/incs.h"

static bool keyPressed[350];

void KeyListener::keyCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        keyPressed[key] = true;
    } else if (action == GLFW_RELEASE) {
        keyPressed[key] = false;
    }
}

bool KeyListener::isKeyPressed(int keyCode) {
    return keyPressed[keyCode];
}
