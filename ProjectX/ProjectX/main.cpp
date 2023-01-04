
#include <iostream>
#include "CarDatabase.h"
#include "Vstup.h"
#include "car.h"

void displayMenu();
void processChoice(CarDatabase& database);
using namespace std;
int main() {

	CarDatabase Database;

	//readCarData(Database);
	displayMenu();
	processChoice(Database);

	cout << endl;

	system("pause");
	
	


	return 0;
}

void displayMenu()
{
	cout << "\n*** Registr vozidel: ***\n";
	cout << "\nZvolte si moznosti\n\n";
	cout << "    1: Pridat nove auto " << endl;
	cout << "    2: vypsat vsechna auta " << endl;
	cout << "    3: Upravit udaje" << endl;
	cout << "    4: Ulozit do souboru" << endl;
	cout << "    5: konec" << endl;
}

void processChoice(CarDatabase& database)
{
	string stringEdit = "";
	int intEdit, choice;
	Car xxx;
	ofstream out;
	out.open("student_test.txt");

	cout << "\nEnter your choice: ";
	cin >> choice;
	cout << endl;

	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			cout << "1. Pridat nove auto" << endl;
			cin.ignore(1, ' ');
			cin >> xxx;
			database.addCar(xxx);

			break;
		case 2:
			database.printall();

			break;

		case 3:
			database.printCarInfo();
			cout << "Zvolte, ktery index chcete upravit ";
			cin >> intEdit;
			database.editCarAt(--intEdit);

			break;

		case 4:
			database.saveToFile(out);

			break;
		default:
			cout << "Neplatna Volba" << endl;

			break;
		}

		system("Pause");
		system("CLS");
		displayMenu();

		cout << "\n Zadejte svoji Volbu: ";
		cin >> choice;
		cout << endl;
	}

}

