#pragma once
#include "Produkt.h"
#include <string>

using namespace std;

class Paragon
{
private:
    float sumCena;
    Produkt* arrKategorie[7];

public:
    // konstruktor
    Paragon() {
        Produkt* arrKategorie[7] = { NULL };
    }
    ~Paragon();


};