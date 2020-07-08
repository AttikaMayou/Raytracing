// NewRaytracing.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <ctime>
#include <chrono>

using namespace std;

#include "Camera.h"
#include "Utils.h"
#include "Scene.h"
#include "Sphere.h"

// MATERIAL
#include "Lambertian.h"
#include "Metal.h"
#include "Dielectric.h"
#include "DiffuseLight.h"

// TEXTURE
#include "UniColorTexture.h"
#include "CheckerboardTexture.h"
#include "ImageTexture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external/stb_image_write.h"


vector<thread> threads;

// Dim 1 = thread
// Dim 2 = Y
// Dim 3 = X
vector<vector<vec3>> imageColors;

void createJpg(int width, int height, int channels, int nbImg) {
	size_t size = width * height * channels;

	uint8_t* data = new uint8_t[width * height * channels];

	float r, g, b;
	int ir, ig, ib;
	int index = 0;

	for (int j = height - 1; j >= 0; --j) {
		for (int k = 0; k < width; ++k) {
			vec3 col = imageColors[j][k];
			int r = int(col.getX() * 255.99f);
			int g = int(col.getY() * 255.99f);
			int b = int(col.getZ() * 255.99f);

			data[index++] = r;
			data[index++] = g;
			data[index++] = b;
			data[index++] = 255;
		}
	}

	string filename = "rendu" + std::to_string(nbImg) + ".jpg";
	stbi_write_png(filename.c_str(), width, height, channels, data, width * channels);
}

vec3 colorMap(const Ray& ray, Intersects* world, int depth) {
	IntersectRecord rec;

	if (world->hit(ray, 0.001f, 999999.f, rec)) {
		Ray scattered;
		vec3 attenuation;
		vec3 emitted = rec.mat->emitted(rec.u, rec.v, rec.point);

		if (depth < 50 && rec.mat->scatter(ray, rec, attenuation, scattered)) {
			return emitted + attenuation * colorMap(scattered, world, depth + 1);
		}
		else {
			return emitted;
		}
		//vec3 target = rec.point + rec.normal + Utils::randInUnitSphere();
		//return colorMap(Ray(rec.point, target - rec.point), world) * 0.5;
		//return vec3(rec.normal.getX() + 1, rec.normal.getY() + 1, rec.normal.getZ() + 1) * 0.5;
	}
	else {
		return vec3(0.7, 0.8, 1.0);
		/*
		vec3 unitDirection = unitVector(ray.getDirection());
		float t = (unitDirection.getY() + 1) * 0.5;

		return vec3(1.0f, 1.0f, 1.0f) * (1.0f - t) + vec3(0.0f, 0.7f, 1.0f) * t;*/
	}
}

thread processImage(int nbProcess, float width, float height, float widthStart, float widthEnd, int nbImg, const Camera cam, Intersects* world) {
	std::thread thread([nbProcess, width, height, widthStart, widthEnd, nbImg, cam, world]() {
		int iterAntiAliasing = 100;

		for (int j = height - 1; j >= 0; j--)
		{
			for (int i = widthStart; i < widthEnd; i++)
			{
				vec3 col(0, 0, 0);

				for (int s = 0; s < iterAntiAliasing; s++) {
					float u = float(i + Utils::randFloat()) / float(width);
					float v = float(j + Utils::randFloat()) / float(height);

					Ray ray = cam.getRay(u, v);
					col = col + colorMap(ray, world, 0);
				}

				col = col / iterAntiAliasing;
				col = vec3(sqrt(col.getX()), sqrt(col.getY()), sqrt(col.getZ()));

				imageColors[j][i] = col;
			}
		}
	});

	return thread;
}

//void createImage(float width, float height, int nbImg) {
//	Bitmap bmp(nbImg);
//	bmp.SetHeader(width, height);
//
//	//int r = int(powf(col.getX(), 1.f / 2.2f) * 255.99f);
//	//int g = int(powf(col.getY(), 1.f / 2.2f) * 255.99f);
//	//int b = int(powf(col.getZ(), 1.f / 2.2f) * 255.99f);
//
//	for (int i = 0; i < imageColors.size(); ++i) {
//		for (int j = height - 1; j >= 0; --j) {
//			for (int k = 0; k < imageColors[i][j].size(); ++k) {
//				vec3 col = imageColors[i][j][k];
//				int r = int(col.getX() * 255.99f);
//				int g = int(col.getY() * 255.99f);
//				int b = int(col.getZ() * 255.99f);
//
//				bmp.OutputColor(r, g, b);
//			}
//		}
//	}
//}

int main() {
	int nbProcess = 4;
	int nbImg = 1;

	const int width = 600;
	const int height = 600;

	for (int indexImg = 0; indexImg < nbImg; ++indexImg) {
		threads.clear();
		imageColors.clear();
		threads.resize(nbProcess);
		imageColors.resize(height);

		for (int i = 0; i < height; i++) {
			imageColors[i].resize(width);
		}

		auto start = chrono::system_clock::now();
		std::cout << "Start multiThread for img " << indexImg << endl;

		float widthPart = width / nbProcess;

		Camera cam(vec3(0, 0, 1), vec3(0, 0, -1), vec3(0, 1, 0), 90, float(width / height));

		int texWidth, texHeight, textChan;
		unsigned char* textureData = stbi_load("texture.jpg", &texWidth, &texHeight, &textChan, 0);

		Intersects* list[2];
		list[0] = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(new ImageTexture(textureData, texWidth, texHeight)));
		list[1] = new Sphere(vec3(0, -100.5, -1), 100, new Lambertian(
			new CheckerboardTexture(new UniColorTexture(vec3(0.1, 0.3, 0.8)), new UniColorTexture(vec3(0.8, 0.2, 0.2)))
		));
		//list[2] = new Sphere(vec3(1, 0, -1), 0.5, new Metal(vec3(0.8, 0.6, 0.2), 0.1));
		//list[3] = new Sphere(vec3(-1, 0, -1), 0.5, new Dielectric(1.5));
		//list[2] = new Sphere(vec3(0, 3, -1), 1, new DiffuseLight(new ConstantTexture(vec3(4,4,4))));
		//list[4] = new Sphere(vec3(-1, 0, -1), -0.45, new Dielectric(1.5));

		Intersects* world = new Scene(list, 2);

		for (int i = 0; i < nbProcess; i++) {
			threads[i] = processImage(i, width, height, widthPart * i, widthPart * i + widthPart, indexImg, cam, world);
			cout << "threads " << i << " parse img x to " << (widthPart * i) << " to " << (widthPart * i + widthPart) << endl;
		}

		std::cout << "Waiting multiThread" << endl;

		for (int i = 0; i < nbProcess; i++) {
			threads[i].join();
		}

		auto end = chrono::system_clock::now();

		chrono::duration<double> elapsedSeconds = end - start;

		std::cout << "End multiThread at : " << elapsedSeconds.count() << endl;

		createJpg(width, height, 4, indexImg);

		end = chrono::system_clock::now();
		elapsedSeconds = end - start;

		std::cout << "End creation image after : " << elapsedSeconds.count() << " sec" << endl;
	}
	
	return 0;
}