// pokusny.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

// NakupniParagon.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include "Paragon.h"
#include <list>
//#include "Produkt.h"
//#include <string>


int menu()
{
	printf("Pridat zbozi \t\t [1] \n");
	printf("Odebrat zbozi \t\t [2] \n");
	printf("Vypis nabidku zbozi \t [3] \n");
	printf("Vypis nakupni kosik \t [4] \n");
	printf("Seradit sestupne \t [5] \n");
	printf("Seradit vzestupne \t [6] \n");
	printf("* Spustit DEMO * \t [7] \n");
	printf("KONEC \t\t\t [0]\n\n");

	int choice;
	do
	{
		printf("Zadej volbu: ");
		cin >> choice;
	} while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7);
	return choice;
}

void tiskMenu() {
	cout << "Nabidka:" << endl << "================" << endl;
	cout << "whisky za\t" << 199 << endl;
	cout << "pivo za\t" << 22.5 << endl;
	cout << "mydlo za\t" << 75.5 << endl;
	cout << "praci prasek za\t" << 99 << endl;
	cout << "klobasa za\t" << 23.5 << endl;
	cout << "kotleta za\t" << 78.9 << endl;
	cout << "burt za\t" << 9.9 << endl;
	cout << "steak za\t" << 187.6 << endl;
	cout << "banan za\t" << 9.5 << endl;
	cout << "kiwi za\t" << 12.7 << endl;
	cout << "meloun za\t" << 11.3 << endl;
	cout << "banan za\t" << 33.8 << endl;
	cout << "chleba za\t" << 35 << endl;
	cout << "kobliha za\t" << 9.9 << endl;
	cout << "rohlik za\t" << 3 << endl;
	cout << "chleba za\t" << 35 << endl;
	cout << "kvetak za\t" << 49.9 << endl;
	cout << "patizon za\t" << 14.6 << endl;
	cout << "turin za\t" << 11.9 << endl;
	cout << "rajce za\t" << 9.9 << endl;
	cout << endl;
}

int getIndex(string name) {
	if (name.compare("whisky") == 0) return 0;
	if (name.compare("pivo") == 0) return 0;
	if (name.compare("mydlo") == 0) return 1;
	if (name.compare("praci prasek") == 0) return 1;
	if (name.compare("klobasa") == 0) return 2;
	if (name.compare("kotleta") == 0) return 2;
	if (name.compare("burt") == 0) return 2;
	if (name.compare("steak") == 0) return 2;
	if (name.compare("banan") == 0) return 3;
	if (name.compare("kiwi") == 0) return 3;
	if (name.compare("meloun") == 0) return 3;
	if (name.compare("banan") == 0) return 4;
	if (name.compare("chleba") == 0) return 5;
	if (name.compare("kobliha") == 0) return 5;
	if (name.compare("rohlik") == 0) return 5;
	if (name.compare("chleba") == 0) return 5;
	if (name.compare("kvetak") == 0) return 6;
	if (name.compare("patizon") == 0) return 6;
	if (name.compare("turin") == 0) return 6;
	if (name.compare("rajce") == 0) return 6;
}

float getPrice(string name) {
	if (name.compare("whisky") == 0) return 199;
	if (name.compare("pivo") == 0) return 22.5;
	if (name.compare("mydlo") == 0) return 75.5;
	if (name.compare("praci prasek") == 0) return 99;
	if (name.compare("klobasa") == 0) return 23.5;
	if (name.compare("kotleta") == 0) return 78.9;
	if (name.compare("burt") == 0) return 9.9;
	if (name.compare("steak") == 0) return 187.6;
	if (name.compare("banan") == 0) return 9.5;
	if (name.compare("kiwi") == 0) return 12.7;
	if (name.compare("meloun") == 0) return 11.3;
	if (name.compare("banan") == 0) return 33.8;
	if (name.compare("chleba") == 0) return 35;
	if (name.compare("kobliha") == 0) return 9.9;
	if (name.compare("rohlik") == 0) return 3;
	if (name.compare("chleba") == 0) return 35;
	if (name.compare("kvetak") == 0) return 49.9;
	if (name.compare("patizon") == 0) return 14.6;
	if (name.compare("turin") == 0) return  11.9;
	if (name.compare("rajce") == 0) return 9.9;
}

void add(Paragon* prg) {

	string name;
	float count;

	cout << "Zadej nazev zbozi: ";
	cin >> name;
	cout << "Zadej mnozstvi: ";
	cin >> count;

	prg->addProdukt(name, getPrice(name), count, getIndex(name));

}

