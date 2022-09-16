#ifndef GLFW_CLIENT_MOUSELISTENER_H
#define GLFW_CLIENT_MOUSELISTENER_H
#include "incs.h"


class MouseListener {
public:
    static void mousePosCallback(GLFWwindow* glfwWindow, double xpos, double ypos);
    static void mouseButtonCallback(GLFWwindow* glfwWindow, int button, int action, int mods);
    static void mouseScrollCallback(GLFWwindow* glfwWindow, double xOffset, double yOffset);

    static double getX();
    static double getY();
    static double getDx();
    static double getDy();
    static double getScrollX();
    static double getScrollY();
    static bool isDragging();
    static bool mouseButtonDown(int button);
};


#endif //GLFW_CLIENT_MOUSELISTENER_H
