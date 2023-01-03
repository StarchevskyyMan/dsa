#include "CarDatabase.h"

CarDatabase::CarDatabase()
{
	used = 0;
	capacity = 5;
	carPtr = new Car[capacity];
}

void CarDatabase::addCar(const Car& newCar)
{
	if (used >= capacity)
	{
		cout << "Database is full, Doubling Size. . ." << endl;
		make_bigger();
	}
	carPtr[used] = newCar;
	used++;
}
void CarDatabase::printall() const
{
	for (int i = 0; i < used; i++)
		carPtr[i].printCar();
}

void CarDatabase::editCarAt(int index)
{

	cout << "Co chcete upravit ?" << endl;
	cout << " 1. Barva" << endl;
	cout << " 2. Majitel" << endl;
	cout << " 3. SPZ" << endl;
	cout << " 4. Odstranit záznam" << endl;
	cout << " 5. Zpatky do menu." << endl;
	//cout << " 5. Znaèka" << endl;
	//cout << " 6. Model" << endl;
	//cout << " 7. Rok" << endl;

	int choice, intEdit = 0;
	string stringEdit;

	cout << "\n Cislo volby: ";
	cin >> choice;
	cout << endl;

	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			cout << "Zadejte novou barvu vozu" << endl;
			cin.ignore(1, ' ');
			getline(cin, stringEdit);
			carPtr[index].setColor(stringEdit);

			break;

		case 2:
			cout << "zadejte rodne cislo noveho majitele:" << endl;
			cin.ignore(1, ' ');
			cin >> intEdit;
			carPtr[index].setOwner(intEdit);

			break;

		case 3:
			cout << "Zadejte novou SPZ" << endl;
			cin.ignore(1, ' ');
			getline(cin, stringEdit);
			carPtr[index].setSpz(stringEdit);

			break;
			//nefunguje
		case 4:
			cout << "odstranit zaznam" << endl;
			cin.ignore(1, ' ');
			getline(cin, stringEdit);
			// carPtr[index].funkce delete(stringEdit);

			break;

		default:
			cout << "Neplatna volba:" << endl;
			cout << "======================" << endl;

			break;
		}

		cout << endl;
		system("Pause");
		cout << endl;
		cout << "Co chcete upravit ?" << endl;
		cout << " 1. Barva" << endl;
		cout << " 2. Majitel" << endl;
		cout << " 3. SPZ" << endl;
		cout << " 4. Odstranit záznam" << endl;
		cout << " 5. Zpatky do menu." << endl;
		cout << "======================" << endl;
		cout << "\n Cislo volby: ";
		cin >> choice;
		cout << endl;
	}

}

Car CarDatabase::getCar(int index) const
{
	return carPtr[index];
}

void CarDatabase::printCarInfo() const
{
	for (int i = 0; i < used; i++)
		cout << i + 1 << ". " << carPtr[i].getSpz() << endl;
		//zbyle udaje o autu
}

void CarDatabase::saveToFile(ofstream& out)
{
	if (used == 0)
		cerr << "Zde neni nic noveho k ulozeni" << endl;
	else
	{
		for (int i = 0; i < used; i++)
			carPtr[i].printCarToFile(out);

		out << endl;
		out << "END";
	}

}

void CarDatabase::make_bigger()
{
	Car* temp;
	int xy = capacity * 2;
	temp = new Car[xy];
	for (int i = 0; i < used; i++)
		temp[i] = carPtr[i];
	delete[] carPtr;
	carPtr = temp;
	capacity *= 2;
}

CarDatabase::~CarDatabase()
{

}