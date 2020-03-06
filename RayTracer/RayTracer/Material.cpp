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

void Material::SetMaterialType(Type t)
{
	type = t;
}

void Material::SetMaterialColor(const vec3& c)
{
	color = c;
}

void Material::SetMaterialIndice(float i)
{
	ior = i;
}
