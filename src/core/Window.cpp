#include "../../include/incs.h"

Window::Window() {
    // declaration of standard values
    Window::width = 1920;
    Window::height = 1280;
    Window::title = "game";
    Window::r = 0;
    Window::g = 0;
    Window::b = 0;
    Window::a = 1;
}

void Window::run() {
    // functions that are mandatory to be called
    Window::init();
    Window::loop();

    //destroy window and free memory
    glfwDestroyWindow(Window::glfwWindow);
    // quit glfw
    glfwTerminate();
}

void Window::errorHandling(const char* desc) {
    // every error code (above 1, as 0 is not an error code) will be treated as an error -> exit program
    if(glfwGetError((const char**)desc) >= 1) {
        glfwDestroyWindow(Window::glfwWindow);
        glfwTerminate();
        exit(-1);
    }
}

void Window::init() {
    // init library
    if (!glfwInit()) errorHandling("Could not initialize glfw library: ");

    // create window
    Window::glfwWindow = glfwCreateWindow(Window::width, Window::height, Window::title, NULL, NULL);

    //self-explanatory
    if (!Window::glfwWindow) {
        errorHandling("could not create window: ");
    }

    // set listener with callback functions
    // keyboard pressing
    glfwSetKeyCallback(Window::glfwWindow, KeyListener::keyCallback);
    // mouse button pressing
    glfwSetMouseButtonCallback(Window::glfwWindow, MouseListener::mouseButtonCallback);
    // mouse scrolling
    glfwSetScrollCallback(Window::glfwWindow, MouseListener::mouseScrollCallback);
    // mouse movement
    glfwSetCursorPosCallback(Window::glfwWindow, MouseListener::mousePosCallback);

    //OpenGl context current
    glfwMakeContextCurrent(Window::glfwWindow);

    //Enable v-sync
    glfwSwapInterval(1);
}

void Window::loop() {
    // start of the calculations
    float beginTime = (float)glfwGetTime();
    float endTime;
    float deltaTime = -1.0f;

    while(!glfwWindowShouldClose(Window::glfwWindow)) {
        //Poll events
        glfwPollEvents();

        //clear color buffer
        glClearColor(Window::r, Window::g, Window::b, Window::a);
        glClear(GL_COLOR_BUFFER_BIT);

        // TODO: implement scenes

        // display deltatime (frametime)
        std::cout << "FPS: " << 1/deltaTime << std::endl;

        // keyboard input
        if(KeyListener::isKeyPressed(GLFW_KEY_SPACE)) {
            // do some shit here
        }
        //mouse input
        if (MouseListener::mouseButtonDown(GLFW_MOUSE_BUTTON_1)) {
            // do shit here
        }

        // switch front buffer with back buffer
        glfwSwapBuffers(Window::glfwWindow);

        // dt calculations
        // get passed time, subtract it to get the current frame time, then start with endTime (most updated time)
        // keep in mind, 1 frame will be lost for calculation
        endTime = (float)glfwGetTime();
        deltaTime = endTime - beginTime;
        beginTime = endTime;
    }
}