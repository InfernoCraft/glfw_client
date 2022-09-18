#include "../../../include/incs.h"

static Window* window;



Window::Window() {
    // declaration of standard values
    width = 1920;
    height = 1280;
    title = "game";
    r = 0;
    g = 0;
    b = 0;
    a = 1;
}

Window* Window::getWindow() {
    if (not window) {
        window = new Window();
    }
    return window;
}

Scene* Window::getScene() {
    return currentScene;
}

void Window::changeScene(Scene* newScene) {
    currentScene = newScene;
}

void Window::run() {
    // functions that are mandatory to be called
    init();
    loop();

    //destroy window and free memory
    glfwDestroyWindow(glfwWindow);
    // quit glfw
    glfwTerminate();
}

void Window::errorHandling(const char* desc) {
    // every error code (above 1, as 0 is not an error code) will be treated as an error -> exit program
    if(glfwGetError((const char**)desc) >= 1) {
        glfwDestroyWindow(glfwWindow);
        glfwTerminate();
        exit(-1);
    }
}

void Window::init() {
    // init library
    if (!glfwInit()) errorHandling("Could not initialize glfw library: ");

    // create window
    glfwWindow = glfwCreateWindow(Window::width, Window::height, Window::title, NULL, NULL);

    //self-explanatory
    if (!Window::glfwWindow) {
        errorHandling("could not create window: ");
    }

    // set listener with callback functions
    // keyboard pressing
    glfwSetKeyCallback(glfwWindow, KeyListener::keyCallback);
    // mouse button pressing
    glfwSetMouseButtonCallback(glfwWindow, MouseListener::mouseButtonCallback);
    // mouse scrolling
    glfwSetScrollCallback(glfwWindow, MouseListener::mouseScrollCallback);
    // mouse movement
    glfwSetCursorPosCallback(glfwWindow, MouseListener::mousePosCallback);

    //OpenGl context current
    glfwMakeContextCurrent(glfwWindow);

    //Enable v-sync
    glfwSwapInterval(1);

    //enables that gl blends textures right if they have an alpha channel
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

    changeScene(new TestScene());
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
        glClearColor(r, g, b, Window::a);
        glClear(GL_COLOR_BUFFER_BIT);

        // SCENES
        if (deltaTime >= 0) {
            currentScene->update(deltaTime);
        }

        // switch front buffer with back buffer
        glfwSwapBuffers(glfwWindow);

        // dt calculations
        // get passed time, subtract it to get the current frame time, then start with endTime (most updated time)
        // keep in mind, 1 frame will be lost for calculation
        endTime = (float)glfwGetTime();
        deltaTime = endTime - beginTime;
        beginTime = endTime;
    }
}