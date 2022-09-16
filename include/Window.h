#ifndef GLFW_CLIENT_WINDOW_H
#define GLFW_CLIENT_WINDOW_H
#include "incs.h"

class Window {
private:
    static Window window;
    const char* title;
    int width, height;

    void init();
    void loop();

public:
    GLFWwindow* glfwWindow;
    float r, g, b, a;

    // define standard values
    Window();

    // initializations and native loop
    void run();
    // void function collapses on error
    void errorHandling(const char* desc);
};

#endif
