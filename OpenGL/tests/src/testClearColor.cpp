#include "testClearColor.hpp"
#include "renderer.hpp"

#include "imgui/imgui.h"

#include <iostream>

namespace test {


	TestClearColor::TestClearColor()
		: m_ClearColor { 0.2f, 0.3f, 0.8f, 1.0f }
	{
		std::cout << "TestClearColor constructor called!" << std::endl;
	}

	TestClearColor::~TestClearColor() {
		GLCheckError(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
		GLCheckError(glClear(GL_COLOR_BUFFER_BIT));

		std::cout << "TestClearColor destructor called!" << std::endl;
	}


	void TestClearColor::onUpdate(float deltaTime) {
	}

	void TestClearColor::onRender() {
		GLCheckError(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]));
		GLCheckError(glClear(GL_COLOR_BUFFER_BIT));
	}
	
	void TestClearColor::onImGuiRender() {
		ImGui::ColorEdit4("Clear Color", m_ClearColor);
	}
	
}