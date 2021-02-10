#include "texture.h"

#include "std_image/stb_image.h"

Texture::Texture(const std::string& path) 
	: m_RendererID(0), m_FilePath(path), m_LocalBuffer(nullptr),
	m_Height(0), m_Width(0), m_BPP(0)
{
		//Load image
		stbi_set_flip_vertically_on_load(1);
		m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

		GLCheckError(glGenTextures(1, &m_RendererID));
		GLCheckError(glBindTexture(GL_TEXTURE_2D, m_RendererID));

		GLCheckError(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCheckError(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCheckError(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCheckError(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		GLCheckError(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, m_LocalBuffer));

		GLCheckError(glBindTexture(GL_TEXTURE_2D, 0));

		if (m_LocalBuffer)
			stbi_image_free(m_LocalBuffer);
};
Texture::~Texture() {
	glDeleteTextures(1, &m_RendererID);
};

void Texture::bind(unsigned int slot) const {
	GLCheckError(glActiveTexture(GL_TEXTURE0 + slot));
	GLCheckError(glBindTexture(GL_TEXTURE_2D, m_RendererID));
}

void Texture::unbind() const {
	GLCheckError(glBindTexture(GL_TEXTURE_2D, 0));
}