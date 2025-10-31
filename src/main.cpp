// main.cpp
#include <cstdlib>      // std::exit
#include <cstdint>      // fixed-width integers (se necessário)
#include <memory>       // std::unique_ptr
#include <string>       // std::string

// Inclua os headers da sua Cube Studio 2D (ajuste os nomes conforme a API)
#include "CubeStudio2D.h"  // substitua pelo cabeçalho real da sua engine
// #include "Engine.h"
// #include "Scene.h"

int main(int argc, char** argv) {
    // 1) Inicialização da engine
    if (!CubeStudio2D::Initialize()) {
        // Em caso de falha, encerra com código de erro
        return EXIT_FAILURE;
    }

    // 1.1) Configurações opcionais de ambiente (titulos, resolução, etc.)
    // CubeStudio2D::SetWindowTitle("Cube Studio 2D Engine");
    // CubeStudio2D::SetResolution(800, 600);

    // 2) Preparação da cena inicial (se houver API de Scene)
    // std::unique_ptr<Scene> mainScene = std::make_unique<Scene>("Main");
    // CubeStudio2D::SetActiveScene(mainScene.get());

    // 3) Loop principal
    while (CubeStudio2D::IsRunning()) {
        // cálculo de delta time
        float dt = CubeStudio2D::DeltaTime();

        // atualização de estado
        CubeStudio2D::Update(dt);

        // renderização
        CubeStudio2D::Render();

        // handling de eventos internos, se aplicável
        CubeStudio2D::PollEvents();
    }

    // 4) Finalização e limpeza
    CubeStudio2D::Shutdown();

    return EXIT_SUCCESS;
}
