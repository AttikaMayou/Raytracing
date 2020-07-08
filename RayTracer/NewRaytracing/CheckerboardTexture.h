#pragma once

#include "Texture.h"

class CheckerboardTexture : public Texture {
public:
	CheckerboardTexture();
	CheckerboardTexture(Texture* t0, Texture* t1);

	virtual vec3 value(float u, float v, const vec3& point) const;

private:
	Texture* even;
	Texture* odd;
};