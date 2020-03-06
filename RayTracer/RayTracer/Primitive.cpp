#include "Primitive.h"

Primitive::Primitive()
{

}

Primitive::Primitive(const Material* m)
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
