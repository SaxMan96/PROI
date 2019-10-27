#include "Funkcje.h"

std::string wczytaj()
{
    int i,czy;
    std::string tab;
    while (1)
    {
        std::cout<<"Podaj liczbe:\n";
        i=0;
        czy=0;
        std::cin>>tab;
        if(tab[0]=='-'&&tab.size()>N+1)
        {
            std::cout<<"Podaj poprawna maksymalnie N-cyfrowa liczbe.\n";
            system("cls");
            continue;
        }
        if(tab[0]!='-'&&tab.size()>N)
        {
            std::cout<<"Podaj poprawna maksymalnie N-cyfrowa liczbe.\n";
            system("cls");
            continue;
        }
        if(tab[i]==45)
            i++;
        if(tab[0]==48||(tab[0]==45&&tab[1]==48))
        {
            std::cout<<"Prosze podac poprawna liczbe calkowita\n";
            czy = 1;
            system("cls");
            break;
        }
        for(i; i<tab.size()&&!czy; i++)
            if(tab[i]<48 || tab[i]>58)
            {
                std::cout<<"Prosze podac poprawna liczbe calkowita\n";
                czy=1;
                system("cls");
                break;
            }
        if(czy == 0)
        {
            system("cls");
            return tab;
        }
    }
}
