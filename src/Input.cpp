#include "Input.h"
#include <iostream>

namespace CubeStudio2D {

    Input::Input() {}

    Input::~Input() {}

    void Input::Update() {
        // Capturar eventos de teclado/mouse
        std::cout << "Input updated" << std::endl;
    }

    bool Input::IsKeyPressed(int keycode) {
        // Retornar estado da tecla
        return false;
    }

    bool Input::IsMouseButtonDown(int button) {
        return false;
    }

}