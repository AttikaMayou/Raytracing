#pragma once

#include "Background.h"
#include "Intersection.h"
#include "Material.h"
#include <vector>

//TODO : récupérer tous les trucs imports du main (background, spheres...) 

class Tracer {
private :
	// limite le nombre de récusions possibles
	static const int MAX_DEPTH = 5;
	// constexpr : c'est bien une variable const
	static constexpr float EPSILON = 0.001f;

	Background background;
	// scene
	std::vector<Primitive*> scene;
	Material* mat;

public :
	Tracer();
	~Tracer();
	vec3 trace(const Ray& ray, int depth = 0);
};
