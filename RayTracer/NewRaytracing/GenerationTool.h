#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <ctime>
#include <chrono>

#include "Camera.h"
#include "Utils.h"

// OBJECTS
#include "ObjectsList.h"
#include "Sphere.h"
#include "Box.h"

// MATERIAL
#include "Lambertian.h"
#include "Metal.h"
#include "Dielectric.h"
#include "DiffuseLight.h"

// TEXTURE
#include "UniColorTexture.h"
#include "CheckerboardTexture.h"
#include "ImageTexture.h"

using namespace std;

class GenerationTool {
public:
	GenerationTool();
	GenerationTool(string _inputSceneName, string _outputImgName, int _width, int _height, int _nbThread, int _nbImage);
	GenerationTool(const GenerationTool& copy);
	~GenerationTool();
	GenerationTool& operator=(const GenerationTool g);

	void CreateJpg(int width, int height, int channels, int nbImg);
	vec3 GetColorWithRay(const Ray& ray, ObjectsList world, int depth);
	thread GetPartPixelsData(int nbProcess, float width, float height, float widthStart, float widthEnd, int nbImg, const Camera cam, ObjectsList world);
	void StartImageCreation();

private:
	vector<thread> threads;
	vector<vector<vec3>> pixelsData;

	string inputSceneName;
	string outputImgName;

	int width;
	int height;
	int nbThread;
	int nbImage;
};