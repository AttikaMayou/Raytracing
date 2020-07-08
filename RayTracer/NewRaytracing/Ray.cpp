#include "Ray.h"

Ray::Ray() {
}

Ray::Ray(const vec3& orig, const vec3& dir) {
    origine = orig;
    direction = dir;
}

vec3 Ray::getDirection() const {
    return direction;
}

vec3 Ray::getOrigine() const {
    return origine;
}

vec3 Ray::pointAtParamater(float t) const {
    return origine + direction * t;
}