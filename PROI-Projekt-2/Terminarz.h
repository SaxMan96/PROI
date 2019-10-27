#pragma once
#include <vector>
#include <algorithm>
#include "Zdarzenie.h"

using namespace std;

class Terminarz
{

	vector<Zdarzenie> tablicaZdarzen;
	vector<Zdarzenie> tablicaZdarzendo;
	Data* dzisiaj;

public:

	Terminarz();                                // Konstruktor
	Terminarz(Terminarz&);						// Konstruktor kopiujacy
	Terminarz& operator=(const Terminarz&);     // Operator przypisania

	void wczytajZKlaw();
	void wczytajZPliku();
	void zapiszDoPliku();
	void wyswietl();
	void wyswietlDzisiaj();
	void wyswietlDo(int);
	void wyswietlDoUsuwania();
};
