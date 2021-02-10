#pragma once

#include "test.hpp"

#include "imgui/imgui.h"

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
			-0.5f, -0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.0f, 1.0f
		};

		unsigned int indecies[6] = {
			0, 1, 2,
			2, 3, 0
		};


		VertexArray va;
		VertexBuffer vb;
		VertexBufferLayout layout;

		IndexBuffer ib;

		std::string path = "res/Textures/Skull.png";
		Texture tex;

		Shader shader;

		Renderer renderer;

	};
}