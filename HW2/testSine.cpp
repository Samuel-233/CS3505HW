#include "Sine.h"
/*
Name: Shu Chen
HW2 for CS 3505
Tester for the Sine class, create a sine class and let it to output degree and height from 0 to 360
*/

int main(){
    Sine sine(1.0, 360.0, 1.0);

    for(int i = 0; i < 361; i++){
        std::cout << sine++ << "\n";
    }

    std::cout << std::endl;
}       


/* NOTE:
Since we compile it by 
"g++ -o testCompile testSine.cpp Sine.cpp", 
we do not need to include Sine.cpp, because be just need to 
import the interface（sine.h), when compile, compiler will make Sine.o and 
testSine.o, then link together to make testCompile file
*/
