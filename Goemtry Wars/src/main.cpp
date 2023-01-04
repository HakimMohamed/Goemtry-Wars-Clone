#include<iostream>
#include"../Game.h"

int main(int argc,char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "window");
    window.setFramerateLimit(60);    
  
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

        //draw
        window.display();
       
    }


    return 0;

}
