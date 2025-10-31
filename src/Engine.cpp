#include "Engine.h"
#include <iostream>
#include <chrono>

namespace CubeStudio2D {

    namespace {
        bool isRunning = false;
        float deltaTime = 0.0f;
        std::string windowTitle = "Cube Studio 2D";
        int windowWidth = 800;
        int windowHeight = 600;
        Scene* activeScene = nullptr;
        std::chrono::steady_clock::time_point lastFrameTime;
    }

    bool Engine::Initialize() {
        std::cout << "Initializing Cube Studio 2D Engine..." << std::endl;
        isRunning = true;
        lastFrameTime = std::chrono::steady_clock::now();

        if (activeScene)
            activeScene->OnInit();

        return true;
    }

    bool Engine::IsRunning() {
        return isRunning;
    }

    float Engine::DeltaTime() {
        return deltaTime;
    }

    void Engine::Update(float dt) {
        if (activeScene) activeScene->OnUpdate(dt);
    }

    void Engine::Render() {
        if (activeScene) activeScene->OnRender();
    }

    void Engine::Shutdown() {
        std::cout << "Shutting down Cube Studio 2D Engine..." << std::endl;
        if (activeScene) {
            activeScene->OnShutdown();
            delete activeScene;
            activeScene = nullptr;
        }
        isRunning = false;
    }

    void Engine::SetWindowTitle(const std::string& title) {
        windowTitle = title;
    }

    void Engine::SetResolution(int width, int height) {
        windowWidth = width;
        windowHeight = height;
    }

    void Engine::SetActiveScene(Scene* scene) {
        if (activeScene) {
            activeScene->OnShutdown();
            delete activeScene;