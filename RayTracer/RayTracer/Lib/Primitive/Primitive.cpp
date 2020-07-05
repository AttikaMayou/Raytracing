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
	Matrix mTranslation;
	mTranslation(0, 3) = t.getX();
	mTranslation(1, 3) = t.getY();
	mTranslation(2, 3) = t.getZ();

	trans = mTranslation * trans;
}

void Primitive::RotateX(float deg)
{
	Matrix mRotation;
	mRotation(1, 1) = cos(deg);
	mRotation(2, 1) = sin(deg);
	mRotation(1, 2) = -sin(deg);
	mRotation(2, 2) = cos(deg);

	trans = mRotation * trans;
}

void Primitive::RotateY(float deg)
{
	Matrix mRotation;
	mRotation(0, 0) = cos(deg);
	mRotation(0, 2) = sin(deg);
	mRotation(2, 0) = -sin(deg);
	mRotation(2, 2) = cos(deg);

	trans = mRotation * trans;
}

void Primitive::RotateZ(float deg)
{
	Matrix mRotation;
	mRotation(0, 0) = cos(deg);
	mRotation(1, 0) = sin(deg);
	mRotation(0, 1) = -sin(deg);
	mRotation(1, 1) = cos(deg);

	trans = mRotation * trans;
}

void Primitive::Scale(const float s)
{
	Matrix mScale;
	mScale(0, 0) = s;
	mScale(1, 1) = s;
	mScale(2, 2) = s;

	trans = mScale * trans;
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
