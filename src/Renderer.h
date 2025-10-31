#ifndef RENDERER_H
#define RENDERER_H

#include <string>

namespace CubeStudio2D {

    class Renderer {
    public:
        Renderer();
        ~Renderer();

        bool Initialize(int width, int height, const std::string& title);
        void ClearScreen();
        void DrawTexture(const std::string& texturePath, float x, float y, float scaleX, float scaleY, float rotation);
        void Present();
        void Shutdown();
    };

}

#endif // RENDERER_H