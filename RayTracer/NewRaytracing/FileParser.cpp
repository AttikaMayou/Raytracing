#include "FileParser.h"

FileParser::FileParser(string file) {
	fileToLoad = file;
	camIsDefined = false;
}

void split(const string& s, char delim, vector<string>& params) {
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim)) {
		params.push_back(item);
	}
}

ObjectsList FileParser::GetScene() {
	ObjectsList objectList;
	ifstream fileScene(fileToLoad, ios::in);

	if (!fileScene) {
		return objectList;
	}

	string fileLine;

	while (getline(fileScene, fileLine)) {
		Intersects* object = ReturnCurrentObject(fileLine);

		if (object != nullptr) {
			objectList.Add(object);
		}
	}

	fileScene.close();

	return objectList;
}

Intersects* FileParser::ReturnCurrentObject(string lineToParse) {
	vector<string> params;
	split(lineToParse, ' ', params);

	int lengthSize = params.size();

	if (lengthSize > 0) {
		if (params[0] == "sphere") {
			vec3 pos(stof(params[1]), stof(params[2]), stof(params[3]));
			float radius = stof(params[4]);

			Material* mat = nullptr;
			Texture* tex = nullptr;

			if (lengthSize > 6) {
				string materialType = params[5];
				string textureType = params[6];

				if (textureType == "unicolor") {
					tex = new UniColorTexture(vec3(stof(params[7]), stof(params[8]), stof(params[9])));
				}
				else if (textureType == "image") {
					// Triste
				}
				else if (textureType == "checker") {
					tex = new CheckerboardTexture(new UniColorTexture(vec3(stof(params[7]), stof(params[8]), stof(params[9]))), new UniColorTexture(vec3(stof(params[10]), stof(params[11]), stof(params[12]))));
				}

				if (materialType == "lambert") {
					mat = new Lambertian(tex);
				}
				else if (materialType == "metal") {
					mat = new Metal(vec3(stof(params[7]), stof(params[8]), stof(params[9])), stof(params[10]));
				}
				else if (materialType == "light") {
					mat = new DiffuseLight(tex);
				}
				else if (materialType == "dielectric") {
					mat = new Dielectric(stof(params[7]));
				}
			}

			if (mat == nullptr)
			{
				mat = new Lambertian(new UniColorTexture(vec3(.65, .05, .05)));
			}

			return new Sphere(pos, radius, mat);
		}
		else if (params[0] == "cube") {

		}
		else if (params[0] == "cam") {
			if (lengthSize > 6) {
				camIsDefined = true;
				posCam.setX(stof(params[1]));
				posCam.setY(stof(params[2]));
				posCam.setZ(stof(params[3]));
				lookAt.setX(stof(params[4]));
				lookAt.setY(stof(params[5]));
				lookAt.setZ(stof(params[6]));
			}
		}
	}

	return nullptr;
}

