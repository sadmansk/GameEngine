#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <string>
#include <GL/glew.h>

class Texture {
public:
	Texture(const std::string& fileName);
	void bind(unsigned int unit) const;
    static void unbindAll();
	virtual ~Texture();

private:
	Texture(const Texture& texture) {}
	void operator=(const Texture& texture) {}

	GLuint m_texture;
};
#endif // TEXTURE_H_

