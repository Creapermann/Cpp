#pragma once

#include "test.hpp"

#include "imgui/imgui.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"	


#include "texture.h"
#include "shader.hpp"
#include "vertexBufferLayout.hpp"
#include "vertexBuffer.hpp"
#include "vertexArray.hpp"
#include "indexBuffer.hpp"


#include <string>

namespace test {

	class NewImage : Test
	{
	public:
		NewImage(Shader &s, Renderer &r);
		~NewImage();

		void onRender();
		void onImGuiRender();

		
	private:
		float positions[16] =
		{
			0.0f,   0.0f, 0.0f, 0.0f,
			200.0f, 0.0f, 1.0f, 0.0f,
			200.0f, 200.0f, 1.0f, 1.0f,
			0.0f,   200.0f, 0.0f, 1.0f
		};

		unsigned int indecies[6] = {
			0, 1, 2,
			2, 3, 0
		};


		VertexArray va;
		VertexBuffer vb;
		VertexBufferLayout layout;
		IndexBuffer ib;
		Texture tex;
		Shader shader;
		Renderer renderer;

		std::string path = "res/Textures/Skull.png";
		
		std::string temp;


		glm::vec3 translation = glm::vec3(0, 0, 0);

		glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	};
}