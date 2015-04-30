#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <sdl\SDL.h>

class Window
{
public:
	//ctor
	Window(const std::string title, int width, int height);
	
	//class functions
	void clear(float r, float g, float b, float a);
	void update();
	inline bool isClosed() { return m_isClosed;	}
	inline int getWidth() { return width; }
	inline int getHeight() { return height; }

	//dtor
	virtual ~Window();

private:
	SDL_Window* m_window;
	SDL_GLContext m_context;
	bool m_isClosed;
	int width, height;
	const std::string title;
};


#endif
