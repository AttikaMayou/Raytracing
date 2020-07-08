#include "Camera.h";

Camera::Camera(vec3 lookFrom, vec3 lookAt, vec3 vup, float vfov, float aspect) {
	vec3 u, v, w;

	float theta = vfov * M_PI / 180;
	float halfHeight = tan(theta / 2);
	float halfWidth = aspect * halfHeight;

	origin = lookFrom;
	w = unitVector(lookFrom - lookAt);
	u = unitVector(cross(vup, w));
	v = cross(w, u);

	lowerLeftCorner = origin - u * halfWidth - v * halfHeight - w;
	horizontal = u * 2 * halfWidth;
	vertical = v * 2.0 * halfHeight;
}

Ray Camera::getRay(float u, float v) const {
	return Ray(origin, lowerLeftCorner + horizontal * u + vertical * v - origin);
}