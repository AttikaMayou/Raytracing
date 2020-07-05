
#include <cmath>
#include <iostream>

#include "Bitmap.h"
#include "Tracer.h"

int main(int argc, const char* argv[])
{
	const int width = 800;
	const int height = 600;

	Bitmap bmp;
	bmp.SetHeader(width, height);

	Tracer tracer;

	float aspectRatio = float(width) / float(height);
	for (int j = 0; j < height; j++)
	{
		float y = -2.f * (float(j - height / 2) + 0.5f) / height;

		for (int i = 0; i < width; i++)
		{
			// calcul des coordonnées monde des pixels
			float x = aspectRatio * 2.f * (float(i - width / 2) + 0.5f) / width;

			// Génération du rayon primaire
			Ray ray;
			vec3 orig = { 0.f, 0.f, 0.f };
			ray.setOrigin(orig);
			vec3 dir = { x , y , 1.f };
			ray.setDirection(dir);
			ray.normalizeDirection();

			color col = tracer.trace(ray);

			// compression gamma des couleurs linéaires
			// pour la stockage en 8 bits RGB
			int r = int(powf(col.getX(), 1.f / 2.2f) * 255.99f);
			int g = int(powf(col.getY(), 1.f / 2.2f) * 255.99f);
			int b = int(powf(col.getZ(), 1.f / 2.2f) * 255.99f);
			bmp.OutputColor(r, g, b);
		}
	}

	return 0;
}