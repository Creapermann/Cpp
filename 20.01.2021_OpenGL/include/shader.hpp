#pragma once

#include <string>
#include <unordered_map>

#include "glm/glm.hpp"

struct shaderProgramSoruce {
	std::string vertexSource;
	std::string fragmentSource;
};

class Shader
{
public:
	Shader(std::string& filepath);
	~Shader();

	void bind();
	void unbind();

	//Set Uniforms
	void setUniform1i(const std::string& name, int value);
	void setUniform1f(const std::string& name, float value);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniformMat4f(const std::string& name, const glm::mat4& matrix);

private:
	std::string filepath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

	shaderProgramSoruce parasedShader(std::string& filepath);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int compileShader(unsigned int type, const std::string& source);
	
	int getUniformLocation(const std::string& name);
};
