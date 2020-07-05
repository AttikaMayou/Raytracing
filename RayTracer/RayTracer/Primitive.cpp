#include "Primitive.h"

Primitive::Primitive()
{

}

Primitive::Primitive(Material* m)
{
	mat = m;
}

Primitive::Primitive(const Primitive& p)
{
	mat = p.mat;
}

Primitive& Primitive::operator=(const Primitive& p)
{
	mat = p.mat;
	return *this;
}

Primitive::~Primitive()
{
	delete mat;
}

void Primitive::Translate(const vec3& t)
{
}

void Primitive::RotateX(float deg)
{
}

void Primitive::RotateY(float deg)
{
}

void Primitive::RotateZ(float deg)
{
}

void Primitive::Scale(const vec3& s)
{
}

vec3 Primitive::LocalToGlobal(const vec3& v) const
{
}

Material* Primitive::GetMaterial() const
{
	return mat;
}

void Primitive::SetMaterial(Material* m) {
	mat = m;
}