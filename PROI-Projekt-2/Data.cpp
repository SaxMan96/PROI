#include "Data.h"

class Terminarz;

Data::Data() :
	rok(2016),
	miesiac(1),
	dzien(1),
	godzina(0),
	minuta(0)
{
	//cout << "Konstrunktor data...\n";
}
Data& Data::operator=(const Data& prawy)
{
	//cout << "operator przypisania = terminarz\n";
	this->rok = prawy.rok;
	this->miesiac = prawy.miesiac;
	this->dzien = prawy.dzien;
	this->godzina = prawy.godzina;
	this->minuta = prawy.minuta;
	return *this;
}
void Data::wczytajZKlaw(Data * dzisiaj)
{
	string linia;       //Zmienna do wczytywania ze strumienia
	int czy = 1;          //Flaga

	while (czy)
	{
		czy = 0;
		cout << "Podaj date zdarzenia w formacie DD MM\n";

		getline(cin, linia, ' ');
		dzien = atoi(linia.c_str());

		if (dzien<1 || dzien>31)
			czy = 1;

		getline(cin, linia);
		miesiac = atoi(linia.c_str());
		if (miesiac<1 || miesiac>12)
			czy = 1;

		cout << "Podaj rok zdarzenia RRRR (Domyslnie " << dzisiaj->rok << "):\n";

		getline(cin, linia);
		if (linia == "")
			rok = dzisiaj->rok;
		else
			rok = atoi(linia.c_str());

		//Warunki poprawnosci
		if (rok<0)
		{
			cout << "To teminarz na 2016 rok. Podaj sensowna date.";
			czy = 1;
			get();
			clrscr();
			continue;
		}

		if ((miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) && dzien>30)
			czy = 1;
		if ((miesiac == 2 && dzien>28) || (miesiac == 2 && dzien>29 && rok % 4 == 0))
			czy = 1;
		if (czy)
		{
			cout << "Nie ma takiej daty.\n";
			clrscr();
		}
	}
	czy = 1;
	while (czy)
	{
		czy = 0;
		cout << "Podaj godzine w formacie HH MM \n";

		getline(cin, linia, ' ');
		godzina = atoi(linia.c_str());
		if (godzina<0 || godzina>23)
			czy = 1;

		getline(cin, linia, '\n');
		minuta = atoi(linia.c_str());
		if (godzina<0 || godzina>59)
			czy = 1;
		if (czy)
		{
			cout << "Nie ma takiej godziny.\n";
			clrscr();
		}
	}
}
void Data::zapiszDoPliku(ofstream & plik)
{
	plik << rok << "\n";
	plik << miesiac << "\n";
	plik << dzien << "\n";
	plik << godzina << "\n";
	plik << minuta << "\n";
	plik.flush();
}

void Data::wyswietl()
{
    cout<<"\t";
    if(dzien<10)
        cout<<"0";
	cout << dzien << " ";
	if(miesiac<10)
        cout<<"0";
	cout << miesiac << " ";
	cout << rok << " ";
	if(godzina<10)
        cout<<"0";
	cout << godzina << ":";
	if(minuta<10)
        cout<<"0";
	cout << minuta << endl;
}
void Data::wczytajZPliku(string linia, int nr_linii)
{
	switch (nr_linii % 6)
	{
	case 1: rok = atoi(linia.c_str()); break;
	case 2: miesiac = atoi(linia.c_str()); break;
	case 3: dzien = atoi(linia.c_str()); break;
	case 4: godzina = atoi(linia.c_str()); break;
	case 5: minuta = atoi(linia.c_str()); break;
	}
}
void Data::pobierzDate()
{
	time_t czas;
	struct tm * ptr;
	time(&czas);
	ptr = localtime(&czas);
	//char * dzisiaj = asctime(ptr);
	rok = ptr->tm_year + 1900;
	miesiac = ptr->tm_mon + 1;
	dzien = ptr->tm_mday;
	godzina = ptr->tm_hour;
	minuta = ptr->tm_min;
}
Data dodaj(const Data & staraData, const int ile)
{
	int dniMiesiaca;
	Data data = staraData;
	if (data.miesiac == 4 || data.miesiac == 6 || data.miesiac == 9 || data.miesiac == 11)
		dniMiesiaca = krotkiMiesiac;

	else if (data.miesiac == 2 && data.rok % 4 != 0)
		dniMiesiaca = luty;

	else if (data.miesiac == 2 && data.rok % 4 == 0)
		dniMiesiaca = lutyPrzest;

	else
		dniMiesiaca = dlugiMiesiac;

	if (ile + data.dzien>dniMiesiaca)
	{
		data.miesiac++;
		data.dzien += ile - dniMiesiaca;
	}
	else
		data.dzien += ile;
	return data;
}
bool operator < (const Data & a, const Data & b)
{
	/*cout<<"\nJestem w < data\n";
	Data d;
	d=a;
	d.wyswietl();
	d=b;
	d.wyswietl();*/
	if (a.rok<b.rok)
		return true;

	else if (a.rok>b.rok)
		return false;

	if (a.miesiac<b.miesiac)
		return true;

	else if (a.miesiac>b.miesiac)
		return false;

	if (a.dzien<b.dzien)
		return true;

	else if (a.dzien>b.dzien)
		return false;

    if (a.godzina<b.godzina)
		return true;

	else if (a.godzina>b.godzina)
        return false;

    if (a.minuta<b.minuta)
		return true;

	else if (a.minuta>b.minuta)
        return false;

	return false;
}
