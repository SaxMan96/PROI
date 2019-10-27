OBJS=main.o Preprocesor.o Iterator.o
CXX=g++
CXXLAGS=-Wall -std=c++11
TARGET=Projekt3.out

.PHONY: clean

$(TARGET): $(OBJS) 
	$(CXX) $(OBJS) -o $(TARGET)
main.o: main.cpp Preprocesor.h EmptyTreeException.h NotFoundException.h Iterator.h
	$(CXX) -c $(CXXLAGS) main.cpp -o main.o
Preprocesor.o: Preprocesor.cpp Preprocesor.h Drzewo_imp.hpp DrzewoWezel_imp.hpp Drzewo.h DrzewoWezel.h EmptyTreeException.h NotFoundException.h
	$(CXX) -c $(CXXLAGS) Preprocesor.cpp -o Preprocesor.o
Iterator.o: Iterator.cpp Iterator.h Drzewo_imp.hpp DrzewoWezel_imp.hpp Drzewo.h DrzewoWezel.h EmptyTreeException.h NotFoundException.h
	$(CXX) -c $(CXXLAGS) Iterator.cpp -o Iterator.o
clean:
	rm -f *.o
	rm -f $(TARGET)
 