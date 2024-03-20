#include "../../Include/GUI/Font.h"

#include "../../Include/Bool.h"

#include <stdlib.h>

void InitializeFont(Font* NewFont, char* Type, unsigned int Size, Color TextColor)
{

    NewFont->Size = Size;
    NewFont->TextColor = TextColor;

    unsigned int Length = 0;
    while (Type[Length] != '\0')
        Length++;

    NewFont->Type = (char*)malloc(sizeof(char) * (Length + 1));
    for (unsigned int i = 0; i <= Length; i++)
        NewFont->Type[i] = Type[i];

    #ifdef WIN

        NewFont->ApiFont = CreateFontA(NewFont->Size, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, NewFont->Type);

    #elif defined LIN

    #endif

}

void DestroyFont(Font* CurrentFont)
{

    free(CurrentFont->Type);

}