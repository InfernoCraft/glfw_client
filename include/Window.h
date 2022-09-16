#ifndef GLFW_CLIENT_WINDOW_H
#define GLFW_CLIENT_WINDOW_H
#include "incs.h"

class Window {
private:
    int width, height;
    const char* title;
    static Window window;
    void init();
    void loop();


public:
    GLFWwindow* glfwWindow;
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    float r, g, b, a;
    void run();
    Window();
};

#endif
