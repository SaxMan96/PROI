#include "Drzewo.h"

template< typename T ,typename V >
Drzewo < T,V >::Drzewo()
{
    korzen = new DrzewoWezel< T,V >;
}

template<typename T,typename V>
Drzewo < T,V >::~Drzewo()
{
    delete korzen;
}

template<typename T,typename V>
void Drzewo < T,V >::wstawWezel( const T &k , const V &w)
{
    DrzewoWezel< T ,V > wezel(k,w);
    wstawWezel(wezel,korzen);
}

template<typename T,typename V>
void Drzewo < T ,V >::wstawWezel(const DrzewoWezel< T,V >& doWstawienia, DrzewoWezel< T,V >* aktualny)
{
    if(aktualny -> klucz == "")
    {
        //korzen
       *aktualny = doWstawienia;
        aktualny -> prawy  = nullptr;
        aktualny -> lewy   = nullptr;
        aktualny -> rodzic = korzen;
        return;
    }
    else if (aktualny -> klucz == doWstawienia.klucz)
    {
        //cout<<"Taki element juz istnieje, wiec go nadpisuje."; #define nadpisuje sie
        aktualny -> wartosc = doWstawienia.wartosc;
        return;
    }
    else if(doWstawienia.klucz > aktualny -> klucz)
    {
        if(aktualny -> prawy!=nullptr)
            wstawWezel(doWstawienia, aktualny -> prawy);

        else
        {
            aktualny -> prawy = new DrzewoWezel< T ,V >;
           *aktualny -> prawy = doWstawienia;
            aktualny -> prawy -> prawy  = nullptr;
            aktualny -> prawy -> lewy   = nullptr;
            aktualny -> prawy -> rodzic = aktualny;
            return;
        }
    }
    else
    {
        if(aktualny -> lewy != nullptr)
            wstawWezel(doWstawienia, aktualny -> lewy);

        else
        {
            aktualny -> lewy = new DrzewoWezel< T ,V >;
           *aktualny -> lewy = doWstawienia;
            aktualny -> lewy -> prawy  = nullptr;
            aktualny -> lewy -> lewy   = nullptr;
            aktualny -> lewy -> rodzic = aktualny;
            return;
        }
    }
    return;
}

template< typename T, typename V >
V Drzewo < T ,V >::znajdzZnaczenie( const T& szukane)
{
    if(korzen -> lewy == nullptr || korzen -> prawy == nullptr)
        throw EmptyTreeException();

    V znaczenie;
    znaczenie = znajdzZnaczenie( szukane, korzen );

    return znaczenie;
}

template<typename T, typename V >
V Drzewo < T ,V >::znajdzZnaczenie(const T& szukane , DrzewoWezel< T ,V >* aktualny)
{
    if(aktualny == nullptr)
         throw NotFoundException();

    else if (aktualny -> klucz == szukane)
    {
        if(aktualny -> wartosc == "\n"|| aktualny -> wartosc == " ")
            return "";
        else
            return aktualny -> wartosc + " ";
    }

    else if (aktualny -> klucz > szukane && aktualny -> lewy != nullptr)
        return znajdzZnaczenie( szukane, aktualny -> lewy);

    else if (aktualny -> klucz < szukane && aktualny -> prawy != nullptr)
        return znajdzZnaczenie( szukane, aktualny -> prawy);

    else
        throw NotFoundException();
}
