#include<iostream>
#include"../Vector2.h"
#include<SFML/Graphics.hpp>
#include"../log.h"
#include"../Entity.h"
#include<vector>

void sRender(std::vector<Entity>& entitiesVec, sf::RenderWindow &window)
{
    for(auto & e:entitiesVec)
        if (e.cShape && e.cTransform)
        {
            e.cShape->shape.setPosition(e.cTransform->pos.x, e.cTransform->pos.y);
            window.draw(e.cShape->shape);
        }
}

int main(int argc,char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "window");
    window.setFramerateLimit(60);    

    //Create Entity
    
    std::vector<Entity> entitiesVec;
    Vector2 p(400, 400), v(10, 19);

    Entity e;
    e.cTransform = std::make_shared<CTransform>(p, v);
    e.cShape     = std::make_shared<CShape>(50,sf::Color::Red);
    e.cName     = std::make_shared<CName>("Box");

    entitiesVec.push_back(e);


    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {
            

            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) 
            {

            }  

        }

        window.clear();

        sRender(entitiesVec, window);
        //draw
        window.display();
       
    }


    return 0;

}
