#include "MainGame.h"
#include "iostream"
using namespace std;


MainGame::MainGame()
:wnd(nullptr)
,screenWidth(1024)
,screenHeight(768)
,state(GameState::PLAY)
{
}

void MainGame::run()
{
	initSystems();
	gameLoop();
}

void MainGame::initSystems()
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_EVERYTHING);
	wnd = SDL_CreateWindow("Here Be Dragons",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight, SDL_WINDOW_OPENGL);
}

void MainGame::gameLoop()
{
	while (state != GameState::EXIT) {
		processInput();
	}
}

void MainGame::processInput()
{
	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		switch (e.type) {
			case SDL_QUIT:
				state = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				cout << "M(" << e.motion.x << "," << e.motion.y << ")\n";
				break;

		}
	}
}
