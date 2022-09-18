#include "../../../include/game/GameLoadingScene.h"

GameLoadingScene::GameLoadingScene() {

}

void GameLoadingScene::init() {

}

void GameLoadingScene::update(float deltaTime) {
    // display deltatime (frametime)
    std::cout << "[GameLoadingScene] FPS: " << 1/deltaTime << std::endl;
    if (KeyListener::isKeyPressed(GLFW_KEY_SPACE)) {
        Window::getWindow()->changeScene(new MainMenuScene());
    }
}