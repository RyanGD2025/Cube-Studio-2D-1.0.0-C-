#include "Scene.h"
#include <algorithm>

namespace CubeStudio2D {

    Scene::Scene(const std::string& name)
        : m_name(name) {}

    Scene::~Scene() {
        for (Entity* entity : m_entities) delete entity;
        m_entities.clear();
    }

    const std::string& Scene::GetName() const { return m_name; }

    void Scene::OnInit() {
        // Inicialização da cena
    }

    void Scene::OnUpdate(float dt) {
        for (Entity* entity : m_entities) {
            // Atualização de entidades
        }
    }

    void Scene::OnRender() {
        for (Entity* entity : m_entities) {
            // Renderização de entidades
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
            delete *it;
            m_entities.erase(it);
        }
    }

    const std::vector<Entity*>& Scene::GetEntities() const {
        return m_entities;
    }

}