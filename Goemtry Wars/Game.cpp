#include "Game.h"

Game::Game(const std::string& config)
{
    init(config);
}
void Game::init(const std::string& path)
{
    std::ifstream fin(path);

    m_window.create(sf::VideoMode(1280, 720), "Geomtry War Clone");
    m_window.setFramerateLimit(60);

    spawnPlayer();
}
void Game::run()
{
    while (m_running)
    {
        m_entites.update();

        sEnemySpawner();
        sMovement();
        sCollision();
        sUserInput();
        sRender();
        
        m_currentFrame++;
    }
}
void Game::setPaused(bool paused)
{
    m_paused = paused;
}

void Game::spawnPlayer()
{
    auto entity = m_entites.addEntity("player");

    float mx = m_window.getSize().x / 2;
    float my = m_window.getSize().y / 2;

    entity->cTransform = std::make_shared<CTransform>(Vector2(mx, my), Vector2(1, 1));
    entity->cShape = std::make_shared<CShape>(32, 8, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4);
    entity->cInput = std::make_shared<CInput>();

    m_player = entity;
}

void Game::spawnEnemy()
{
    auto entity = m_entites.addEntity("enemy");

    float ex = rand()%m_window.getSize().x;
    float ey = rand()%m_window.getSize().y;

    entity->cTransform = std::make_shared<CTransform>(Vector2(ex, ey), Vector2(1, 1));
    entity->cShape = std::make_shared<CShape>(16, 3, sf::Color(10, 10, 10), sf::Color(255, 255, 255), 4);
    entity->cInput = std::make_shared<CInput>();

    m_player = entity;

    m_lastEnemySpawnTime = m_currentFrame;
}
void Game::sMovement()
{

}

void Game::sUserInput()
{


}

void Game::sLifespan()
{
}

void Game::sRender()
{
    m_window.clear();

   

    for (auto& e : m_entites.getEntities())
    {
        m_player->cShape->shape.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);
        m_player->cTransform->angle += 1;
        m_player->cShape->shape.setRotation(m_player->cTransform->angle);

        m_window.draw(m_player->cShape->shape);
    }

    m_window.display();
}

void Game::sEnemySpawner()
{
    spawnEnemy();
}

void Game::sCollision()
{
}





void Game::spawnSmallEnemies(std::shared_ptr<Entity> entity)
{
}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vector2& mousePos)
{
}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity)
{
}




