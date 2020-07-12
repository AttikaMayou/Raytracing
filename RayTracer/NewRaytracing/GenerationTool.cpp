#include "GenerationTool.h"

#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external/stb_image_write.h"

GenerationTool::GenerationTool()
{
	width = 0;
	height = 0;
	nbThread = 0;
	nbImage = 0;

	inputSceneName = "";
	outputImgName = "";
}

GenerationTool::GenerationTool(string _inputSceneName, string _outputImgName, int _width, int _height, int _nbThread, int _nbImage) {
	width = _width;
	height = _height;
	nbThread = _nbThread;
	nbImage = _nbImage;

	inputSceneName = _inputSceneName;
	outputImgName = _outputImgName;
}

GenerationTool::GenerationTool(const GenerationTool& copy)
{
	width = copy.width;
	height = copy.height;
	nbThread = copy.nbThread;
	nbImage = copy.nbImage;

	inputSceneName = copy.inputSceneName;
	outputImgName = copy.outputImgName;
}

GenerationTool::~GenerationTool() {}

GenerationTool& GenerationTool::operator=(const GenerationTool g)
{
	width = g.width;
	height = g.height;
	nbThread = g.nbThread;
	nbImage = g.nbImage;

	inputSceneName = g.inputSceneName;
	outputImgName = g.outputImgName;
	return* this;
}

void GenerationTool::CreateJpg(int width, int height, int channels, int nbImg) {
	size_t size = width * height * channels;

	uint8_t* data = new uint8_t[width * height * channels];

	float r, g, b;
	int ir, ig, ib;
	int index = 0;

	for (int j = height - 1; j >= 0; --j) {
		for (int k = 0; k < width; ++k) {
			vec3 col = pixelsData[j][k];
			int r = int(col.getX() * 255.99f);
			int g = int(col.getY() * 255.99f);
			int b = int(col.getZ() * 255.99f);

			data[index++] = r;
			data[index++] = g;
			data[index++] = b;
			data[index++] = 255;
		}
	}

	string filename = outputImgName + std::to_string(nbImg) + ".jpg";
	stbi_write_png(filename.c_str(), width, height, channels, data, width * channels);
}


vec3 GenerationTool::GetColorWithRay(const Ray& ray, ObjectsList world, int depth) {
	IntersectRecord rec;

	if (world.hit(ray, 0.001f, 999999.f, rec)) {
		Ray scattered;
		vec3 attenuation;
		vec3 emitted = rec.mat->emitted(rec.u, rec.v, rec.point);

		if (depth < 50 && rec.mat->scatter(ray, rec, attenuation, scattered)) {
			return emitted + attenuation * GetColorWithRay(scattered, world, depth + 1);
		}
		else {
			return emitted;
		}
	}
	else {
		return vec3(0.2, 0.4, 0.8);
	}
}

thread GenerationTool::GetPartPixelsData(int nbProcess, float width, float height, float widthStart, float widthEnd, int nbImg, const Camera cam, ObjectsList world) {
	std::thread thread([this, nbProcess, width, height, widthStart, widthEnd, nbImg, cam, world]() {
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
					col = col + GetColorWithRay(ray, world, 0);
				}

				col = col / iterAntiAliasing;
				col = vec3(sqrt(col.getX()), sqrt(col.getY()), sqrt(col.getZ()));

				pixelsData[j][i] = col;
			}
		}
		});

	return thread;
}

ObjectsList GetScene() {
	ObjectsList listObjects;

	Material* red = new Lambertian(new UniColorTexture(vec3(.65, .05, .05)));
	Material* white = new Lambertian(new UniColorTexture(vec3(.73, .73, .73)));
	Material* green = new Lambertian(new UniColorTexture(vec3(.12, .45, .15)));
	Material* light = new DiffuseLight(new UniColorTexture(vec3(15, 15, 15)));

	listObjects.Add(new FlipFace(new RectYZ(0, 555, 0, 555, 555, green)));
	listObjects.Add(new RectYZ(0, 555, 0, 555, 0, red));
	listObjects.Add(new RectXZ(213, 343, 227, 332, 554, light));
	listObjects.Add(new FlipFace(new RectXZ(0, 555, 0, 555, 555, white)));
	listObjects.Add(new RectXZ(0, 555, 0, 555, 0, white));
	listObjects.Add(new FlipFace(new RectXY(0, 555, 0, 555, 555, white)));

	Intersects* box1 = new Box(vec3(130, 0, 65), vec3(295, 165, 230), white);
	listObjects.Add(box1);

	Intersects* box2 = new Box(vec3(265, 0, 295), vec3(430, 330, 460), white);
	listObjects.Add(box2);

	return listObjects;
}

void GenerationTool::StartImageCreation() {
	ObjectsList world;
	FileParser fileParser(inputSceneName);

	if (inputSceneName == "") {
		world = GetScene();
	}
	else {
		world = fileParser.GetScene();
	}

	for (int indexImg = 0; indexImg < nbImage; ++indexImg) {
		threads.clear();
		pixelsData.clear();
		threads.resize(nbThread);
		pixelsData.resize(height);

		for (int i = 0; i < height; i++) {
			pixelsData[i].resize(width);
		}

		auto start = chrono::system_clock::now();
		std::cout << "Start multiThread for img " << indexImg << endl;

		float widthPart = width / nbThread;

		vec3 camPos;
		vec3 lookAt;
		if (fileParser.camIsDefined) {
			camPos = fileParser.posCam;
			lookAt = fileParser.lookAt;
		}
		else {
			camPos = vec3(278, 278, -800);
			lookAt = vec3(278, 278, 0);
		}

		Camera cam(camPos, lookAt, vec3(0, 1, 0), 90, float(width / height), 0.0, 10.0, 0.0, 1.0);

		for (int i = 0; i < nbThread; i++) {
			threads[i] = GetPartPixelsData(i, width, height, widthPart * i, widthPart * i + widthPart, indexImg, cam, world);
			cout << "threads " << i << " parse img x to " << (widthPart * i) << " to " << (widthPart * i + widthPart) << endl;
		}

		std::cout << "Waiting multiThread" << endl;

		for (int i = 0; i < nbThread; i++) {
			threads[i].join();
		}

		auto end = chrono::system_clock::now();

		chrono::duration<double> elapsedSeconds = end - start;

		std::cout << "End multiThread at : " << elapsedSeconds.count() << endl;

		CreateJpg(width, height, 4, indexImg);

		end = chrono::system_clock::now();
		elapsedSeconds = end - start;

		std::cout << "End creation image after : " << elapsedSeconds.count() << " sec" << endl;
	}
}