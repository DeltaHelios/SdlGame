#include "MainGame.h"
#include "iostream"
#include "string"
#include "SDL_opengl.h"
using namespace std;

void fatalError(const string& s) {
	cerr<< "FATAL ERROR " << s << endl;
	cerr << " Press any key to quit";
	char c;
	cin >> c;
	SDL_Quit();
}

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
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			float dx = (i-0.9f) * 0.75f;
			float dy = (j-0.9f) * 0.75f;

			sprites[i][j].init(dx-0.3f,dy-0.3f, 0.4, 0.4);
		}
	}

	gameLoop();
}

void MainGame::initSystems()
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_EVERYTHING);
	wnd = SDL_CreateWindow("Here Be Dragons",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight, SDL_WINDOW_OPENGL
	);
	if (!wnd) {
		fatalError("Cannot create SDL main window.");
	}
	SDL_GLContext ctxt = SDL_GL_CreateContext(wnd);
	if (!ctxt) {
		fatalError("Cannot create GL context.");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(1.0f, 0.75f, 0.0f, 0.5f);
}
void MainGame::gameLoop()
{
	while (state != GameState::EXIT) {
		processInput();
		draw();
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

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int c = 0; c < 3; c++) {
		for (int r = 0; r< 3; r++) {

			sprites[c][r].draw();
		}
	}
	glEnd();

	SDL_GL_SwapWindow(wnd);
}
