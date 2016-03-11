#include "Liczba.h"

Liczba::Liczba(std::string x)
    {
        liczba=x;
    }
Liczba operator+(const Liczba & a,const Liczba & b)
    {
        //------------------------Obiekty pomocnicze------------------------
        Liczba c("0");
        Liczba d("0");
        //------------------------Zmienne pomocnicze------------------------
        int skladnik1=0;
        int skladnik2=0;
        int k,dlugosc;
        int wart_a;
        int wart_b;
        //--------------------Dodawanie dwoch ujemnych----------------------
        if(a.liczba[0]=='-'&&b.liczba[0]=='-')
                return -((-a)+(-b));
        //-----------------------------a>0----------------------------------
        if(a.liczba[0]!='-'&&b.liczba[0]=='-')
        {
            //---Pobieram rozmiar skladnikow -1 do odczytywania z tablicy---
            int i=a.liczba.size()-1;
            int j=b.liczba.size()-1;
            //----Sprawdzanie czy modul ujemnej jest wiekszy od dodatniej---
            if(i==j-1)
            {
                for(d=-b,k=0;k<=i;k++)
                {
                    if(d.liczba[k]>a.liczba[k])
                        return -((-b)+(-a));
                    if(d.liczba[k]<a.liczba[k])
                        break;
                }
            }
            if(i<j-1)
                return -((-a)+(-b));
            //-----------------Zerowanie obiektu wynikowego-----------------
            for(k=0;(k<i||k<j);k++)
                   c.liczba+='0';
            dlugosc=k;
            //---------------------Dodawanie pisemne------------------------
            for(k,i,j;k>=0;i--,j--,k--)
            {
                //-------odczytywanie wartosci od konca - od jednosci-------
                wart_a=a.liczba[i];
                wart_b=b.liczba[j];
                //--------Jesli koniec to nie wprowadza nic do sumy---------
                if(i<0)
                    wart_a=48;
                if(j<1)
                    wart_b=48;
                //--------------------Dodawanie pisemne---------------------
                skladnik1=(wart_a-'0')-(wart_b-'0')+skladnik2;
                //--------Przenoszenie na nastepny bit jesli suma >9--------
                if (skladnik1<0&&i>=0)
                {
                    skladnik2=-1;
                    skladnik1=skladnik1+10;
                }
                else
                    skladnik2=0;
                //------wpiswanie skladnikow od konca najpierw jednosci-----
                c.liczba[k]+=skladnik1;
            }
            //-----------------Kasowanie poczatkowych zer------------------
            k=0;
            while(c.liczba[k]=='0')
            {
                k++;
            }
            //-------------------jesli wynikiem jest 0---------------------
            if(k==(int)c.liczba.size())
                k--;
            c.liczba=c.liczba.substr(k,std::string::npos);
            return c;
        }
        //-------------------------------a<0--------------------------------
        if(a.liczba[0]=='-'&&b.liczba[0]!='-')
            return b+a;
        //--------------------Dodawanie dwoch dodatnich---------------------
        if (a.liczba[0]!='-'&&b.liczba[0]!='-')
        {
            //---Pobieram rozmiar skladnikow -1 do wyczytywania z tablicy---
            int i=a.liczba.size()-1;
            int j=b.liczba.size()-1;
            //-----------------Zerowanie obiektu wynikowego-----------------
            for(k=0;(k<i||k<j);k++)
                c.liczba+='0';
            dlugosc=k;
            c.liczba+='0';
            //--Suma moze miec wiecej o 1 cyfre niz jej najdluzszy skladnik-
            k++;
            //--------------------------Dodawanie---------------------------
            for(k,i,j;k>=0;i--,j--,k--)
            {
                //------odczytywanie wartosci od konca - od jednosci--------
                wart_a=a.liczba[i];
                wart_b=b.liczba[j];
                //---------Jesli koniec to nie wprowadza nic do sumy--------
                if(i<0)
                    wart_a=48;
                if(j<0)
                    wart_b=48;
                //-------------------Dodawanie pisemne----------------------
                skladnik1=(wart_a-'0')+(wart_b-'0')+skladnik2;
                //--------Przenoszenie na nastepny bit jesli suma >9--------
                if (skladnik1>9)
                {
                    skladnik2=1;
                    skladnik1=skladnik1-10;
                }
                else
                    skladnik2=0;
                //------wpiswanie skladnikow od konca najpierw jednosci-----
                c.liczba[k]+=skladnik1;
            }
            if(skladnik2)
                c.liczba[k-1]+=skladnik2;
            //-------------------Kasowanie poczatkowych zer-----------------
            k=0;
            while(c.liczba[k]=='0')
            {
                k++;
            }
            //--------------------Jesli wyniekiem jest 0--------------------
            if(k==c.liczba.size())
                k--;
            c.liczba=c.liczba.substr(k,std::string::npos);
            return c;
        }
    }
Liczba operator-(const Liczba & a)
    {
        Liczba c("0");
        c=a;
        if(c.liczba[0]=='-')
            c.liczba=c.liczba.substr(1,std::string::npos);
        else
            c.liczba=c.liczba.insert(0,"-");
        return c;
    }
std::ostream& operator<< (std::ostream &wyjscie,const Liczba & a)
    {
        wyjscie << a.liczba;
        return wyjscie;
    }
