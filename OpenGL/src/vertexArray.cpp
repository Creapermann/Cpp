#include "vertexArray.hpp"
#include "vertexBufferLayout.hpp"
#include "renderer.hpp"



VertexArray::VertexArray() {

	GLCheckError(glGenVertexArrays(1, &m_RendererID));
	GLCheckError(glBindVertexArray(m_RendererID));
}
VertexArray:: ~VertexArray() {
	GLCheckError(glDeleteVertexArrays(1, &m_RendererID));
}


void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {

	bind();
	vb.bind();

	const auto& elements = layout.getElements();

	unsigned int offset = 0;

	for (int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];

		GLCheckError(glEnableVertexAttribArray(i));
		GLCheckError(glVertexAttribPointer(i, element.count, element.type,
			element.normalized, layout.getStride(),(const void*) offset));
		offset += element.count * VertexBufferElement::getSizeOfType(element.type);
	}

	
}

void VertexArray::bind() const {

}

void VertexArray::unbind() const {

}
