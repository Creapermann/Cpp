#pragma once

#include "test.hpp"


namespace test {

	class TestClearColor : Test
	{
	public:
		TestClearColor();
		~TestClearColor();
		
		void onUpdate(float deltaTime) override;
		void onRender() override;
		void onImGuiRender() override;

	private:
		float m_ClearColor[4];
	};
}