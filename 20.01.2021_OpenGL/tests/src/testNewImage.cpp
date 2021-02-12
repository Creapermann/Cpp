#include "testNewImage.hpp"


#include "std_image/stb_image.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <array>
#include <conio.h>

#include "renderer.hpp"


#include <iostream>


namespace test {

	NewImage::NewImage(Shader& s, Renderer& r)
		: shader(s), renderer(r), vb(positions, 4 * 4 * sizeof(float)), ib(indecies, 6), tex(path)
	{
		layout.push<float>(2);
		layout.push<float>(2);
		va.addBuffer(vb, layout);
	}

	NewImage::~NewImage() { }

	void NewImage::onRender() {

		if (path.size() >= 3) {
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
			glm::mat4 MVP = proj * view * model;

			shader.bind();
			shader.setUniformMat4f("u_MVP", MVP);
			shader.unbind();
			renderer.draw(va, ib, shader);
		}
	}
	
	void NewImage::onImGuiRender() {

		std::array<char, 100> buf = {""};

		if (ImGui::InputText("Image Location", buf.data(), buf.size())) {
			temp = buf.data();
		}

		int enterKeyPressed = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_ENTER);
		if (enterKeyPressed == GLFW_PRESS){
			path = "res/Textures/";
			path += temp;
			tex.changeTex(path);

			tex.bind();
			shader.setUniform1i("u_Texture", 0);
		}



		ImGui::SliderFloat("X-Axis Translation", &translation.x, 0.0f, 960.0f);
		ImGui::SliderFloat("Y-Axis Translation", &translation.y, 0.0f, 540.0f);
	}
}