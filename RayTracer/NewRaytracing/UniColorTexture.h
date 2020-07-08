#pragma once

#include "Texture.h"

class UniColorTexture : public Texture {
public:
	UniColorTexture() {}
	UniColorTexture(vec3 c): col(c) {}
	virtual vec3 value(float u, float v, const vec3& p) const {
		return col;
	}

private:
	vec3 col;
};