/*
 * << Alternative PDF Library 1.0.0 >> -- text_demo2.c
 *
 * Copyright (c) 1999-2006 Takeshi Kanno <takeshi_kanno@est.hi-ho.ne.jp>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.
 *
 * Modified by Shu Chen, University of Utah, 2024.
 */

/*
This is the interface of the HaruPDF.cpp, which is the facade class for Haru lib.
User can add page and put letter in to pdf then output it as a PDF file
*/

#ifndef HARUPDF_H
#define HARUPDF_H

#include "hpdf.h"

class HaruPDF{
    HPDF_Doc  pdf;
    HPDF_Page currentPage;
    char fileName[256];
    HPDF_Font font;
    int fontSize;
    unsigned int i;

public:
    /// @brief Make a empty PDF, waiting for data input
    /// @param fileName fileName of this PDF
    HaruPDF(const char* fileName);

    /// @brief Add a new page to PDF
    void addPage();

    /// @brief Set the font and font size for the text
    /// @param fontName font name
    /// @param fontSize font size
    void setFont(const char* fontName, int fontSize);

    /// @brief Add texts to pdf
    /// @param txt text want to display
    /// @param startX start position, X component
    /// @param startY start position, Y component
    void addText(const char* txt, float startX, float startY);

    /// @brief Add a single char to pdf, but can rotatate the char on PDF
    /// @param txt text want to display
    /// @param x start position, X component
    /// @param y start position, Y component
    /// @param rot rotation degree of this char
    void addText(const char txt, float x, float y, float rot);

    /// @brief Output the PDF file
    void outPut();
};

#endif


