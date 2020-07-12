#include "UniColorTexture.h"

UniColorTexture::UniColorTexture() : col({0.f, 0.f, 0.f}) {}

UniColorTexture::UniColorTexture(vec3 c) : col(c) {}

UniColorTexture::UniColorTexture(const UniColorTexture& copy) : col(copy.col) {}

UniColorTexture::~UniColorTexture() {}

UniColorTexture& UniColorTexture::operator=(const UniColorTexture& u)
{
	col = u.col;
	return *this;
}
