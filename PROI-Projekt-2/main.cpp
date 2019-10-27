#include "Terminarz.h"
#include "Zdarzenie.h"
#include "Data.h"
#include "Funkcje.h"

using namespace std;

int main()
{
	//cout << "Tworze obiekt terminarz...\n";
	Terminarz terminarz;
	int decyzja;
	int decyzja1;
	int czy;
	while (1)
	{
		decyzja  = -1;
		decyzja1 = -1;
		czy = 1;
		terminarz.wyswietlDzisiaj();
		cout << "MENU:\n<1>Wczytaj z pliku\n<2>Wczytaj zdarzenie\n<3>Wyswietl\n<4>Zapisz zmiany\n<5>Usuwanie\n<6>Informacje\n<7>Wyjscie\n";
		decyzja = wyborMenu();
		switch (decyzja)
		{
		case 1:
			//-----------------------Wczytaj z pliku------------------------
			clrscr();
			terminarz.wczytajZPliku();
			break;
		case 2:
			//----------------------Wczytaj zdarzenie-----------------------
			clrscr();
			terminarz.wczytajZKlaw();
			break;
		case 3:
			//--------------------------Wyswietl----------------------------
			clrscr();
			while (czy)
			{
				terminarz.wyswietlDzisiaj();
				cout << "MENU:\n<1>Wczytaj z pliku\n<2>Wczytaj zdarzenie\n<3>Wyswietl\n";
				cout << "\t<1>Wszystko\n\t<2>Dzien\n\t<3>Tydzien\n\t<4>Miesiac\n";
				cout << "<4>Zapisz zmiany\n<5>Informacje\n<6>Wyjscie\n";
				decyzja1 = wyborMenu();
				switch (decyzja1)
				{
				case 1:
					//-----------Wszystko-----------
					clrscr();
					terminarz.wyswietl();
					get();
					clrscr();
					czy = 0;
					break;
				case 2:
					//-----------Dzien-----------
					clrscr();
					terminarz.wyswietlDo(1);
					get();
					clrscr();
					czy = 0;
					break;
				case 3:
					//----------Tydzien------------
					clrscr();
					terminarz.wyswietlDo(7);
					get();
					clrscr();
					czy = 0;
					break;
				case 4:
					//----------Miesiac------------
					clrscr();
					terminarz.wyswietlDo(30);
					get();
					clrscr();
					czy = 0;
					break;
				default:
					//-----------------------------Blad-----------------------------
					cout << "\nBLAD WYBORU.\nNacisnij Enter...";
					get();
					clrscr();
					break;
				}
			}
			break;
		case 4:
			//------------------------Zapisz zmiany-------------------------
			clrscr();
			terminarz.zapiszDoPliku();
			break;
        case 5:
            //-------------------------------Usuwanie---------------------------
            clrscr();
            terminarz.wyswietlDoUsuwania();
            break;
		case 6:
			//-----------------------------Info-----------------------------
			clrscr();
			cout << "============================================================================\nPROJEKT : 2.3 LABORATORIUM PROI 2016\n";
			cout << "AUTOR   : MATEUSZ DOROBEK - PW EITI, INFORMATYKA, SEM 2, GR I/5\nDATA    : 18.04.2016\n";
			cout << "============================================================================\nNacisnij Enter...";
			get();
			clrscr();
			break;
		case 7:
			//----------------------------Wyjscie---------------------------
			clrscr();
			cout << "DZIEKUJE ZA SKORZYSTANIE Z PROGRAMU.";
			return 0;
		default:
			//-----------------------------Blad-----------------------------
			cout << "\nBLAD WYBORU.\nNacisnij Enter...";
			get();
			clrscr();
			break;
		}
	}
	return 0;
}
