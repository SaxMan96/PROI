#ifndef Liczba_h
#define Liczba_h
#include <iostream>
#include <string>
#include <cstdlib>
class Liczba
{
    //---------Parametr (private)--------
    std::string liczba;
    public:
    //-------------Konstruktory-----------
    Liczba(std::string a);
    void wyswietl();
    //--------------Operator+-------------
    friend Liczba operator+(const Liczba & a,const Liczba & b);
    friend Liczba operator-(const Liczba & a);
    Liczba& operator=(const Liczba & a)
    {
        liczba=a.liczba;
        return *this;
    }
    friend std::ostream& operator<< (std::ostream &wyjscie,const Liczba & a);

};
#endif
