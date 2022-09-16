#ifndef GLFW_CLIENT_KEYLISTENER_H
#define GLFW_CLIENT_KEYLISTENER_H
#include "incs.h"

class KeyListener {
public:
    static void keyCallback(GLFWwindow* glfwWindow, int key, int scancode, int action, int mods);
    static bool isKeyPressed(int keyCode);
    static KeyListener keyListener;
};


#endif //GLFW_CLIENT_KEYLISTENER_H
