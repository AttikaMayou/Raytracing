#pragma once

#include <fstream>

#include "GenerationTool.h"


class Menu {
public:
	Menu();
	~Menu();
	Menu(const Menu& copy);
	Menu& operator=(const Menu& m);

	bool CheckIfFileExists(string filename);
	
	void ChooseSceneName();
	void ChooseOutputFilename();
	void ChooseResolution();
	void ChooseNbThread();
	void ChooseNbImage();
	bool ConfirmParameters();

	void StartMainMenu();
	
private:
	int width;
	int height;
	int nbThread;
	int nbImage;

	string inputSceneName;
	string outputImgName;
};