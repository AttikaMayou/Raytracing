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
}

Material* Primitive::GetMaterial() {
	return mat;
}

void Primitive::SetMaterial(Material* m) {
	mat = m;
}