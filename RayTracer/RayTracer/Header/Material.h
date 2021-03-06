#pragma once

#include "Utils/vec3.h"

class Material {
private:
	                                                                                                                                            
public:
	enum class Type {
		MATTE, // r�flexion diffuse seule (sans inter-r�flexions)
		PLASTIC, // r�flexion diffuse + sp�culaire (via Phong ou Blinn-Phong)
		METALLIC, // inter-r�flexions seules (th�oriquement, pas de diffuse)
		DIELECTRIC, // r�flexions et r�fractions en m�me temps (pas correct d'un pov physique)
		MAX,
		EMISSIVE
	};

	Type type;
	vec3 color;
	float ior; //indice de r�fraction

	Material();
	Material(Type t, vec3 c, float i);
	Material(const Material& m);
	~Material() {}
	Material& operator=(const Material& m);
	Type GetMaterial() { return type; }
	vec3 GetColor() { return color; }
	float GetIor() { return ior; }
	void SetMaterialType(Type t);
	void SetMaterialColor(const vec3& c);
	void SetMaterialIndice(float i);
};

