#ifndef GLFW_CLIENT_GAMELOADINGSCENE_H
#define GLFW_CLIENT_GAMELOADINGSCENE_H
#include "../incs.h"

class GameLoadingScene : public Scene {
private:


public:
    GameLoadingScene();
    void init();
    void update(float deltaTime);
};


#endif
