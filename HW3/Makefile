LIBHARU = ./libharu

SRC = ./src
INC = ./include

CFLAGS = -Wall -I$(INC) -I$(LIBHARU)/include

sinePDF : sinePDF.o HaruPDF.o Sine.o
	g++ -Wall -o sinePDF sinePDF.o HaruPDF.o Sine.o -L$(LIBHARU)/src -lhpdfs

sinePDF.o : sinePDF.cpp $(INC)/HaruPDF.h $(INC)/Sine.h
	g++ -Wall $(CFLAGS) -c sinePDF.cpp

HaruPDF.o : $(SRC)/HaruPDF.cpp $(INC)/HaruPDF.h
	g++ -Wall $(CFLAGS) -c $(SRC)/HaruPDF.cpp

Sine.o : $(SRC)/Sine.cpp $(INC)/Sine.h
	g++ -Wall -I$(INC) -c $(SRC)/Sine.cpp



clean : 
	rm -f *.o