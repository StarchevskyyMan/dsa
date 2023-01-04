#include "Car.h"
//#include <iostream>

//using namespace std;
// konstruktor:
Car::Car() {
	model	= "";
	brand	= "";
	spz		= "";
	color	= "";
	year	= 0;
	//palivo	= "";
	majitel = 0;
}
void Car::setCar(const string& newCarModel, const string& newCarBrand, const string newCarSpz, const string newCarColor, const int newCarYear,
	/*const string& newCarFuel,*/ const int newCarOwner) {
	model	= newCarModel;
	brand	= newCarBrand;
	spz		= newCarSpz;
	color	= newCarColor;
	year	= newCarYear;
	//palivo	= newCarFuel;
	majitel = newCarOwner;
}
//vytvoreni noveho automobilu
void Car::addNewCar(istream& ins) {
	cout << "vytvarite novy automobil \n";
	cout << "==================================================" <<endl ;
	cout << " zadejte nazev vyrobce: " ;
	getline(ins, brand);
	cout << "==================================================" << endl;
	cout << " zadejte model automobilu: ";
	getline(ins, model);
	cout << "==================================================" << endl;
	cout << " zadejte SPZ automobilu: ";
	getline(ins, spz);
	cout << "==================================================" << endl;
	cout << " zadejte barvu automobilu ";
	getline(ins, color);
	cout << "==================================================" << endl;
	cout << " zadejte rok uvedeni do provozu: ";
	ins >> year;
	cout << "==================================================" << endl;
	cout << " zadejte rodne cislo ridice  bez lomitka: ";
	ins >> majitel;
	cout << "==================================================" << endl;




}
string Car::getBrand() const {
	return brand;

}
string Car::getModel() const {
	return model;
}
string Car::getColor() const {
	return color;
}
string Car::getSpz() const {
	return spz;
}
int Car::getYear() const {
	return year;
}
/*
char Car::getFuel() const {
	return palivo;
}
*/
int Car::getOwner() const {
	return majitel;
}

//
void Car::setBrand(const string& newCarBrand ) {
	brand = newCarBrand;
	

}
void	Car::setModel(const string& newCarModel) {
	model = newCarModel;
}
void	Car::setSpz(const string& newCarSpz) {
	spz = newCarSpz;
}
void	Car::setColor(const string& newCarColor) {
	color = newCarColor;
}
void	Car::setYear(int newCarYear) {
	year = newCarYear;
}
void	Car::setOwner(int newCarOwner) {
	majitel = newCarOwner;
}

/*
void	setFuel(const string& newCarFuel);
*/


void	Car::printCar() const{
	cout << " Znacka: " << brand  << endl;
	cout << " Model:  " << model  << endl;
	cout << " SPZ:    " << spz    << endl;
	cout << " Barva:  " << color  << endl;
	cout << " Rok:    " << year   << endl;
	cout << " Majitel:" << majitel<< endl;

}
//zapise udaje do souboru

void	Car::printCarToFile(ofstream& out) {
	out << brand << " " << model << endl;
	out << spz << endl ;
	out << majitel << endl;
	out << color << endl;
	out << endl;
}

Car::~Car() {

}

//vytvori z docasneho souboru novy objekt auto

istream& operator >> (istream& ins, Car& tempCar)
{
	tempCar.addNewCar(ins);
	return ins;
}



