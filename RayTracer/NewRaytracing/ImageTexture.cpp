#include "ImageTexture.h"

ImageTexture::ImageTexture() {
}

ImageTexture::ImageTexture(unsigned char* pixels, int a, int b) : data(pixels), width(a), height(b) {
}

vec3 ImageTexture::value(float u, float v, const vec3& p) const {
	int i = u * width;
	int j = (1 - v) * height - 0.001;

	if (i < 0) {
		i = 0;
	}

	if (j < 0) {
		j = 0;
	}

	if (i > width - 1) {
		i = width - 1;
	}
	if (j > height - 1) {
		i = height - 1;
	}

	float r = int(data[3 * i + 3 * width * j + 0]) / 255.0;
	float g = int(data[3 * i + 3 * width * j + 1]) / 255.0;
	float b = int(data[3 * i + 3 * width * j + 2]) / 255.0;

	return vec3(r, g, b);
}