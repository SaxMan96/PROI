#ifndef DRZEWO
#define DRZEWO

#include "DrzewoWezel.h"
#include "NotFoundException.h"
#include "EmptyTreeException.h"

#include <fstream>

template< typename T , typename V >
class Drzewo
{
    DrzewoWezel< T ,V >* korzen;

public:
    Drzewo();
    ~Drzewo();
    Drzewo(const Drzewo< T,V >& ) = delete;
    Drzewo< T ,V >& operator =( const Drzewo < T ,V >& ) = delete;
    void wstawWezel( const T & , const V & );
    V znajdzZnaczenie(const T & );

private:
    void wstawWezel(const DrzewoWezel < T ,V >&, DrzewoWezel< T ,V >* );
    V znajdzZnaczenie(const T & , DrzewoWezel< T ,V >* );
};
#include "Drzewo_imp.hpp"
#endif //DRZEWO
