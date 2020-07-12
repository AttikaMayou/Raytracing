#include "Menu.h"

#define é char(130)
#define à char(133)
#define ê char(136)
#define è char(138)

Menu::Menu() {
	width = 0;
	height = 0;
	nbThread = 0;
	nbImage = 0;

	inputSceneName = "";
	outputImgName = "";
}

Menu::~Menu() {}

Menu::Menu(const Menu& copy)
{
	width = copy.width;
	height = copy.height;
	nbThread = copy.nbThread;
	nbImage = copy.nbImage;

	inputSceneName = copy.inputSceneName;
	outputImgName = copy.outputImgName;
}

Menu& Menu::operator=(const Menu& m)
{
	width = m.width;
	height = m.height;
	nbThread = m.nbThread;
	nbImage = m.nbImage;

	inputSceneName = m.inputSceneName;
	outputImgName = m.outputImgName;
	return *this;
}

bool Menu::CheckIfFileExists(string filename) {
	ifstream f(filename.c_str());
	return f.good();
}

void Menu::ChooseSceneName() {
	bool closeMenu = false;
	
	do {
		cout << "Choissisez votre scene " << à << " charg" << é << " (ne tapez rien pour la sc" << è << "ne par d" << é << "faut)" << endl;
		cin >> inputSceneName;

		cout << (inputSceneName == "rien") << endl;
		if (inputSceneName == "" || inputSceneName == "rien") {
			inputSceneName = "";
		} else if (!CheckIfFileExists(inputSceneName)) {
			cout << "Fichier non trouv" << é << endl;
			continue;
		}

		closeMenu = true;
	} while (!closeMenu);
}

void Menu::ChooseOutputFilename() {
	bool closeMenu = false;

	do {
		cout << "Choissisez un nom pour le fichier de sortie" << endl;
		cin >> outputImgName;

		if (outputImgName == "") {
			cout << "Nom de fichier incorrecte" << endl;
			continue;
		}

		closeMenu = true;
	} while (!closeMenu);
}

void Menu::ChooseResolution() {
	bool closeMenu = false;
	
	do {
		cout << "Choissisez votre r" << é << "solution (Largeur Hauteur)" << endl;
		cin >> width;
		cin >> height;

		if (width < 50 || height < 50) {
			cout << "Param" << è << "tre de r" << é << "solution trop petit, ils doivent " << ê << "tre au moins à 50 pixels" << endl;
			continue;
		}

		closeMenu = true;
	} while (!closeMenu);
}

void Menu::ChooseNbThread() {
	bool closeMenu = false;

	do {
		cout << "Choissisez le nombre de thread : " << endl;
		cin >> nbThread;

		if (nbThread < 1) {
			cout << "Nombre de thread ne peut pas " << ê << "tre inf" << é << "rieur " << à << " 1" << endl;
			continue;
		}

		closeMenu = true;
	} while (!closeMenu);
}

void Menu::ChooseNbImage() {
	bool closeMenu = false;

	do {
		cout << "Choissisez le nombre d'images g" << é << "n" << é << "r" << é << "s" << endl;
		cin >> nbImage;

		if (nbImage < 1) {
			cout << "Nombre d'image ne peut pas " << ê << "tre inf" << é << "rieur " << à << " 1" << endl;
			continue;
		}

		closeMenu = true;
	} while (!closeMenu);
}

bool Menu::ConfirmParameters() {
	char choice;

	cout << "Largeur " << width << " - Hauteur : " << height << endl;
	cout << "Nombre de thread : " << nbThread << " - nombre d'image : " << nbImage << endl;
	cout << "Voulez-vous confirmez ces param" << è << "tres ? (Y/N)" << endl;
	cin >> choice;

	if (choice == 'Y' || choice == 'y') {
		return true;
	}

	return false;
}

void Menu::StartMainMenu() {
	do {
		ChooseSceneName();
		
		ChooseOutputFilename();

		ChooseResolution();

		ChooseNbThread();

		ChooseNbImage();
	} while (!ConfirmParameters());

	GenerationTool generationTool(inputSceneName, outputImgName, width, height, nbThread, nbImage);
	generationTool.StartImageCreation();
}