#include "Terminarz.h"

Terminarz::Terminarz()
{
	//cout << "Konstrunktor domyslny Terminarz\n";
	dzisiaj = new Data;
	dzisiaj->pobierzDate();
};

Terminarz& Terminarz::operator=(const Terminarz& prawy)
{
	//cout << "operator przypisania = terminarz\n";
	tablicaZdarzen = prawy.tablicaZdarzen;
	tablicaZdarzendo = prawy.tablicaZdarzendo;
	dzisiaj = prawy.dzisiaj;
	return *this;
}

Terminarz::Terminarz(Terminarz & temp)
{
	//cout << "Konstrunktor kopiujacy terminarz\n";
	tablicaZdarzen = temp.tablicaZdarzen;
	tablicaZdarzendo = temp.tablicaZdarzendo;
	dzisiaj = temp.dzisiaj;
}

void Terminarz::wczytajZKlaw()
{
	Zdarzenie x;
	x.wczytajZKlaw(dzisiaj);
	bool czy;
	while (1)
	{
		cout << "<0> Zdarzenie ma konkretny termin\n<1> Zadanie powinno byc wykonane do danego terminu\n";
		cin >> czy;
		if (cin.good())
			break;
		cout << "Zly wybor.\nNacisnij Enter...";
		cin.clear();
		get();
		clrscr();
	}
	if (czy)
	{
		tablicaZdarzendo.push_back(x);
		sort(tablicaZdarzendo.begin(), tablicaZdarzendo.end());
	}
	else
	{
		tablicaZdarzen.push_back(x);
		sort(tablicaZdarzen.begin(), tablicaZdarzen.end());
	}
	cout<<"Wczytano pomyslnie.";
	get();
	clrscr();
}

void Terminarz::wczytajZPliku()
{
	//Czyszcze terminarz przed wczytaniem pliku

	tablicaZdarzen.erase(tablicaZdarzen.begin(), tablicaZdarzen.end());
	tablicaZdarzendo.erase(tablicaZdarzendo.begin(), tablicaZdarzendo.end());

	ifstream plik;              //Zmienna do ktorej wczytuje plik Terminarz.txt
	plik.open("Terminarz.txt"); //Otwieram plik

	if (!plik.good())      //Sprawdzam czy otwieranie sie powiodlo
	{
		cout << "Plik nie istnieje!";
		return;
	}
	int liczbaZdarzen;      //Liczba zdarzen do wczytania
	int liczbaZdarzenDo;    //Liczba zadan do wczytania
	int czy;                //licznik

	Zdarzenie zdarzenie;    //Obiekt pomocniczy

	string linia;           //Zmienna do ktorej wczytuje kolejne linijki pliku
	int nr_linii;           //Zmienna pomocnicza przy poruszaniu sie po tekscie

	getline(plik, linia);
	liczbaZdarzen = atoi(linia.c_str());      //Wczytuje liczbe zdarzen
	getline(plik, linia);
	liczbaZdarzenDo = atoi(linia.c_str());    //Wczytuje liczbe zadan

											  //Wczytywanie tablicy zdarzen
	for (; liczbaZdarzen; --liczbaZdarzen)
	{
		for (czy = 0, nr_linii = 0; getline(plik, linia) && czy<5; ++czy, ++nr_linii)
			zdarzenie.wczytajZPliku(linia, nr_linii);
		tablicaZdarzen.push_back(zdarzenie);
	}
	//Wczytywanie tablicy zdarzen do
	for (; liczbaZdarzenDo; --liczbaZdarzenDo)
	{
		for (czy = 0, nr_linii = 0; getline(plik, linia) && czy<5; ++czy, ++nr_linii)
			zdarzenie.wczytajZPliku(linia, nr_linii);
		tablicaZdarzendo.push_back(zdarzenie);
	}
	plik.close();
	cout<<"Wczytano pomyslnie.\nNacisnij Enter...";
	get();
    clrscr();
}

void Terminarz::zapiszDoPliku()
{
	ofstream plik;
	plik.open("Terminarz.txt");
	if (plik.good() == true)
	{
		plik << tablicaZdarzen.size() << "\n";
		plik << tablicaZdarzendo.size() << "\n";
		for (int i = 1; i <= tablicaZdarzen.size(); i++)
		{
			tablicaZdarzen[i - 1].zapiszDoPliku(plik);
			plik.flush();
		}
		for (int i = 1; i <= tablicaZdarzendo.size(); i++)
		{
			tablicaZdarzendo[i - 1].zapiszDoPliku(plik);
			plik.flush();
		}
		plik.close();
	}
	cout << "Zapisano zmiany.\nNacisnij Enter...\n";
    get();
    clrscr();
}