void remove(Paragon* prg) {

	string name;
	float count;

	cout << "Zadej nazev zbozi: ";
	cin >> name;
	cout << "Zadej mnozstvi: ";
	cin >> count;
	prg->remProdukt(name, count, getIndex(name));

}



void demo(Paragon prg) {
	//tiskMenu();
	cout << "Vypis prazdneho Paragonu:" << endl;
	prg.printParagon();
	cout << endl << endl;

	// [0:Alkohol, 1:Drogerie, 2:Maso, 3:Nápoje, 4:Ovoce, 5:Potraviny, 6:Zelenina]

	//===================================
	prg.addProdukt("whisky", 199, 1, 0);
	prg.addProdukt("pivo", 22.5, 10, 0);

	prg.addProdukt("mydlo", 75.5, 3, 1);
	prg.addProdukt("praci prasek", 99, 1, 1);

	prg.addProdukt("klobasa", 23.5, 0.56, 2);
	prg.addProdukt("kotleta", 78.9, 1.38, 2);
	prg.addProdukt("burt", 9.9, 2.65, 2);
	prg.addProdukt("steak", 187.6, 0.46, 2);

	prg.addProdukt("banan", 9.5, 1, 3);
	prg.addProdukt("kiwi", 12.7, 3, 3);
	prg.addProdukt("meloun", 11.3, 2, 3);

	prg.addProdukt("banan", 33.8, 0.5, 4);

	prg.addProdukt("chleba", 35, 1, 5);
	prg.addProdukt("kobliha", 9.9, 4, 5);
	prg.addProdukt("rohlik", 3, 15, 5);
	prg.addProdukt("chleba", 35, 2, 5);
	prg.addProdukt("chleba", 39, 3, 5);
	prg.addProdukt("chleba", 170, 1, 5);

	prg.addProdukt("kvetak", 49.9, 1, 6);
	prg.addProdukt("patizon", 14.6, 2, 6);
	prg.addProdukt("turin", 11.9, 1.7, 6);
	prg.addProdukt("rajce", 9.9, 0.6, 6);

	cout << "Vypis Paragonu realneho nakupniho kosiku s osetrenymi duplicitami:" << endl;
	prg.printParagon();
	cout << endl;


	cout << "Serazuji paragon po kategeoriich podle ceny sestupne a vypisuji ho..." << endl;
	prg.sortKatgByAtrDesc();

	cout << "Vypis setrideneho paragonu podle ceny v kategoriich:" << endl;
	prg.printParagon();
	cout << endl;

	cout << "Serazuji paragon po kategeoriich a cenach vzestupne a vypisuji ho..." << endl;
	prg.sortKatgByAtrAsc();
	prg.printParagon();
	cout << endl;

	cout << "Odebírám několik položek (ze zacatku seznamu, z prostred i z konce seznamu)" << endl;
	//zmenseni poctu kusu
	prg.remProdukt("banan", 0.2, 4);	// jedinny prvek
	prg.remProdukt("rajce", 0.2, 6);		// prvni prvek
	prg.remProdukt("chleba", 2, 5);			//posledni prvek
	prg.remProdukt("steak", 0.2, 2);		// prostredni

	//kompletni odebrani polozky z kosiku
	prg.remProdukt("banan", 999, 4);	// jedinny prvek
	prg.remProdukt("rajce", 999, 6);		// prvni prvek
	prg.remProdukt("chleba", 999, 5);			//posledni prvek
	prg.remProdukt("steak", 999, 2);		// prostredni

	cout << "Vypis Paragonu s odebranymi polozkami:" << endl;
	prg.printParagon();
	cout << endl;
}

int main()
{
	Paragon* prg = new Paragon();
	/*
		int choice;
		do
		{
			choice = menu();
			switch (choice)
			{
			case 1:
				add(prg);
				break;
			case 2:
				remove(prg);
				break;
			case 3:
				// print nabidku
				tiskMenu();
				break;
			case 4:
				// print Paragon
				prg->printParagon();
				break;
			case 5:
				prg->sortKatgByAtrAsc();
				break;
			case 6:
				prg->sortKatgByAtrAsc();
				break;
			case 7:
				// DEMO
				demo(*prg);
				break;
			}
		} while (choice != 0);
	*/
	demo(*prg);
	delete prg;
}