#pragma once

#include "vec3.h"

class Ray {
public:
    Ray();
    Ray(const vec3& orig, const vec3& dir);

    vec3 getDirection() const;
    vec3 getOrigine() const;
    vec3 pointAtParamater(float t) const;

private:
    vec3 origine;
    vec3 direction;
};