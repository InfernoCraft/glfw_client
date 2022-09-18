#ifndef GLFW_CLIENT_SCENE_H
#define GLFW_CLIENT_SCENE_H
#include "../incs.h"

class Scene {
protected:


private:
    bool isRunning = false;

public:
    Scene();
    void init();
    void start();
    virtual void update(float deltaTime);
};


#endif