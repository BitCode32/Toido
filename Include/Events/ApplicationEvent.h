#ifndef TOIDO_APPLICATION_EVENT
#define TOIDO_APPLICATION_EVENT

#include "Event.h"

typedef struct 
{

    Event ApplicationEvent;
    unsigned int Width, Height;

} WindowResizeEvent;

typedef struct
{
    
    Event ApplicationEvent;

} WindowCloseEvent, WindowFocusEvent, WindowLostFocusEvent;

typedef struct
{

    Event ApplicationEvent;
    unsigned int ComponentId, ComponentEvent;

} ComponentEvent;

void InitializeWindowResizeEvent(WindowResizeEvent* NewResizeEvent, unsigned int Width, unsigned int Height);

void InitializeWindowCloseEvent(WindowCloseEvent* NewCloseEvent);
void InitializeWindowFocusEvent(WindowFocusEvent* NewFocusEvent);
void InitializeWindowLostFocusEvent(WindowLostFocusEvent* NewLostFocusEvent);

void InitializeComponentEvent(ComponentEvent* NewComponentEvent, unsigned int ComponentId, unsigned int ComponentEvent);

#endif