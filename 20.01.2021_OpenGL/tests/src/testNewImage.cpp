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

	NewImage::~NewImage() {
	}

	void NewImage::onRender() {

		tex.bind();
		shader.setUniform1i("u_Texture", 0);

		va.unbind();
		vb.unbind();
		ib.unbind();
		shader.unbind();


		renderer.draw(va, ib, shader);
		
	}
	
	void NewImage::onImGuiRender() {


		std::array<char, 100> buf = {""};

		if (ImGui::InputText("Image Location", buf.data(), buf.size())) {
				std::string temp = buf.data();
				std::cout << temp << std::endl;
		}

		
		int temp = glfwGetKey();
			
	}
}