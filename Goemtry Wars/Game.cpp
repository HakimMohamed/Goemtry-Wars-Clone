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

    std::cout << "init"<<"\n";
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

    entity->cTransform = std::make_shared<CTransform>(Vector2(mx, my), Vector2(4,4));
    entity->cShape = std::make_shared<CShape>(32, 8, sf::Color(10, 10, 10), sf::Color::Red, 4);
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

    

    m_lastEnemySpawnTime = m_currentFrame;
}

void Game::sEnemySpawner()
{
    spawnEnemy();
}

void Game::sMovement()
{
    m_player->cTransform->vel = { 0,0 };
       
    auto playerInput = m_player->cInput;
    float playerSpeed = 5;

    if (playerInput->up)
    {
        m_player->cTransform->vel.y = -playerSpeed;
    }

     if (playerInput->down)
    {
        m_player->cTransform->vel.y = playerSpeed;
    }

    if (playerInput->left)
    {
        m_player->cTransform->vel.x = -playerSpeed;
    }

    if (playerInput->right)
    {
        m_player->cTransform->vel.x = playerSpeed;
    }



    for (auto& e : m_entites.getEntities())
    {
        e->cTransform->pos.x += e->cTransform->vel.x;
        e->cTransform->pos.y += e->cTransform->vel.y;
    }
    
}

void Game::sUserInput()
{

    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_running = false;
        }

        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::W:
                std::cout << "W key pressed\n";
                m_player->cInput->up = true;
                break;

            case sf::Keyboard::S:
                std::cout << "S key pressed\n";
                m_player->cInput->down = true;
                break;

            case sf::Keyboard::A:
                std::cout << "A key pressed\n";
                m_player->cInput->left = true;
                break;

            case sf::Keyboard::D:
                std::cout << "D key pressed\n";
                m_player->cInput->right = true;
                break;
            default: 
                break;
            }
        }

        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::W:
                std::cout << "W key released\n";
                m_player->cInput->up = false;
                break;

            case sf::Keyboard::S:
                std::cout << "S key released\n";
                m_player->cInput->down = false;
                break;

            case sf::Keyboard::A:
                std::cout << "A key released\n";
                m_player->cInput->left = false;
                break;

            case sf::Keyboard::D:
                std::cout << "D key released\n";
                m_player->cInput->right = false;
                break;

            default:
                break;
            }
        }

    }
}

void Game::sLifespan()
{
}

void Game::sRender()
{
    m_window.clear();
 
    for (auto& e : m_entites.getEntities())
    {
        e->cShape->shape.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);
        e->cTransform->angle += 1.0f;
        e->cShape->shape.setRotation(e->cTransform->angle);

        m_window.draw(e->cShape->shape);

    }

    m_window.display();
}



void Game::sCollision()
{
}





void Game::spawnSmallEnemies(std::shared_ptr<Entity> entity)
{
    auto bullet = m_entites.addEntity("bullet");

}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vector2& mousePos)
{
}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity)
{
}




