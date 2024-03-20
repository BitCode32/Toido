#include "../../Include/GUI/Color.h"

void InitializeColor(Color* NewColor, unsigned char R, unsigned char G, unsigned char B)
{

    NewColor->R = R;
    NewColor->G = G;
    NewColor->B = B;

}

int MixColor(Color* CurrentColor, Color* OtherColor, float Percentage)
{

    if (Percentage > 1.0f || Percentage < 0.0f)
        return -1;

    CurrentColor->R = (CurrentColor->R * (1.0f - Percentage)) + (OtherColor->R * Percentage);
    CurrentColor->G = (CurrentColor->G * (1.0f - Percentage)) + (OtherColor->G * Percentage);
    CurrentColor->B = (CurrentColor->B * (1.0f - Percentage)) + (OtherColor->B * Percentage);

    return 0;

}

int ChangeColorBrightness(Color* CurrentColor, float Brightness)
{

    if (Brightness > 1.0f || Brightness < 0.0f)
        return -1;

    CurrentColor->R *= Brightness;
    CurrentColor->G *= Brightness;
    CurrentColor->B *= Brightness;

    return 0;

}