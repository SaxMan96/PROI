#ifndef PREPROCESOR
#define PREPROCESOR

#include "Drzewo.h"
#include <string>
#include <sstream>

class Preprocesor
{
    Drzewo< string , string > drzewo;    //Struktura przechowujaca slownik definow ktory zostanie uzyty przy przerobce tekstu
    string tekst;

public:
    Preprocesor();
    ~Preprocesor();
    void wczytaj();
    void wyswietl()const;
    void podmien();
    void zapisz();
};


#endif // PREPROCESOR
