#pragma once

#include "Texture.h"

class UniColorTexture : public Texture {
public:
	UniColorTexture();
	UniColorTexture(vec3 c);
	UniColorTexture(const UniColorTexture& copy);
	~UniColorTexture();
	UniColorTexture& operator=(const UniColorTexture& u);
	virtual vec3 value(float u, float v, const vec3& p) const {
		return col;
	}

private:
	vec3 col;
};
