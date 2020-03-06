#include "Light.h"

Light::Light(const Light& l)
{
	direction = l.direction;
	position = l.position;
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
