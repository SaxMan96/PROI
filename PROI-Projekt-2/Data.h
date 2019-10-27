#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>  //setw()
#include <stdio.h>  //
#include <cctype>   //isdigit()
#include "Funkcje.h"
#define krotkiMiesiac 30
#define dlugiMiesiac 31
#define luty 28
#define lutyPrzest 29

using namespace std;

class Data
{
public:
	int rok;
	int miesiac;
	int dzien;
	int godzina;
	int minuta;
public:
	Data();		// Konstruktor

	void pobierzDate();
	void wczytajZKlaw(Data *);
	void wczytajZPliku(string, int);
	void zapiszDoPliku(ofstream &);
	void wyswietl();
	friend Data dodaj(const Data &, int);
	Data& operator=(const Data&);     // Operator przypisania
	friend bool operator < (const Data &, const Data &);
};
