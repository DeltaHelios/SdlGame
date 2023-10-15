#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "Sprite.h"

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
	void draw();
	SDL_Window *wnd;
	int screenWidth;
	int screenHeight;
	GameState state;
	Sprite sprites[10][10];
};

