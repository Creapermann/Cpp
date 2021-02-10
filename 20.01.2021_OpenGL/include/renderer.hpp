#pragma once

#include <GL/glew.h>

#include "vertexArray.hpp"
#include "indexBuffer.hpp"
#include "shader.hpp"

//Error handling
#define ASSERT(x) if (!(x)) __debugbreak();   //Takes a bool
//Backslashes are used to go with one #define into more lines, sepperate commands with ';'
#define GLCheckError(x) GLClearErrors();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__));


void GLClearErrors();
bool GLLogCall(const char* function, const char* filepath, int line);



class Renderer
{
public:
	Renderer() {};
	void draw(const VertexArray& va, const IndexBuffer& ib, Shader& shader) const;
	void clear() const;
private:

};