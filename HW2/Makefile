testCompile: Sine.o testSine.o
	g++ -o testCompile Sine.o testSine.o
Sine.o: Sine.cpp Sine.h
	g++ -c Sine.cpp
testSine.o : testSine.cpp Sine.h
	g++ -c testSine.cpp
test : testCompile
	./testCompile > SineData.txt