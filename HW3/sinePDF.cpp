#include "HaruPDF.h"
#include "Sine.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/*
The tester for the HaruPDF.
Use the Sine class to generate the curve, and draw letters on the curve.
*/
int main()
{
    const char *txt = "a loooooooooooooooooooooooooooooooooooooooong sine curve";
    float x = 10;
    float y = 300;
    float waveLen = 270;
    float step = 10;
    float amp = 50;
    float spacing = 10;

    HaruPDF pdf("sinePDF");
    pdf.addPage();
    pdf.setFont("Courier-Bold", spacing);
    Sine sine(amp, waveLen, step);

    for (unsigned i = 0; i < strlen(txt); i++)
    {
        // By using derivative, can get the slope of the curve
        float rot = cos(sine.currentAngle() * M_PI / waveLen * 2.0) * 45.0;
        pdf.addText(txt[i], x + i * spacing * 0.7, y + sine.currentHeight(), rot);
        sine++;
    }
    pdf.outPut();
}