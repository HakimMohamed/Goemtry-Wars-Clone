#include<iostream>
#include"Game.h"

int main(int argc,char* argv[])
{
	Game g("ConfigFile/Config.txt");
	g.run();

    return 0;

}
