/*
Name: Shu Chen
HW2 for CS 3505
header file for Sine class, define sine parameter and func, kinda like interface in java
This class will calculate the height for different degree for the sine.
This class start from degree 0, and increment it by custom step, by using currentHeight() method
user can get current height for the current angle.
*/

#ifndef SINE_H
#define SINE_H

#include <iostream>
using std::ostream;

class Sine{
    double amplitude;
    double wavelength;
    double increment;
    double angle;

public:
    /// @brief Sine class
    /// @param amp amp of sine wave
    /// @param wavelength wavelength of the sine wave
    /// @param inc every increment step size
    Sine(double amp, double wavelength, double inc);
    
    /// @brief Getter of angle
    /// @return current angle
    double currentAngle();

    /// @brief Calculate current height
    /// @return current height by using current data
    double currentHeight();

    /// @brief Overload operator <<
    /// @return ostream with current angle and current height
    friend ostream& operator<<(ostream& output, Sine sinClass);
        
    /// @brief Overload prefix addition
    /// @return an increment
    Sine& operator++();
        
    /// @brief Overload post fix addition
    /// @param foo a foo var that tell if it is post fix or pre fix
    /// @return old object, without addition
    Sine operator++(int); //To separate two overload, we need a dummy parameter
};

#endif