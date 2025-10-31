// core.cpp
#include "CubeStudio2D.h"
#include <iostream>
#include <chrono>
#include <thread>

namespace CubeStudio2D {

    // Dados internos para controle da engine
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
        // Inicialize janela, gráficos, input, etc.
        std::cout << "Initializing Cube Studio 2D Engine..." << std::endl;

        isRunning = true;
        lastFrameTime = std::chrono::steady_clock::now();

        // Inicialização da cena ativa (se necessária)
        if(activeScene) {
            activeScene->OnInit();
        }

        return true; // Suponha sempre sucesso para este exemplo
    }

    bool Engine::IsRunning() {
        return isRunning;
    }

    float Engine::DeltaTime() {
        return deltaTime;
    }

    void Engine::Update(float dt) {
        // Atualize lógica da engine e cena
        if (activeScene) {
            activeScene->OnUpdate(dt);
        }
    }

    void Engine::Render() {
        // Renderize cena atual
        if (activeScene) {
            activeScene->OnRender();
        }
    }

    void Engine::Shutdown() {
        // Limpar recursos
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
        // Implemente alteração de título de janela se necessário
    }

    void Engine::SetResolution(int width, int height) {
        windowWidth = width;
        windowHeight = height;
        // Implemente redimensionamento de janela se necessário
    }

    void Engine::SetActiveScene(Scene* scene) {
        if (activeScene) {
            activeScene->OnShutdown();
            delete activeScene;
        }
        activeScene = scene;
        if (activeScene) {
            activeScene->OnInit();
        }
    }

    Scene* Engine::GetActiveScene() {
        return activeScene;
    }


    // Implementação da classe Scene

    Scene::Scene(const std::string& name)
        : m_name(name) { }

    Scene::~Scene() { 
        for (Entity* entity : m_entities) {
            delete entity;
        }
        m_entities.clear();
    }

    const std::string& Scene::GetName() const {
        return m_name;
    }

    void Scene::OnInit() {
        // Código para inicialização da cena
    }

    void Scene::OnUpdate(float dt) {
        // Atualiza cada entidade
        for (Entity* entity : m_entities) {
            // implementações futuras
        }
    }

    void Scene::OnRender() {
        // Renderização das entidades da cena
        for (Entity* entity : m_entities) {
            // implementações futuras
        }
    }

    void Scene::OnShutdown() {
        // Limpeza da cena
    }

    void Scene::AddEntity(Entity* entity) {
        m_entities.push_back(entity);
    }

    void Scene::RemoveEntity(Entity* entity) {
        auto it = std::find(m_entities.begin(), m_entities.end(), entity);
        if (it != m_entities.end()) {
            m_entities.erase(it);
            delete entity;
        }
    }

    const std::vector<Entity*>& Scene::GetEntities() const {
        return m_entities;
    }


    // Implementação da classe Entity

    Entity::Entity(const std::string& name)
        : m_name(name), m_position{0, 0}, m_rotation(0.0f),
          m_scaleX(1.0f), m_scaleY(1.0f), m_texture("") { }

    Entity::~Entity() { }

    const std::string& Entity::GetName() const {
        return m_name;
    }

    Entity::Vec2 Entity::GetPosition() const {
        return m_position;
    }

    void Entity::SetPosition(const Vec2& pos) {
        m_position = pos;
    }

    void Entity::Translate(float dx, float dy) {
        m_position.x += dx;
        m_position.y += dy;
    }

    void Entity::SetRotation(float angle) {
        m_rotation = angle;
    }

    void Entity::SetScale(float sx, float sy) {
        m_scaleX = sx;
        m_scaleY = sy;
    }

    void Entity::SetTexture(const std::string& texturePath) {
        m_texture = texturePath;
        // Aqui carregue a textura conforme a sua engine
    }

} // namespace CubeStudio2D
