#include "DrzewoWezel.h"

template<typename T, typename V>
DrzewoWezel< T,V >::DrzewoWezel()
{
    lewy = nullptr;
    prawy = nullptr;
    rodzic = nullptr;
}

template<typename T, typename V>
DrzewoWezel< T,V >::DrzewoWezel(const T& k,const V& w)
{
    klucz = k;
    wartosc = w;
    lewy = nullptr;
    prawy = nullptr;
    rodzic = nullptr;
}

template<typename T, typename V>
DrzewoWezel< T,V >::~DrzewoWezel()
{
    if(this == nullptr)
        return;
    rodzic = nullptr;
    if(lewy != nullptr)
        delete lewy;
    if(prawy != nullptr)
        delete prawy;
}

template<typename T, typename V>
DrzewoWezel< T ,V >* DrzewoWezel < T,V >::operator = ( const DrzewoWezel < T,V >* doPrzypisania)
{
    delete this;
    if (doPrzypisania == nullptr)
        return nullptr;

    DrzewoWezel< T,V > *nowy = new DrzewoWezel(doPrzypisania -> klucz, doPrzypisania -> wartosc);
    nowy -> lewy  = doPrzypisania -> lewy;
    nowy -> prawy = doPrzypisania -> prawy;
    return nowy;
}
