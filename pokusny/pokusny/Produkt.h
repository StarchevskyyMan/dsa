#pragma once
#include <string>


class Produkt
{
private:
    std::string Nazev;
    float jendCena;
    float Mnozstvi;
    int katgIdx; // 0-7, index pole
    // int maxMnozstvi; // kvuli omezeni poctu produktu ktere lze na 1 parag. koupit
    Produkt* pNext;
    Produkt* pPrev;

public:
    Produkt(std::string name, float price, float count, int idx) {
        Nazev = name;
        Mnozstvi = count;
        katgIdx = idx;
        jendCena = price;
        pNext = nullptr;
        pPrev = nullptr;
    }

    ~Produkt() { };

    std::string getName() {
        return Nazev;
    }

    void setCount(float count) {
        Mnozstvi = count;
    }

    float getCount() {
        return Mnozstvi;
    }

    Produkt* getNext() {
        return pNext;
    }

    void setNext(Produkt* next) {
        pNext = next;
    }

    Produkt* getPrev() {
        return pPrev;
    }

    void setPrev(Produkt* prev) {
        pPrev = prev;
    }

    float getPrice() {
        return jendCena * Mnozstvi;
    }

    float getJednPrice() {
        return jendCena;
    }

    void setPrice(float newPrice) {
        jendCena = newPrice;
    }
};