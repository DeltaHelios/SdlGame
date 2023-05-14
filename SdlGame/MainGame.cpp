#include "MainGame.h"



MainGame::MainGame()
:wnd(nullptr)
,screenWidth(1024)
,screenHeight(768)
{
}

void MainGame::run()
{
	initSystems();
}

void MainGame::initSystems()
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_EVERYTHING);
	wnd = SDL_CreateWindow("Here Be Dragons",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight, SDL_WINDOW_OPENGL);
}
