#include <string>
#include <sdl\SDL.h>

class Window
{
public:
	//ctor
	Window(const std::string title, int width, int height);
	
	//class functions
	void clear(float r, float g, float b, float a);
	inline bool isClosed() { return m_isClosed;	}
	void update();

	//dtor
	virtual ~Window();

private:
	SDL_Window* m_window;
	SDL_GLContext m_context;
	bool m_isClosed;
};
