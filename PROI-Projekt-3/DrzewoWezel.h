#ifndef DRZEWOWEZEL
#define DRZEWOWEZEL

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T, typename V>
struct DrzewoWezel
{
    T klucz;
    V wartosc;

    DrzewoWezel* lewy;
    DrzewoWezel* rodzic;
    DrzewoWezel* prawy;

    DrzewoWezel();
    DrzewoWezel(const T& ,const V& );
    DrzewoWezel( const DrzewoWezel< T,V >& ) = delete;
    ~DrzewoWezel();
    DrzewoWezel< T ,V >* operator = ( const DrzewoWezel < T,V >* );
};
#include "DrzewoWezel_imp.hpp"
#endif // DRZEWOWEZEL
