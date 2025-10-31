#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "Scene.h"

namespace CubeStudio2D {

    class Engine {
    public:
        static bool Initialize();
        static bool IsRunning();
        static float DeltaTime();
        static void Update(float dt);
        static void Render();
        static void Shutdown();
        static void SetWindowTitle(const std::string& title);
        static void SetResolution(int width, int height);
        static void SetActiveScene(Scene* scene);
        static Scene* GetActiveScene();
    };

}

#endif // ENGINE_H