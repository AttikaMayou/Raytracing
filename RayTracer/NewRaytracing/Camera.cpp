#include "Camera.h";

Camera::Camera(vec3 lookFrom, vec3 lookAt, vec3 vup, float vfov, float aspect, float aperture, float focusDist, float t0, float t1) {
	float theta = vfov * M_PI / 180;
	float h = tan(theta / 2);
	float viewportHeight = 2.0 * h;
	float viewportWidth = aspect * viewportHeight;

	w = unitVector(lookFrom - lookAt);
	u = unitVector(cross(vup, w));
	v = cross(w, u);

	origin = lookFrom;
	horizontal = u * focusDist * viewportWidth;
	vertical = v * focusDist * viewportHeight;
	lowerLeftCorner = origin - horizontal/2 - vertical/2 - w * focusDist;

	lensRadius = aperture / 2;
	time0 = t0;
	time1 = t1;
}

Ray Camera::getRay(float s, float t) const {
	vec3 rad = Utils::randInUnitDisk() * lensRadius;
	vec3 offset = u * rad.getX() + v * rad.getY();

	return Ray(origin + offset, lowerLeftCorner + horizontal * s + vertical * t - origin - offset);
}