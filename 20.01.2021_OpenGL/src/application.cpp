//Check GL methods at "https://docs.gl"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>

#include "renderer.hpp"	
#include "vertexBuffer.hpp"
#include "indexBuffer.hpp"
#include "vertexArray.hpp"
#include "vertexBufferLayout.hpp"
#include "shader.hpp"
#include "texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"	

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "tests/testClearColor.hpp"
#include "tests/testNewImage.hpp"


int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())    
		return -1;


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int windowSizeX = 960, windowSizeY = 540;

	window = glfwCreateWindow(windowSizeX, windowSizeY, "Drawing Screen", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);      

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)           
		std::cout << "Error, glew was not initalized right!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;             
	{
		
		GLCheckError(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		GLCheckError(glEnable(GL_BLEND));

		
		std::string shaderPath = "res/shaders/Basic.shader";
		Shader shader(shaderPath);
		shader.bind();

		//ImGui Init
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init();
		ImGui::StyleColorsDark();

		int imGuiWindowSizeX = 600, imGuiWindowSizeY = 300;

		const char* items[] = { "None", "Clear Color", "New Image", "Smthing else" };
		int choosenElement = 0;
		

		Renderer renderer;

		test::TestClearColor ccTest;
		test::NewImage niTest(shader, renderer);


		while (!glfwWindowShouldClose(window)) {
			renderer.clear();

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			

			switch (choosenElement) {
			case 1:
				ccTest.onRender();
				ccTest.onUpdate(0.0f);
				ccTest.onImGuiRender();

				if (ImGui::Button("Back")) {
					choosenElement = 0;

					ccTest.~TestClearColor();
				}
				break;

			case 2:
				
				niTest.onImGuiRender();
				niTest.onRender();

				if (ImGui::Button("Back")) {
					choosenElement = 0;
				}
				
				break;

			default:
				ImGui::Begin("Test Menu");

				ImGui::SetWindowPos(ImVec2(windowSizeX / 2 - imGuiWindowSizeX / 2, 10));
				ImGui::SetWindowSize(ImVec2(600, 500));

				ImGui::Text("Choose one of the following Tests: ");
				ImGui::Combo("Tests", &choosenElement, items, IM_ARRAYSIZE(items), 10);
				

				ImGui::End();

				break;
			}


			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			

			GLCheckError(glfwSwapBuffers(window));

			GLCheckError(glfwPollEvents());
		}
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	

	glfwTerminate();
	return 0;
}