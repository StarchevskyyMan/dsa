#ifndef CAR
#define CAR


#include<iostream>
#include<string>
#include<fstream>
// bez std namespace je problém použít string
using namespace std;



class Car
{
	friend istream& operator>>(istream& ins, Car& tempCar);

public:
	Car();
	void setCar(const string& newCarModel, const string& newCarBrand, const string newCarSpz, const string newCarColor, const int newCarYear, const int newCarOwner);
	//void	setCar( const string& newCarModel, const string& newCarBrand, const string& newCarSpz, const string& newCarColor, const int newCarYear,
	//const string& newCarFuel, const int newCarOwner);
	void	addNewCar(istream& ins);
	string	getModel() const;
	string	getBrand() const;
	string	getSpz() const;
	string	getColor() const;
	int		getYear() const;
	int		getOwner() const;
	//string	getFuel() const;
	void	setModel(const string& newCarModel);
	void	setBrand(const string& newCarBrand);
	void	setSpz(const string& newCarSpz);
	void	setColor(const string& newCarColor);
	void	setYear(int newCarYear);
	void	setOwner(int newCarOwner);
	//void	setFuel(const string& newCarFuel );
	void	printCar() const;
	void	printCarToFile(ofstream& out);
	~Car();

private: 
	
	string model;
	string brand;
	string spz;
	string color;
	int year;
	//char palivo;
	int majitel;







};

#endif // !car

