#include "Iterator.h"


template <typename T, typename V>
Iterator< T,V >::Iterator(): wsk(nullptr) {}

template <typename T, typename V>
Iterator< T,V >::Iterator( DrzewoWezel< T,V >* n ): wsk(n) {}

// operator wyluskania
template <typename T, typename V>
T Iterator< T,V >::operator* ()
{
    return wsk->klucz;
}

// preinkrementacja  ++iter
template <typename T, typename V>
Iterator< T,V >& Iterator< T,V >::operator++()
{
    if(wsk -> lewy != nullptr)
        wsk = wsk -> lewy;
    else if(wsk -> prawy != nullptr)
        wsk = wsk ->prawy;
    else if(wsk -> rodzic != nullptr)
        wsk = wsk -> rodzic;
    else
        wsk = nullptr;
        // lub throw OutOfRange();

    return *this;
}

// postinkrementacja  iter++
template <typename T, typename V>
Iterator< T,V >& Iterator< T,V >::operator++(int)
{
    Iterator tmp = *this;

    if(wsk -> lewy != nullptr)
        wsk = wsk -> lewy;
    else if(wsk -> prawy != nullptr)
        wsk = wsk ->prawy;
    else if(wsk -> rodzic != nullptr)
        wsk = wsk -> rodzic;
    else
        wsk = nullptr;

    return tmp;
}

// predekrementacji  --iter
template <typename T, typename V>
Iterator< T,V >& Iterator< T,V >::operator--()
{
    if(wsk -> rodzic != nullptr)
        wsk = wsk -> rodzic;
    else if(wsk -> prawy != nullptr)
        wsk = wsk ->prawy;
    else if(wsk -> lewy != nullptr)
        wsk = wsk -> lewy;
    else
        wsk = nullptr;
        // lub throw OutOfRange();

    return *this;
}

// postdekrementacja  iter--
template <typename T, typename V>
Iterator< T,V >& Iterator< T,V >::operator--(int)
{
    Iterator tmp = *this;

    if(wsk -> rodzic != nullptr)
        wsk = wsk -> rodzic;
    else if(wsk -> prawy != nullptr)
        wsk = wsk ->prawy;
    else if(wsk -> lewy != nullptr)
        wsk = wsk -> lewy;
    else
        wsk = nullptr;

    return tmp;
}

// operator porownania ==
template <typename T, typename V>
bool Iterator< T,V >::operator== ( const Iterator< T,V >& i )
{
    if ( wsk == i.wsk )
        return true;
    else
        return false;
}

// operator nierownosci !=
template <typename T, typename V>
bool Iterator< T,V >::operator!= ( const Iterator< T,V >& i )
{
    return !( *this == i );
}

// operator przypisania =
template <typename T, typename V>
Iterator< T,V >& Iterator< T,V >::operator= ( const Iterator< T,V >& i )
{
    wsk = i.wsk;
    return *this;
}
