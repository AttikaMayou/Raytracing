#pragma once

#include <fstream>
#include <string>
#include <sstream>

#include "Camera.h"

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

class FileParser {
public:
	FileParser(string file);
	ObjectsList GetScene();
	Intersects* ReturnCurrentObject(string currentLine);

	bool camIsDefined;
	vec3 posCam;
	vec3 lookAt;
private:
	string fileToLoad;
};