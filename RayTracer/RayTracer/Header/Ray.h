#pragma once

#include "Utils/vec3.h"

class Ray {
private :
	vec3 origin;
	float tmin;
	vec3 direction;
	float tmax;

public :
	Ray();
	Ray(const vec3& o, float min, const vec3& d, float max);
	Ray(const Ray& r);
	~Ray();
	Ray& operator=(const Ray& r);
	vec3 getOrigin() const{ return origin; }
	float getTMin() const { return tmin; }
	vec3 getDirection() const { return direction; }
	float getTMax() const { return tmax; }
	void setOrigin(const vec3& o);
	void setTMin(float t);
	void setDirection(const vec3& d);
	void normalizeDirection();
	void SetTMax(float t);
	// calcule la position d'un point (intersection)
	// en fonction d'un paramètre de distance
	inline vec3 evaluate(const float t) const {
		return origin + direction * t;
	}
};
