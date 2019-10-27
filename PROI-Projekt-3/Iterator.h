#ifndef ITERATOR
#define ITERATOR

#include "Drzewo.h"


template <typename T, typename V>
class Iterator
{
    DrzewoWezel< T,V >* wsk;

public:
	Iterator();
	Iterator( DrzewoWezel< T,V >* );

	Iterator< T,V >& operator++();
	Iterator< T,V >& operator++(int);
	Iterator< T,V >& operator--();
	Iterator< T,V >& operator--(int);
	bool operator== ( const Iterator< T,V >& );
	bool operator!= ( const Iterator< T,V >& );
	Iterator< T,V >& operator= ( const Iterator< T,V >& );
	T operator* ();
};
#endif //ITERATOR
