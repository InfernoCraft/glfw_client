#include "../../../include/incs.h"

Scene::Scene() {

}

void Scene::init() {

}

void Scene::start() {
    isRunning = true;
}

void Scene::update(float deltaTime) {
    std::cout << "[Scene] FPS: " << 1/deltaTime << std::endl;
}