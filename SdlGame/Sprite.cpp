#include "Sprite.h"
#include <SDL_opengl_glext.h>

Sprite::Sprite():vboId(0)
{
	
}

Sprite::~Sprite()
{
	if (vboId) {
		glDeleteBuffers(1, &vboId);
	}
}

void Sprite::init(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	if (vboId == 0) {
		glGenBuffers(1, &vboId);
	}
	/*
		B----A
		|    |
		C----D
		*/

	float vertexData[3 * 3 * 2] = {
		/*A*/x, y + (height * 0.5f), /*B*/ x + (width * 0.4f), y + height,/*C*/ x + width, y + (height * 0.8f), //
		/*C*/ x, y + (height * 0.5f), /*A*/x + (width * 0.4f), y    , /*D*/ x + width , y + (height * 0.2f), //
	   x + (width * 0.827f), y + (height * 0.748), /*Point*/ x + (width * 0.936),y + (height * 0.781), /*Points*/ x + (width * 0.926),y+(height*0.656)
	};

	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0 , nullptr);
	glDrawArrays(GL_TRIANGLES, 0, 9);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
