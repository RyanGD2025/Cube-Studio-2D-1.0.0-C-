#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include "Entity.h"

namespace CubeStudio2D {

    class Scene {
    public:
        Scene(const std::string& name);
        virtual ~Scene();

        const std::string& GetName() const;

        virtual void OnInit();
        virtual void OnUpdate(float dt);
        virtual void OnRender();
        virtual void OnShutdown();

        void AddEntity(Entity* entity);
        void RemoveEntity(Entity* entity);
        const std::vector<Entity*>& GetEntities() const;

    protected:
        std::string m_name;
        std::vector<Entity*> m_entities;
    };

}

#endif // SCENE_H