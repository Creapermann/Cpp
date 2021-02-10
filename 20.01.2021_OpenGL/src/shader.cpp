#include "shader.hpp"

#include "renderer.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>



Shader::Shader(std::string& filepath) 
	: filepath(filepath)
{
	shaderProgramSoruce sp = parasedShader(filepath);
	GLCheckError(m_RendererID = createShader(sp.vertexSource, sp.fragmentSource));

}

Shader::~Shader() {
	glUseProgram(0);
}

shaderProgramSoruce Shader::parasedShader(std::string& filepath) {
	std::ifstream stream(filepath);

	enum class shaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	shaderType currentShaderType = shaderType::NONE;

	std::string line;
	std::stringstream ss[2];

	while (std::getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				currentShaderType = shaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				currentShaderType = shaderType::FRAGMENT;
		}
		else if (currentShaderType != shaderType::NONE) {
			ss[(int)currentShaderType] << line << '\n';
		}
	}


	return { ss[0].str(), ss[1].str() };
}


unsigned int Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader) {

	GLCheckError(unsigned int program = glCreateProgram());

	GLCheckError(unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader));
	GLCheckError(unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader));

	GLCheckError(glAttachShader(program, vs));
	GLCheckError(glAttachShader(program, fs));

	GLCheckError(glLinkProgram(program));

	GLCheckError(glValidateProgram(program));

	int programValStatus = 0;
	GLCheckError(glGetProgramiv(program, GL_VALIDATE_STATUS, &programValStatus));
	if (programValStatus != GL_TRUE)
		std::cout << "Your shader programm is not value!" << std::endl;

	GLCheckError(glDeleteShader(vs));
	GLCheckError(glDeleteShader(fs));

	return program;
}


unsigned int Shader::compileShader(unsigned int type, const std::string& source) {

	GLCheckError(unsigned int id = glCreateShader(type));

	const char* src = &source[0];        //creates a pointer to the beginning of the string 'source'

	GLCheckError(glShaderSource(id, 1, &src, nullptr));

	GLCheckError(glCompileShader(id));


	int shaderCompStatus = 0;
	GLCheckError(glGetShaderiv(id, GL_COMPILE_STATUS, &shaderCompStatus));
	if (shaderCompStatus != GL_TRUE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(sizeof(char) * length);

		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!"
			<< std::endl;
		std::cout << message << std::endl;

		delete[] message;

		glDeleteShader(id);
		return 0;
	}
	return id;
}




void Shader::bind() {
	glUseProgram(m_RendererID);
}

void Shader::unbind() {
	glUseProgram(0);
}



void Shader::setUniform1i(const std::string& name, int value) {
	GLCheckError(glUniform1i(getUniformLocation(name), value));
}

void Shader::setUniform1f(const std::string& name, float value) {
	GLCheckError(glUniform1f(getUniformLocation(name), value));
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
	GLCheckError(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
}

void Shader::setUniformMat4f(const std::string& name, const glm::mat4& matrix) {
	GLCheckError(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}



int Shader::getUniformLocation(const std::string& name) {
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];
		
	GLCheckError(int location = glGetUniformLocation(m_RendererID, name.c_str()));
	if (location == -1)
		std::cout << "Warning: uniform " << name << " does not exist!" << std::endl;
	else
		m_UniformLocationCache[name] = location;
	return location;
}