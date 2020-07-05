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

Material* Primitive::GetMaterial() const
{
	return mat;
}

void Primitive::SetMaterial(Material* m) {
	mat = m;
}