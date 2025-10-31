#ifndef ENTITY_H
#define ENTITY_H

#include <string>

namespace CubeStudio2D {

    class Entity {
    public:
        struct Vec2 { float x; float y; };

        Entity(const std::string& name);
        virtual ~Entity();

        const std::string& GetName() const;

        Vec2 GetPosition() const;
        void SetPosition(Vec2 pos);

        void Translate(float dx, float dy);
        void SetRotation(float angle);
        void SetScale(float sx, float sy);

        void SetTexture(const std::string& texPath);

    protected:
        std::string m_name;
        Vec2 m_position;
        float m_rotation;
        float m_scaleX;
        float m_scaleY;
        std::string m_texture;
    };

}

#endif // ENTITY_H