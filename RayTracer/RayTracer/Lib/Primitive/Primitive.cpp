#include "../../Header/Primitive/Primitive.h"

Primitive::Primitive()
	: position({0.f, 0.f, 0.f}), rotation({ 0.f, 0.f, 0.f }), scale({ 1.f, 1.f, 1.f })
{
	mat = nullptr;
}

Primitive::Primitive(Material* m)
	: position({ 0.f, 0.f, 0.f }), rotation({ 0.f, 0.f, 0.f }), scale({ 1.f, 1.f, 1.f })
{
	mat = m;
}

Primitive::Primitive(const vec3& p)
	: position(p), rotation({ 0.f, 0.f, 0.f }), scale({ 1.f, 1.f, 1.f })
{
	mat = nullptr;
}

Primitive::Primitive(const vec3& p, Material* m)
	: position(p), rotation({ 0.f, 0.f, 0.f }), scale({ 1.f, 1.f, 1.f })
{
	mat = m;
}

Primitive::Primitive(const vec3& p, const vec3& r, const vec3& s, Material* m)
	: position(p), rotation(r), scale(s)
{
	mat = m;
}

Primitive::Primitive(const Primitive& p)
{
	position = p.position;
	rotation = p.rotation;
	scale = p.scale;
	mat = p.mat;
}

Primitive& Primitive::operator=(const Primitive& p)
{
	position = p.position;
	rotation = p.rotation;
	scale = p.scale;
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
	return { 0.f, 0.f, 0.f };
}

void Primitive::SetPosition(const vec3& p)
{
	position = p;
}

void Primitive::SetRotation(const vec3& r)
{
	rotation = r;
}

void Primitive::SetScale(const vec3& s)
{
	scale = s;
}

void Primitive::SetMaterial(Material* m)
{
	mat = m;
}
