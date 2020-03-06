#pragma once

#include "vec3.h"

class Material {
private:
	                                                                                                                                            
public:
	enum class Type {
		MATTE, // réflexion diffuse seule (sans inter-réflexions)
		PLASTIC, // réflexion diffuse + spéculaire (via Phong ou Blinn-Phong)
		METALLIC, // inter-réflexions seules (théoriquement, pas de diffuse)
		DIELECTRIC, // réflexions et réfractions en même temps (pas correct d'un pov physique)
		MAX,
		EMISSIVE
	};

	Type type;
	vec3 color;
	float ior; //indice de réfraction

	Material();
	Material(Type t, vec3 c, float i);
	~Material() {}
};

