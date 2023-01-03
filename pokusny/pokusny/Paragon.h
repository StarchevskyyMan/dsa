#pragma once
#include "Produkt.h"
#include <string>

using namespace std;
const char* Kategorie[] = { "Alkohol", "Drogerie", "Maso", "Napoje", "Ovoce", "Potraviny", "Zelenina" };

class Paragon
{
private:
    float sumCena;
    Produkt* arrKategorie[7];
    // int* arr;

public:
    // konstruktor
    Paragon() {
        for (int i = 0; i < 7; i++) {
            arrKategorie[i] = nullptr;
        }
        sumCena = 0.0;
    }

    friend class Produkt;

    ~Paragon() {
        ;
    }


    // === INSERT ==================================================
    void addProdukt(std::string name, float price, float count, int idx) {
        // Pokud Idx = nullptr; tzn. Kategore jeste nema zboziclass Produkt
/*
    private:
        std::string Nazev;
        float jendCena;
        float Mnozstvi;
        int katgIdx; // 0-7, index pole
        // int maxMnozstvi; // kvuli omezeni poctu produktu ktere lze na 1 parag. koupit
        Produkt *pNext;
        Produkt *pPrev;
*/


        if (arrKategorie[idx] == nullptr) {
            Produkt* prd = new Produkt(name, price, count, idx);
            arrKategorie[idx] = prd; // pole na spravnem indexu ma ukazatel na prvni Produkt
        }
        // Pukud uz mame prvni produkt, projdem cely DLList a pridame na konec
        else if (find(name, idx) == nullptr) {
            Produkt* tmp = arrKategorie[idx]; // Ukazatel na prvni Prodkut v seznamu
            while (tmp->getNext() != nullptr) {
                tmp = tmp->getNext();
            }
            Produkt* prd = new Produkt(name, price, count, idx);
            prd->setPrev(tmp);
            tmp->setNext(prd);
        }
        else {
            find(name, idx)->setCount(find(name, idx)->getCount() + count);
        }
    }

    // === REMOVE ====================================================
    void remProdukt(std::string name, float count, int idx) {
        if (find(name, idx) == nullptr) {
            cout << "Uvedene zbozi neni v nakupnim kosiku...";
            return;
        }

        Produkt* tmp = find(name, idx);

        if (tmp->getCount() > count) { // jeste nejake kusy v kosiku zbydou
            tmp->setCount(tmp->getCount() - count);

        }
        else {  // odebiram vsechny kusy, nebo dokonce vic kusu, nez kolik mam v kosiku
            if (arrKategorie[idx]->getNext() == nullptr) {
                arrKategorie[idx] = nullptr;
                delete tmp;
            }
            else if (tmp == arrKategorie[idx]) { // odebiram prvni prvek v seznamu
                arrKategorie[idx] = arrKategorie[idx]->getNext();
                arrKategorie[idx]->setPrev(nullptr);
                delete tmp;
            }
            else if (tmp->getNext() == nullptr) { // modebiram posledni prvek
                tmp->getPrev()->setNext(nullptr);
                delete tmp;
            }
            else {  //odebiram prvek nekde z prostredka
                tmp->getPrev()->setNext(tmp->getNext());
                tmp->getNext()->setPrev(tmp->getPrev());
                delete tmp;
            }
        }
    }

    // === SEARCH =======================================
    Produkt* find(string name, int idx) {
        // prazdnz seznam? vracim NULL!
        if (arrKategorie[idx] == nullptr) {
            return nullptr;
        }

        Produkt* tmp = arrKategorie[idx]; // Ukazatel na prvni Prodkut v seznamu
        while (tmp != nullptr) {
            if (tmp->getName().compare(name) == 0)
                return tmp;
            tmp = tmp->getNext();
        }
        return tmp;
    }


    // === SELECT SORT SESTUPNE =======================================
    void sortKatgByAtrDesc() {

        Produkt* separator = nullptr;   // ukazuje na zacatek nesetrideny casti
        Produkt* ptr = nullptr;         // aktualne porovnavanz prvek
        Produkt* min = nullptr;         // prozatimni nejmensi v aktualnim pruchodu nesetrizenou casti
//        int debug = 0; //debugging

        for (int i = 0; i < 7; i++) { // Iterace pres Kategorie a bude SelectSort

//            debug = 0;
            // test na prazdny nebo jednoprvkovy seznam
            if (arrKategorie[i] == nullptr) continue;
            if (arrKategorie[i]->getNext() == nullptr) continue;

            // inicializace csech pomocnych pointeru na celo seznamu
            min = arrKategorie[i];
            ptr = arrKategorie[i];
            separator = arrKategorie[i];

            while (separator != nullptr) { // dokud nesetridim cele pole = pocatek nesetridene casti neni na uplnem konci seznamu
//              debug++;
                min = separator;
                ptr = separator;

                // ukazatel min nastavim na minimalni prvek v nesetrizene casti (tzn. od separatoru do konce)
                while (ptr != nullptr) {

                    if (min->getPrice() > ptr->getPrice()) {
                        min = ptr;  // min je ted nejmesi prvek v LinkedListu
                    }
                    ptr = ptr->getNext();
                }

                //cout << debug << ". pruchod - min:" << min->getPrice() << endl;

                if (min != arrKategorie[i]) {   //nejmensi neni hned prvni prvek. Prvek posunu na zacatek pole
                    if (min->getNext() == nullptr) {    // nejmensi je posledni prvek

                        if (separator == min) {
                            separator = min->getNext();
                        }
                        min->getPrev()->setNext(nullptr);
                        min->setNext(arrKategorie[i]);
                        min->getNext()->setPrev(min);
                        min->setPrev(nullptr);
                        arrKategorie[i] = min;
                    }
                    else {  // nejmensi je prvek nekde uprosted
                        if (separator == min) {
                            separator = min->getNext();
                        }
                        min->getPrev()->setNext(min->getNext());
                        min->getNext()->setPrev(min->getPrev());

                        min->setNext(arrKategorie[i]);
                        min->getNext()->setPrev(min);
                        arrKategorie[i] = min;
                    }
                }
                else {
                    separator = separator->getNext(); // zmensim nesetridenou cast
                }
            } // konec trideni aktualniho seznamu
        } // konec for 0..6
    }

