#ifndef CUBESTUDIO2D_H
#define CUBESTUDIO2D_H

#include <string>
#include <vector>
#include <memory>

namespace CubeStudio2D {

    // Forward declarations
    class Engine;
    class Scene;
    class Entity;

    using ScenePtr = std::unique_ptr<Scene>;

    // Engine lifecycle
    class Engine {
    public:
        // Inicializa a engine; retorna true se tudo ocorreu bem
        static bool Initialize();

        // Verifica se a engine está rodando
        static bool IsRunning();

        // Delta time entre frames (em segundos)
        static float DeltaTime();

        // Atualiza o estado da engine
        static void Update(float dt);

        // Renderiza a cena atual
        static void Render();

        // Libera recursos e encerra a engine
        static void Shutdown();

        // Configurações opcionais
        static void SetWindowTitle(const std::string& title);
        static void SetResolution(int width, int height);

        // Gerenciamento de cenas
        static void SetActiveScene(Scene* scene);
        static Scene* GetActiveScene();
    };

    // Cena básica
    class Scene {
    public:
        Scene(const std::string& name);
        virtual ~Scene();

        const std::string& GetName() const;

        // Ciclo de vida da cena
        virtual void OnInit();
        virtual void OnUpdate(float dt);
        virtual void OnRender();
        virtual void OnShutdown();

        // Gerenciamento simples de entidades
        void AddEntity(Entity* entity);
        void RemoveEntity(Entity* entity);
        const std::vector<Entity*>& GetEntities() const;

    protected:
        std::string m_name;
        std::vector<Entity*> m_entities;
    };

    // Entidade básica
    class Entity {
    public:
        Entity(const std::string& name);
        virtual ~Entity();

        const std::string& GetName() const;

        // Propriedades básicas de posição e transformação
        struct Vec2 { float x; float y; };

        Vec2 GetPosition() const;
        void SetPosition(const Vec2& pos);

        void Translate(float dx, float dy);
        void SetRotation(float angle); // graus
        void SetScale(float sx, float sy);

        // Propriedade de renderização - caminho para textura
        void SetTexture(const std::string& texturePath);

    protected:
        std::string m_name;
        Vec2 m_position;
        float m_rotation;
        float m_scaleX;
        float m_scaleY;
        std::string m_texture;
    };

} // namespace CubeStudio2D

#endif // CUBESTUDIO2D_H
