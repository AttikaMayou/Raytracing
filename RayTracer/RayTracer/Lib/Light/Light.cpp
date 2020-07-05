#include "../../Header/Light/Light.h"

Light::Light(const Light& l)
	: position(l.position), direction(l.direction)
{
}

Light::~Light()
{
}

Light& Light::operator=(const Light& l)
{
	direction = l.direction;
	position = l.position;
	return *this;
}
