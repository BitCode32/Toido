#ifndef TOIDO_OS
#define TOIDO_OS

#ifdef _WIN32

    #define WIN
    #include <windows.h>

#elif defined __linux__

    #define LIN

#endif

#endif