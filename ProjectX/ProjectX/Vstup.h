#include "Car.h"
#include "CarDatabase.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
//odsud by se mìly naèíst data 
const char AUTA_DATA[] = "auta_data.txt";

void createCarList(ifstream& infile, CarDatabase& Database)
{


	Car tempCar;
	string model;
	string brand;
	string spz;
	string color;
	int year;
	
	int majitel;
	

	infile >> spz;

	while (spz != "END")
	{
		if (infile.peek() == ' ')
			infile.ignore();
		getline(infile, brand);
		getline(infile, model);
		getline(infile, color);


		infile >> year >> majitel ;


		tempCar.setCar(brand, model, spz, color, year, majitel);
		Database.addCar(tempCar);

		infile >> spz;
	}
}
//otevre soubor ziska z nej informace a ulozi je do pole, ktere si vytvori 
void readCarData(CarDatabase& Database)
{
	ifstream infile;

	infile.open(AUTA_DATA);
	
	if (!infile)
	{
		cerr << "Soubor neexistuje" << endl;
		system("Pause");
		exit(1);
	}

	createCarList(infile, Database);

	infile.close();
}
