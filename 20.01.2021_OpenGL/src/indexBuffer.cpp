#include "indexBuffer.hpp"
#include "renderer.hpp"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
	: m_Count(count)
{

	ASSERT(sizeof(unsigned int) == sizeof(GLuint))

	GLCheckError(glGenBuffers(1, &m_RendererID));
	GLCheckError(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	GLCheckError(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
	GLCheckError(glDeleteBuffers(1, &m_RendererID));
} 



void IndexBuffer::bind() const {
	GLCheckError(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::unbind() const {
	GLCheckError(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}