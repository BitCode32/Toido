#ifndef TOIDO_MOUSE_EVENT
#define TOIDO_MOUSE_EVENT

#include "Event.h"
#include "MouseCodes.h"

typedef struct
{

    Event MouseEvent;
    unsigned int X, Y;

} MouseMovedEvent;

typedef struct 
{

    Event MouseEvent;
    unsigned int DeltaScroll;

} MouseScrolledEvent;

typedef struct
{

    Event MouseEvent;
    MouseCode MouseButtonPressed;

} MouseButtonPressedEvent;

typedef struct
{

    Event MouseEvent;
    MouseCode MouseButtonReleased;

} MouseButtonReleasedEvent;

void InitializeMouseMovedEvent(MouseMovedEvent* NewMouseMovedEvent, unsigned int X, unsigned int Y);
void InitializeMouseScrolledEvent(MouseScrolledEvent* NewMouseScrolledEvent, unsigned int DeltaScroll);
void InitializeMouseButtonPressedEvent(MouseButtonPressedEvent* NewMouseButtonPressedEvent, MouseCode MouseButtonPressed);
void InitializeMouseButtonReleasedEvent(MouseButtonReleasedEvent* NewMouseButtonReleasedEvent, MouseCode MouseButtonReleased);

#endif