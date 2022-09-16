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

    glfwSetKeyCallback(Window::glfwWindow, this->keyCallback);

    //OpenGl context current
    glfwMakeContextCurrent(Window::glfwWindow);

    //Enable v-sync
    glfwSwapInterval(GLFW_TRUE);

}

void Window::loop() {
    while(!glfwWindowShouldClose(Window::glfwWindow)) {
        //Poll events
        glfwPollEvents();

        //clear color buffer
        glClearColor(Window::r, Window::g, Window::b, Window::a);
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(Window::glfwWindow);
    }
}

void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    std::cout << key;
}
