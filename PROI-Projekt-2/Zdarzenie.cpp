#include "Zdarzenie.h"

Zdarzenie::Zdarzenie()
{
	//cout << "Konstrunktor domyslny zdarzenie\n";
	nazwa = "Zdarzenie";
	data.dzien = 1;
	data.miesiac = 1;
	data.rok = 2016;
	data.minuta = 0;
	data.godzina = 0;
}
void Zdarzenie::wczytajZKlaw(Data * dzisiaj)
{
	string linia;
	Zdarzenie temp;
	cout << "Podaj nazwe zdarznenia: \n";
	cin.ignore();
	getline(cin, linia);
	if(linia == "")
		nazwa = "Zdarzenie";
    else
        nazwa = linia;
    cout<<"Nazwa zdarzenie:   "<<nazwa;
	data.wczytajZKlaw(dzisiaj);
}
Zdarzenie::~Zdarzenie()
{
	//cout << "Destruktor Zdarzenie\n";
}
void Zdarzenie::zapiszDoPliku(ofstream & plik)
{
	plik << nazwa << "\n";
	data.zapiszDoPliku(plik);
	plik.flush();
}

void Zdarzenie::wyswietl()
{
	cout << nazwa << endl;
	data.wyswietl();
}
void Zdarzenie::wczytajZPliku(string linia, int nr_linii)
{
	if (nr_linii == 0)
		nazwa = linia;
	else
		data.wczytajZPliku(linia, nr_linii);
	switch (nr_linii % 6)
	{
	case 0: nazwa = linia;                       break;
	case 1: data.rok = atoi(linia.c_str()); break;
	case 2: data.miesiac = atoi(linia.c_str()); break;
	case 3: data.dzien = atoi(linia.c_str()); break;
	case 4: data.godzina = atoi(linia.c_str()); break;
	case 5: data.minuta = atoi(linia.c_str()); break;
	}
}
bool operator < (const Zdarzenie & a, const Zdarzenie & b)
{
	return a.data<b.data;
}
