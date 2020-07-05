#pragma once

#include "Material.h"
#include "Ray.h"

class Primitive {

private :
protected :
	vec3 position;
	vec3 rotation;
	vec3 scale;
	Material* mat = nullptr;
public :
	Primitive();
	Primitive(Material* m);
	Primitive(const Primitive& p);
	Primitive& operator=(const Primitive& p);
	virtual ~Primitive();

	void Translate(const vec3& t);
	void RotateX(float deg);
	void RotateY(float deg);
	void RotateZ(float deg);
	void Scale(const vec3& s);
	vec3 LocalToGlobal(const vec3& v) const;

	vec3 GetPosition() const { return position; };
	vec3 GetRotation() const { return rotation; };
	vec3 GetScale() const { return scale; };
	Material* GetMaterial() const;
	void SetPosition(const vec3& p);
	void SetRotation(const vec3& r);
	void SetScale(const vec3& s);
	void SetMaterial(Material* m);
	
	virtual float Intersect(const Ray& ray) const = 0;
	virtual vec3 CalcNormal(const vec3& p) const = 0;
};
