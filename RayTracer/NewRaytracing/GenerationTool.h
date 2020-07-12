#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <ctime>
#include <chrono>

#include "Utils.h"
#include "FileParser.h"

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