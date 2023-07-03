#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
enum class GameState {
	PLAY, EXIT
};
class MainGame
{
public:
	MainGame();
	void run();
private:
	void initSystems();
	void gameLoop();
	void processInput();
	SDL_Window *wnd;
	int screenWidth;
	int screenHeight;
	GameState state;
};

