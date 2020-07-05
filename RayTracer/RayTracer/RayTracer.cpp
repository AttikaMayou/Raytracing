
#include <cmath>
#include <iostream>
#include <stdlib.h>

#include "Header/Bitmap.h"
#include "Header/Tracer.h"
#include "Header/Camera.h"

float randFloat() {
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

int main(int argc, const char* argv[])
{
	const int width = 200;
	const int height = 100;

	Bitmap bmp;
	bmp.SetHeader(width, height);

	Tracer tracer = Tracer();
	Camera cam;

	float aspectRatio = float(width) / float(height);

	int iterAntiAliasing = 50;

	for (int j = 0; j < height; j++)
	{
		//float y = -2.f * (float(j - height / 2) + 0.5f) / height;

		for (int i = 0; i < width; i++)
		{
			// calcul des coordonnées monde des pixels
			//float x = aspectRatio * 2.f * (float(i - width / 2) + 0.5f) / width;
			vec3 col(0, 0, 0);

			for (int s = 0; s < iterAntiAliasing; s++) {
				float x = float(i + randFloat()) / float(width);
				float y = float(j + randFloat()) / float(height);

				Ray ray = cam.getRay(x, y);
				//ray.normalizeDirection();

				col = col + tracer.trace(ray);
			}

			col = col / iterAntiAliasing;
			// Génération du rayon primaire
			/*Ray ray;
			vec3 orig = { 0.f, 0.f, 0.f };
			ray.setOrigin(orig);
			vec3 dir = { x , y , 1.f };
			ray.setDirection(dir);
			ray.normalizeDirection();*/

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