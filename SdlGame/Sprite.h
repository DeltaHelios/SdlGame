#pragma once
#include <SDL_opengl.h>

class Sprite
{
public:
	Sprite();
	~Sprite();
	void init(float x, float y, float width, float height);
	void draw();
private:
	float x;
	float y;
	float width;
	float height;
	GLuint vboId;

};

