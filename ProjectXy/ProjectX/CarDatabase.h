#ifndef CARDATABASE_H
#define CARDATABASE_H

#include "car.h"
#include <iostream>

class CarDatabase
{
public:
	CarDatabase();
	void addCar(const Car& newCar);
	void printall() const;
	void editCarAt(int index);
	Car  getCar(int index) const;
	void printCarInfo() const;
	void saveToFile(ofstream& out);
	~CarDatabase();
private:
	void make_bigger();
	Car* carPtr;
	int capacity, used;
};
#endif // !BOOKDATABASE_H