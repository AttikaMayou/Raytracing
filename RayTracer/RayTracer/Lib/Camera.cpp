#include "../Header/Camera.h";

Camera::Camera() {
	lowerLeftCorner = vec3(-2.0, -1.0, -1.0);
	horizontal = vec3(4.0, 0.0, 0.0);
	vertical = vec3(0.0, 2.0, 0.0);
	origin = vec3(0.0, 0.0, 0.0);
}

Ray Camera::getRay(float u, float v) {
	return Ray(origin, 0.1, lowerLeftCorner + horizontal * u + vertical * v, 0.9);
}