#include "Material.h"

Material::Material() = default;

vec3 Material::emitted(float u, float v, const vec3& point) const {
	return vec3(0, 0, 0);
}