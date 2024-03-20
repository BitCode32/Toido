#ifndef TOIDO_COLOR
#define TOIDO_COLOR

typedef struct
{
    
    unsigned char R, G, B;

} Color;

void InitializeColor(Color* NewColor, unsigned char R, unsigned char G, unsigned char B);

int MixColor(Color* CurrentColor, Color* OtherColor, float Percentage);
int ChangeColorBrightness(Color* CurrentColor, float Brightness);

#endif