void Terminarz::wyswietl()
{
	cout << "\tZdarzenia: \n\n";
	if(tablicaZdarzen.size())
        for (int i = 0; i<tablicaZdarzen.size(); i++)
            tablicaZdarzen[i].wyswietl();
    else
        cout<<"BRAK.\n";

	cout << "\n\tZadania do wykonania: \n\n";
	if(tablicaZdarzendo.size())
        for (int i = 0; i<tablicaZdarzendo.size(); i++)
            tablicaZdarzendo[i].wyswietl();
    else
        cout<<"BRAK.\n";
}

void Terminarz::wyswietlDo(int ile)
{
	Data doDaty = *dzisiaj;

	doDaty = dodaj(*dzisiaj, ile);

    cout << "\tZdarzenia:\n";
    if(tablicaZdarzen.size())
        for (int i = 0; (i<tablicaZdarzen.size()) && (tablicaZdarzen[i].data<doDaty); ++i)
            tablicaZdarzen[i].wyswietl();
    else
        cout<<"BRAK.\n";

    cout << "\tZdarzenia do:\n";
    if(tablicaZdarzendo.size())
        for (int i = 0; (i<tablicaZdarzendo.size()) && (tablicaZdarzendo[i].data<doDaty); ++i)
            tablicaZdarzendo[i].wyswietl();
    else
        cout<<"BRAK.\n";
}

void Terminarz::wyswietlDzisiaj()
{
	cout << setw(62) << "Dzisiaj: ";
	if(dzisiaj->dzien<10)
        cout<<"0";
	cout << dzisiaj->dzien << " ";
	if(dzisiaj->miesiac<10)
        cout<<"0";
	cout << dzisiaj->miesiac << " ";
	cout << dzisiaj->rok << " ";
	if(dzisiaj->godzina<10)
        cout<<"0";
	cout << dzisiaj->godzina << ":";
	if(dzisiaj->minuta<10)
        cout<<"0";
	cout << dzisiaj->minuta << endl;
}

void Terminarz::wyswietlDoUsuwania()
{
    while(tablicaZdarzen.size())
    {
        cout << "\tWybierz zdarzenia do usuniecia:\n<0> Koniec usuwania.\n\n";
        for (int i = 0; i<tablicaZdarzen.size(); i++)
        {
            cout<<"<"<<i+1<<"> ";
            tablicaZdarzen[i].wyswietl();
        }
        int decyzja;
        decyzja=wyborMenu();
        if(decyzja==0)
        {
            //----------------------------Koniec usuwania zdarzen---------------------------
			clrscr();
			cout << "Koniec usuwania zdarzen.";
			get();
			clrscr();
            break;
        }
        else if(decyzja<=tablicaZdarzen.size()&&decyzja>0)
        {
            //------------------------------usuwanie zdarzen-------------------------------------
            tablicaZdarzen.erase(tablicaZdarzen.begin()+decyzja-1);
            cout<<"Usunieto.";
            clrscr();
        }
		else
        {
            //-----------------------------Blad-----------------------------
			cout << "\nBLAD WYBORU.\nNacisnij Enter...";
			get();
			clrscr();
        }
    }
    while(tablicaZdarzendo.size())
    {
        cout << "\tWybierz zadania do usuniecia:\n<0> Koniec usuwania.\n\n";
        for (int i = 0; i<tablicaZdarzendo.size(); i++)
        {
            cout<<"<"<<i+1<<"> ";
            tablicaZdarzendo[i].wyswietl();
        }
        int decyzja;
        decyzja=wyborMenu();
        if(decyzja==0)
        {
            //----------------------------Koniec usuwania zadan---------------------------
            clrscr();
            cout << "Koniec usuwania zadan.";
            get();
            clrscr();
            break;
        }
        else if(decyzja<=tablicaZdarzendo.size()&&decyzja>0)
        {
            //------------------------------usuwanie zdarzen-------------------------------------
            tablicaZdarzendo.erase(tablicaZdarzendo.begin()+decyzja-1);
            cout<<"Usunieto.";
            clrscr();
        }
        else
        {
            //-----------------------------Blad-----------------------------
            cout << "\nBLAD WYBORU.\nNacisnij Enter...";
            clrscr();
        }
    }
}
