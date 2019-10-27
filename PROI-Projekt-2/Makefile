OBJS=main.o Terminarz.o Zdarzenie.o Data.o Funkcje.o
CXX=g++
CXXLAGS=-Wall -std=c++11
LFLAGS=

Projekt1.out: $(OBJS) Terminarz.h Zdarzenie.h Data.h Funkcje.h
	$(CXX) $(OBJS) -o Projekt2.out

main.o: main.cpp
	$(CXX) -c $(CXXLAGS) main.cpp -o main.o


Funkcje.o: Funkcje.cpp
	$(CXX) -c $(CXXLAGS) Funkcje.cpp -o Funkcje.o


Data.o: Data.cpp
	$(CXX) -c $(CXXLAGS) Data.cpp -o Data.o


Zdarzenie.o: Zdarzenie.cpp
	$(CXX) -c $(CXXLAGS) Zdarzenie.cpp -o Zdarzenie.o


Terminarz.o: Terminarz.cpp
	$(CXX) -c $(CXXLAGS) Terminarz.cpp -o Terminarz.o



clean:
	rm -f *.o
.PHONY: clean