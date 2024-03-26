#ifndef TOIDO_MOUSECODES
#define TOIDO_MOUSECODES

#include "../OS.h"

typedef enum
{

    #ifdef WIN
        
        MC_LEFT = 0x01,
        MC_RIGHT = 0x02,
        MC_MIDDLE = 0x04,
        MC_X1 = 0x05,
        MC_X2 = 0x06

    #elif defined LIN
        
        MC_LEFT = 1,
        MC_RIGHT = 2,
        MC_MIDDLE = 3,
        MC_X1 = 8,
        MC_X2 = 9

    #endif

} MouseCode;
    
#endif