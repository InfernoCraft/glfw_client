#ifndef GLFW_CLIENT_TESTSCENE_H
#define GLFW_CLIENT_TESTSCENE_H
#include "../incs.h"

class TestScene : public Scene{
private:


public:
    TestScene();
    void init();
    void update(float deltaTime);
};


#endif
