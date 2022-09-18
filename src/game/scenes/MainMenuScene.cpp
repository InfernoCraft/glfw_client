#include "../../../include/incs.h"

MainMenuScene::MainMenuScene() {
    std::cout << "BUNKER CARLOS\n";
}

void MainMenuScene::init() {

}

void MainMenuScene::update(float deltaTime) {
    // display deltatime (frametime)
    std::cout << "[MainMenuScene] FPS: " << 1/deltaTime << std::endl;
    Window::getWindow()->r = 1;
    Window::getWindow()->g = 1;
    Window::getWindow()->b = 1;
}