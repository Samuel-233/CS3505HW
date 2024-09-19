/*
Implementation for HaruPDF class
*/

#include "HaruPDF.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

HaruPDF::HaruPDF(const char *fileName)
{
    strcpy(this->fileName, fileName);
    strcat(this->fileName, ".pdf");
    this->pdf = HPDF_New(NULL, NULL);
    this->currentPage = NULL;
}

void HaruPDF::addPage()
{
    this->currentPage = HPDF_AddPage(this->pdf);
    HPDF_Page_SetSize(this->currentPage, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    HPDF_Page_BeginText(this->currentPage);
    this->setFont("Courier-Bold", 20);
}

void HaruPDF::setFont(const char *fontName, int fontSize)
{
    this->font = HPDF_GetFont(pdf, fontName, NULL);
    HPDF_Page_SetTextLeading(this->currentPage, 20);
    HPDF_Page_SetGrayStroke(this->currentPage, 0);
    HPDF_Page_SetFontAndSize(this->currentPage, this->font, fontSize);
    this->fontSize = fontSize;
}

void HaruPDF::addText(const char txt, float x, float y, float rot)
{
    char buffer[2];
    float radians = rot / 180.0 * M_PI;
    HPDF_Page_SetTextMatrix(this->currentPage,
                            cos(radians), sin(radians), -sin(radians), cos(radians),
                            x, y);
    buffer[0] = txt;
    buffer[1] = 0;
    HPDF_Page_ShowText(this->currentPage, buffer);
}

void HaruPDF::addText(const char *txt, float startX, float startY)
{
    for (this->i = 0; this->i < strlen(txt); this->i++)
    {
        this->addText(txt[this->i], startX + this->i * this->fontSize, startY, 0);
    }
}

void HaruPDF::outPut()
{
    HPDF_Page_EndText(this->currentPage);
    // save the document to a file
    HPDF_SaveToFile(this->pdf, this->fileName);
    // clean up
    HPDF_Free(this->pdf);
}
