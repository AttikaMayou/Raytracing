#pragma once

#include "../Utils/vec3.h"
#include "../Primitive/Primitive.h"

class Light : Primitive {
private:
	vec3 position;
	vec3 direction;

public:
	Light() : position(vec3{ 0.f, 0.f, 0.f }), direction(vec3{ 0.f, 0.f, 0.f }) {};
	Light(const vec3& p, const vec3& d) : position(p), direction(d) {};
	Light(const Light& l);
	~Light();
	Light& operator=(const Light& l);
};

// exo1 = appliquer l'équation de Lambert (N dot L)
		//rappel : L est la direction du fragment (position) VERS la lumière
		//dans le cas d'une directionnelle : L = -direction
// exo2 = envoyer un rayon type "feeler" vers les lumières
		//si intersection, cela signifie que l'on est dans
		//l'ombre d'une primitive.
		//donc col = vec3(0, 0, 0)