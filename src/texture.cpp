#include "texture.h"
#include "stb_image.h" //for loading the textures
#include <cassert>
#include <iostream>

Texture::Texture(const std::string& fileName) {
	int width, height, numComponents; //returned by the stb loader

	unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);

	if (imageData == NULL)
		std::cerr << "Texture loading failed for texture: " << fileName << std::endl;

	glGenTextures(1, &m_texture); //generate space for 1 texture and store it in m_texture
	glBindTexture(GL_TEXTURE_2D, m_texture);

	//wrapping if the mesh has more pixels than the texture, repeat makes the texture repeat in this case
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//for interpolation
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//send the texture to the GPU
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	stbi_image_free(imageData);//free the image data from the CPU once we dont need it anymore
}


Texture::~Texture() {
	glDeleteTextures(1, &m_texture); //delete the texture
}

void Texture::bind(unsigned int unit) const {
	assert(unit >= 0 && unit <= 31);

	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}

void Texture::unbindAll() {
    glBindTexture(GL_TEXTURE_2D, 0);
}
