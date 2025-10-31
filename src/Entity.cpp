#include "Entity.h"

namespace CubeStudio2D {

    Entity::Entity(const std::string& name)
        : m_name(name), m_position{0,0}, m_rotation(0), m_scaleX(1), m_scaleY(1) {}

    Entity::~Entity() {}

    const std::string& Entity::GetName() const { return m_name; }

    Entity::Vec2 Entity::GetPosition() const { return m_position; }

    void Entity::SetPosition(Vec2 pos) {
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

    void Entity::SetTexture(const std::string& texPath) {
        m_texture = texPath;
    }

}