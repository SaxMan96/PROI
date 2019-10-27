#pragma once
#include "Data.h"

using namespace std;

class Zdarzenie
{
public:
	string nazwa;
	Data data;

	Zdarzenie();					// Konstruktor
	static Zdarzenie wczytaj();		// Metoda statyczna
	~Zdarzenie();					// Destruktor
	void wczytajZKlaw(Data*);
	void wczytajZPliku(string, int);
	void zapiszDoPliku(ofstream&);
	void wyswietl();
	friend bool operator < (const Zdarzenie &, const Zdarzenie &);

};
