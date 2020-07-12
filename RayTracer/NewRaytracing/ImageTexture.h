#pragma once

#include "Texture.h"

class ImageTexture : public Texture {
public:
	ImageTexture();
	ImageTexture(unsigned char* pixels, int a, int b);
	ImageTexture(const ImageTexture& copy);
	~ImageTexture();
	ImageTexture& operator=(const ImageTexture& i);
	virtual vec3 value(float u, float v, const vec3& p) const;

private:
	unsigned char* data;
	int width;
	int height;
};