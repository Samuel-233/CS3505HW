/*
Name: Shu Chen
HW2 for CS 3505
Class for Sine, This class will calculate the height for different degree for the sine.
This class start from degree 0, and increment it by custom step, by using currentHeight() method
user can get current height for the current angle.
*/

#include "Sine.h"
#include <cmath>
using std::ostream;

/// @brief Sine class
/// @param amp amp of sine wave
/// @param wavelength wavelength of the sine wave
/// @param inc every increment step size
Sine::Sine(double amp, double wavelength, double inc)
    :amplitude(amp), wavelength(wavelength), increment(inc), angle(0){
                
}

/// @brief Getter of angle
/// @return current angle
double Sine::currentAngle(){
    return this->angle;
}

/// @brief Calculate current height
/// @return current height by using current data
double Sine::currentHeight(){
    double radians = 2.0 * angle * M_PI / this->wavelength; 
    return this->amplitude * sin(radians);
}

/// @brief Overload operator <<
/// @return ostream with current angle and current height
ostream& operator<<(ostream& output, Sine sinObj){
    output << sinObj.currentAngle() << ", " << sinObj.currentHeight();
    return output;
}

/// @brief Overload prefix addition
/// @return an increment
Sine& Sine::operator++(){
    this->angle += this->increment;
    return *this;
}

/// @brief Overload post fix addition
/// @param foo a foo var that tell if it is post fix or pre fix
/// @return old object, without addition
Sine Sine::operator++(int foo){
    Sine result(*this); //This will call a "copy constructor, will make a copy of sine cobject"
    ++(*this);
    return result;
}