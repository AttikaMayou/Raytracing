#include "Material.h"

Material::Material()
{
	type = Type::MATTE;
	color = { 0.f, 0.f, 0.f };
	ior = 0.f;
}

Material::Material(Type t, vec3 c, float i)
{
	type = t;
	color = c;
	ior = i;
}
