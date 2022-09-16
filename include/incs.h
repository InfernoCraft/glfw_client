//
// Created by pasca on 15.09.2022.
//
#ifndef GLFW_CLIENT_MAIN_H
#define GLFW_CLIENT_MAIN_H
#include "../GLFW/include/glfw3.h"

class main {

};

class Window {
private:
    Window();

public:
    static Window* get();
    void run();
};


#endif //GLFW_CLIENT_MAIN_H
