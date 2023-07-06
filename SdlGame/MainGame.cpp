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
	glClearDepth(1.1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_COLOR_ARRAY);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex2f(0, 0);
	glVertex2f(-0, -1);
	glVertex2f(1,-1);

	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex2f(0, 0);
	glVertex2f(1, 1);
	glVertex2f(-0, 1);
	glEnd();

	SDL_GL_SwapWindow(wnd);
}
