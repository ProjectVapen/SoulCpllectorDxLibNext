#pragma once
class Window
{
	private:
		
		int const m_windowWidth;
		int const m_windowHeight;
	
	public:

		Window(int width,int height);
		~Window();

		int GetWidth()const;
		int GetHeight()const;
};

