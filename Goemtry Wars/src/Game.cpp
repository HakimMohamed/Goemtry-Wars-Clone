#include "Game.h"

Game::Game(const std::string& config)
{
	init(config);
}



void Game::init(const std::string& config)
{
	// to do read config file here 
	// use premade player config ,enemy config ,bullet variabes
	//std::fstream fin(path);

	_window.create(sf::VideoMode(1280, 720), "Geomtry wars");
	_window.setFramerateLimit(60);

	spawnPlayer();
}

void Game::setPaused(bool paused)
{
	_paused = paused;
}

void Game::run()
{
	// to do pause functionality 
	// some systems should function while paused
	// some shouldn't (movement/input

	while (_running)
	{
		_entities.update();
		

		//if (!_paused)
		//{
		//	

		//}
		sEnemySpawner();
		sMovement();
		sCollision();
		sUserInput();
		sRender();


		//increment the current frame 
		// may need to be moved when pause implemented

		_currentFrame++;
	}
}



void Game::spawnPlayer()
{
	// to do finish adding all properties to the player with the correct values from the config
	//create every entity by calling entitymanager.addentity(tag)
	
	//this returns a std::shared_ptr<Entity>, so we type auto to save typing
	auto entity = _entities.addEntity("player");

	float mx = _window.getSize().x/2;
	float my = _window.getSize().y / 2;

	//Give this entity a Transform so it spawns 
	entity->cTransform = std::make_shared<CTransform>(Vector2(mx, my), Vector2(1.0f, 1.0f), 0.0f);

	entity->cShape = std::make_shared<CShape>(32.0f, 8, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4.0f);

	entity->cInput = std::make_shared<CInput>();

	_player = entity;

}

void Game::spawnEnemy()
{

	//to do make sure the enemy is spawned porperly with the correct config enemy config
	// make sure he will spawn in the bound of the screen
	auto entity = _entities.addEntity("enemy");

	float ex = rand()%_window.getSize().x;
	float ey = rand()%_window.getSize().y;



	//Give this entity a Transform so it spawns 
	entity->cTransform = std::make_shared<CTransform>(Vector2(ex, ey), Vector2(1.0f, 1.0f), 0.0f);

	entity->cShape = std::make_shared<CShape>(16.0f, 3, sf::Color(0, 0, 0), sf::Color(255, 0, 0), 4.0f);

	entity->cInput = std::make_shared<CInput>();

	_player = entity;


	_lastEnemySpawnTime = _currentFrame;
}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vector2& target)
{


	auto bullet = _entities.addEntity("bullet");

	bullet->cTransform = std::make_shared<CTransform>(target,Vector2(0,0),0);
	bullet->cShape     = std::make_shared<CShape>(10, 8, sf::Color(255, 255, 255), sf::Color(255, 0, 0), 2);
}




void Game::sMovement()
{
	_player->cTransform->velocity = {0,0};

	if (_player->cInput->up)
	{
		_player->cTransform->velocity.y = -5;
	}

	_player->cTransform->pos.x += _player->cTransform->velocity.x;
	_player->cTransform->pos.y += _player->cTransform->velocity.y;

}

void Game::sUserInput()
{


	sf::Event event;

	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_running = false;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				std::cout << "w key pressed";
				_player->cInput->up = true;
				//set player input component to true
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
				std::cout << "w key Released";
				_player->cInput->up = false;
				//set player input component to true
				break;
			default:
				break;

			}
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "left mouse" << event.mouseButton.x << " , " << event.mouseButton.y << "\n";
				spawnBullet(_player, Vector2(event.mouseButton.x, event.mouseButton.y));
			}

			if (event.mouseButton.button == sf::Mouse::Right)
			{
				std::cout << "left mouse" << event.mouseButton.x << " , " << event.mouseButton.y << "\n";
				spawnBullet(_player, Vector2(event.mouseButton.x, event.mouseButton.y));
			}
		}

	}
}

void Game::sLifeSpan()
{
}

void Game::sRender()
{
	_window.clear();

	for (auto &e : _entities.getEntities())
	{
		e->cShape->circle.setPosition(e->cTransform->pos.x,e->cTransform->pos.y);
		e->cTransform->angle+=1.0f;
		e->cShape->circle.setRotation(e->cTransform->angle);

		_window.draw(e->cShape->circle);
	}


}

void Game::sEnemySpawner()
{
	spawnEnemy();
}

void Game::sCollision()
{

	for (auto& b : _entities.getEntities("bullet"))
	{
		for (auto& e : _entities.getEntities("enemy"))
		{
			// use the math in the previous lecture

		}
	}
}
