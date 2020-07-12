#include "CheckerboardTexture.h"

CheckerboardTexture::CheckerboardTexture() : even(nullptr), odd(nullptr) {}

CheckerboardTexture::CheckerboardTexture(Texture* t0, Texture* t1) : even(t0), odd(t1) {}

CheckerboardTexture::CheckerboardTexture(const CheckerboardTexture& copy) : even(copy.even), odd(copy.odd) {}

CheckerboardTexture::~CheckerboardTexture()
{
	delete even;
	delete odd;
}

CheckerboardTexture& CheckerboardTexture::operator=(const CheckerboardTexture& c)
{
	even = c.even;
	odd = c.odd;
	return* this;
}

vec3 CheckerboardTexture::value(float u, float v, const vec3& point) const {
	float sines = sin(10 * point.getX()) * sin(10 * point.getY()) * sin(10 * point.getZ());

	if (sines < 0) {
		return odd->value(u, v, point);
	}
	else {
		return even->value(u, v, point);
	}
}
