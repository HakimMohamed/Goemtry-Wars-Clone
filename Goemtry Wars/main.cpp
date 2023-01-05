#include<iostream>
#include"Game.h"
#include<SFML/Graphics.hpp>

int main(int argc,char* argv[])
{
	Game g("ConfigFile/Config.txt");
	g.run();

    return 0;

}