    // === SELECT SORT VZESTPNE =========================================================================
    void sortKatgByAtrAsc() {
        Produkt* separator = nullptr;   // ukazuje na zacatek nesetrideny casti
        Produkt* ptr = nullptr;         // aktualne porovnavanz prvek
        Produkt* max = nullptr;         // prozatimni nejmensi v aktualnim pruchodu nesetrizenou casti
//        int debug = 0; //debugging

        for (int i = 0; i < 7; i++) { // Iterace pres Kategorie a bude SelectSort

//            debug = 0;
            // test na prazdny nebo jednoprvkovy seznam
            if (arrKategorie[i] == nullptr) continue;
            if (arrKategorie[i]->getNext() == nullptr) continue;

            // inicializace csech pomocnych pointeru na celo seznamu
            max = arrKategorie[i];
            ptr = arrKategorie[i];
            separator = arrKategorie[i];

            while (separator != nullptr) { // dokud nesetridim cele pole = pocatek nesetridene casti neni na uplnem konci seznamu
//              debug++;
                max = separator;
                ptr = separator;

                // ukazatel max nastavim na maximalni prvek v nesetrizene casti (tzn. od separatoru do konce)
                while (ptr != nullptr) {

                    if (max->getPrice() < ptr->getPrice()) {
                        max = ptr;  // max je ted nejvetsi prvek v LinkedListu
                    }
                    ptr = ptr->getNext();
                }

                //cout << debug << ". pruchod - max:" << max->getPrice() << endl;

                if (max != arrKategorie[i]) {   //nejvetsii neni hned prvni prvek. Prvek posunu na zacatek pole
                    if (max->getNext() == nullptr) {    // nejvetsi je posledni prvek

                        if (separator == max) {
                            separator = max->getNext();
                        }
                        max->getPrev()->setNext(nullptr);
                        max->setNext(arrKategorie[i]);
                        max->getNext()->setPrev(max);
                        max->setPrev(nullptr);
                        arrKategorie[i] = max;
                    }
                    else {  // nejvetsi je prvek nekde uprosted
                        if (separator == max) {
                            separator = max->getNext();
                        }
                        max->getPrev()->setNext(max->getNext());
                        max->getNext()->setPrev(max->getPrev());

                        max->setNext(arrKategorie[i]);
                        max->getNext()->setPrev(max);
                        arrKategorie[i] = max;
                    }
                }
                else {
                    separator = separator->getNext(); // zmensim nesetridenou cast
                }
            } // konec trideni aktualniho seznamu
        } // konec for 0..6
    }

    // === CENA JEDNE KATEGORIE =========================================================
    float getSumCenaKat(int idx) {
        float sum = 0.0;
        Produkt* prd = arrKategorie[idx];
        while (prd != nullptr) {
            sum += prd->getPrice();
            prd = prd->getNext();
        }
        return sum;
    }

    // === CENA KOMPLET ==================================================================
    float getSumCena() {
        float sum = 0.0;
        for (int i = 0; i < 7; i++) {
            sum += getSumCenaKat(i);
        }
        return sum;
    }

    // === TISK ===========================================================================
    void printParagon() {
        Produkt* prd = nullptr;

        for (int i = 0; i < 7; i++) {

            if (arrKategorie[i] != nullptr) {
                cout << Kategorie[i] << ":" << endl;

                prd = arrKategorie[i];
                while (prd != nullptr) {
                    cout <<
                        "\t[" << prd->getName() <<
                        "\t\t(" << prd->getCount() << " ks po " << prd->getJednPrice() <<
                        " CZK)\t: celkem = " <<
                        prd->getPrice() << " CZK ]" << endl;
                    prd = prd->getNext();
                }
                cout << endl;
            }
            else {
                // cout << "..." << endl;
            }
        }
        cout << "CENA CELKEM = " << getSumCena() << endl;
        cout << "==========================================================================" << endl;
    }
};