#ifndef GLFW_CLIENT_WINDOW_H
#define GLFW_CLIENT_WINDOW_H
#include "../incs.h"

class Window {
private:
    const char* title;
    int width, height;

    Scene* currentScene;

    // define standard values
    Window();

    void init();
    void loop();

public:
    GLFWwindow* glfwWindow;
    float r, g, b, a;

    static Window* getWindow();

    // initializations and native loop
    void run();

    void changeScene(Scene* newScene);
    Scene* getScene();

    // void function collapses on error
    void errorHandling(const char* desc);
};

#endif
