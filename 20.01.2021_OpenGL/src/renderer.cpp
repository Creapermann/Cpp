#include <iostream>

#include "Renderer.hpp"



void GLClearErrors() {
	while (glGetError() != GL_NO_ERROR);
}


bool GLLogCall(const char* function, const char* filepath, int line) {
	while (GLenum error = glGetError()) {        //While error is not false
		std::cout << "[OpenGL Error] (" << error << ")" << "  " << function <<
			"  " << filepath << ": " << line << std::endl;
		return false;
	}
	return true;
}




void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, Shader& shader) const {
	shader.bind();
	va.bind();
	ib.bind();

	GLCheckError(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}


void Renderer::clear() const {
	GLCheckError(glClear(GL_COLOR_BUFFER_BIT));
}