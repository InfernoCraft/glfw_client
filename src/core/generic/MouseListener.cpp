#include "../../../include/incs.h"

const int mouseButtonLength = 3;

static double scrollX = 0.0;
static double scrollY = 0.0;
static double xPos = 0.0;
static double yPos = 0.0;
static double lastX = 0.0;
static double lastY = 0.0;
static bool mouseButtonPressed[mouseButtonLength];
static bool dragging = false;

void MouseListener::mousePosCallback(GLFWwindow *glfwWindow, double xpos, double ypos) {
    lastX = xPos;
    lastY = yPos;
    xPos = xpos;
    yPos = ypos;
    dragging = mouseButtonPressed[0] || mouseButtonPressed[1] || mouseButtonPressed[2];
}

void MouseListener::mouseButtonCallback(GLFWwindow *glfwWindow, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        if (button < mouseButtonLength) {
            mouseButtonPressed[button] = true;
        }
    } else if (action == GLFW_RELEASE) {
        if (button < mouseButtonLength) {
            mouseButtonPressed[button] = false;
        }
    }
}

void MouseListener::mouseScrollCallback(GLFWwindow *glfwWindow, double xOffset, double yOffset) {
    scrollX = xOffset;
    scrollY = yOffset;
}

double MouseListener::getX() {
    return xPos;
}

double MouseListener::getY() {
    return yPos;
}

double MouseListener::getDx() {
    return lastX - xPos;
}

double MouseListener::getDy() {
    return lastY - yPos;
}

double MouseListener::getScrollX() {
    return scrollX;
}

double MouseListener::getScrollY() {
    return scrollY;
}

bool MouseListener::isDragging() {
    return dragging;
}

bool MouseListener::mouseButtonDown(int button) {
    if (button < mouseButtonLength) {
        return mouseButtonPressed[button];
    }
    return false;
}