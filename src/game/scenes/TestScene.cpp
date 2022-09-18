#include "../../../include/incs.h"

TestScene::TestScene() {
    std::cout << "BUNKER CARLOS\n";
}

void TestScene::init() {

}

void TestScene::update(float deltaTime) {
    // display deltatime (frametime)
    std::cout << "[TestScene] FPS: " << 1/deltaTime << std::endl;
}