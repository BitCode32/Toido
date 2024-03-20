#ifndef TOIDO_FONT
#define TOIDO_FONT

#include "Color.h"
#include "../OS.h"

typedef struct
{

    char* Type;
    unsigned int Size;
    Color TextColor;

    #ifdef WIN

        HFONT ApiFont;

    #elif defined LIN

    #endif

} Font;

void InitializeFont(Font* NewFont, char* Type, unsigned int Size, Color TextColor);
void DestroyFont(Font* CurrentFont);

#endif