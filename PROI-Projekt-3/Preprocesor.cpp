#include "Preprocesor.h"


Preprocesor::Preprocesor()
{
    //cout << "konstruktor Preprocesor" << endl;
};

Preprocesor::~Preprocesor()
{
    //cout << "destruktor Preprocesor" << endl;
}
void Preprocesor::wczytaj()
{
    ifstream plik;               //Zmienna do ktorej wczytuje plik Terminarz.txt
    plik.open( "Tekst.txt" );      //Otwieram plik
    if ( !plik.good() )            //Sprawdzam czy otwieranie sie powiodlo
    {
        cout << "Plik nie istnieje!";
        return;
    }

    string temp1, temp2;  //zmienne przechowujace klucz i wartosc wczytana z pliku
    string linia;                //Zmienna do ktorej wczytuje kolejne linijki pliku
    int licznik;                 //Zmienna pomocnicza przy poruszaniu sie po tekscie

    getline(plik, linia, ' ');
    while(linia == "#define")
    {
        for(licznik=0;licznik<2;licznik++)
        {
            if(licznik == 0)
            {
                getline(plik, linia, ' ');
                temp1 = linia;
            }
            if(licznik == 1)
            {
                getline(plik, linia, '\n');
                temp2 = linia;
                drzewo.wstawWezel(temp1, temp2);
            }
        }
        getline(plik, linia, ' ');
    }
    //wczytywanie tekstu
    while( !plik.eof() )
    {
        linia += " ";
        tekst = tekst + linia;
        getline(plik, linia, ' ');
    }
    getline(plik, linia, '\n');
    tekst = tekst + linia;
    plik.close();
}

void Preprocesor::wyswietl()const
{
    cout << "\nTekst: " << tekst << endl;
}
void Preprocesor::podmien()
{
    string poj_slowo;
    string podmieniony_tekst;
    istringstream iss ( tekst );

    while( !iss.eof() )
    {
        iss >> poj_slowo;
        if( iss.eof() )
            break;
        try
        {
            podmieniony_tekst = podmieniony_tekst + drzewo.znajdzZnaczenie(poj_slowo);
        }
        catch( const EmptyTreeException & e )
        {
            podmieniony_tekst = tekst;
            cout << "Drzewo jest puste"<<endl;
            break;
        }
        catch( NotFoundException & e )
        {
            podmieniony_tekst = podmieniony_tekst + poj_slowo + " ";
            continue;
        }
    }
    tekst = podmieniony_tekst;
}
void Preprocesor::zapisz()
{
    ofstream plik( "TekstPoZmianie.txt" );
    if ( plik.good() == true)
    {
        plik << tekst << "\n";
        plik.flush();
        plik.close();
        cout << "\nZapisano zmiany do pliku.\nDziekuje za skorzystanie z programu.\n\n";
    }
    else
        cout << "Nie udalo sie zapisac."<<endl;
}
