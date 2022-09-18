#ifndef GLFW_CLIENT_KEYLISTENER_H
#define GLFW_CLIENT_KEYLISTENER_H
#include "../incs.h"

class KeyListener {
public:
    // function describers (like static) should be placed in the header if instance-less utilization is desired
    static void keyCallback(GLFWwindow* glfwWindow, int key, int scancode, int action, int mods);
    static bool isKeyPressed(int keyCode);
};

#endif