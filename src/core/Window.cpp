#include "../../include/incs.h"

Window::Window() {
    Window::width = 1920;
    Window::height = 1280;
    Window::title = "game";
    Window::r = 0;
    Window::g = 0;
    Window::b = 0;
    Window::a = 1;
}

void Window::run() {
    Window::init();
    Window::loop();

    //destroy window and free memory
    //glfwDestroyWindow(Window::glfwWindow);
}

void Window::init() {
    if (!glfwInit()) return;

    Window::glfwWindow = glfwCreateWindow(Window::width, Window::height, Window::title, NULL, NULL);

    if (!Window::glfwWindow) {
        glfwTerminate();
        return;
    }

    //KeyListener::keyListener = KeyListener();
    glfwSetKeyCallback(Window::glfwWindow, KeyListener::keyCallback);
    glfwSetMouseButtonCallback(Window::glfwWindow, MouseListener::mouseButtonCallback);
    glfwSetScrollCallback(Window::glfwWindow, MouseListener::mouseScrollCallback);
    glfwSetCursorPosCallback(Window::glfwWindow, MouseListener::mousePosCallback);

    //OpenGl context current
    glfwMakeContextCurrent(Window::glfwWindow);

    //Enable v-sync
    glfwSwapInterval(1);
}

void Window::loop() {
    float beginTime = (float)glfwGetTime();
    float endTime;
    float deltaTime = -1.0f;

    while(!glfwWindowShouldClose(Window::glfwWindow)) {
        //Poll events
        glfwPollEvents();

        //clear color buffer
        glClearColor(Window::r, Window::g, Window::b, Window::a);
        glClear(GL_COLOR_BUFFER_BIT);

        //std::cout << 1/deltaTime << std::endl;

        if (MouseListener::mouseButtonDown(GLFW_MOUSE_BUTTON_1)) {
            std::cout<<"test" << std::endl;
        }

        glfwSwapBuffers(Window::glfwWindow);

        endTime = (float)glfwGetTime();
        deltaTime = endTime - beginTime;
        beginTime = endTime;
    }
}