#ifndef INPUT_H
#define INPUT_H

namespace CubeStudio2D {

    class Input {
    public:
        Input();
        ~Input();

        void Update();

        bool IsKeyPressed(int keycode);
        bool IsMouseButtonDown(int button);

        // Outras funções de input conforme necessário
    };

}

#endif // INPUT_H