#include "Window.h"


Window::Window(int width,int height):
m_windowWidth(width),
m_windowHeight(height)
{
}


Window::~Window()
{
}

int Window::GetHeight()const{
	return m_windowWidth;
}

int Window::GetWidth()const{
	return m_windowHeight;
}