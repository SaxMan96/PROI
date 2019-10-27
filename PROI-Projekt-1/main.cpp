#include "Liczba.h"
#include "Funkcje.h"
#define q cout<<"*";
using namespace std;


int main()
{
    //Tablica do wczytania liczby-------
    //Funkcja wczytywania liczby--------
    //Konstruktor
    Liczba x(wczytaj());
    //Wyswietlanie---------------------
   /* cout<<x;*/
    //Funkcja wczytywania liczby--------
    Liczba y(wczytaj());
    //Dodoawanie------------
    //Zmiana znaku------------------
     //Przypisanie--------------------
    Liczba z("0");
    z=x+y;
    cout<<"x="<<x<<"\ny="<<y<<"\nz=x+y="<<z<<endl;

    int decyzja;

    return 0;
}
