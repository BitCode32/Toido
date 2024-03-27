#ifndef TOIDO_KEY_EVENT
#define TOIDO_KEY_EVENT

#include "Event.h"
#include "KeyCodes.h"

typedef struct
{

    Event KeyEvent;
    KeyCode KeyPressed;

} KeyPressedEvent;

typedef struct 
{

    Event KeyEvent;
    KeyCode KeyReleased;

} KeyReleasedEvent;

void InitializeKeyPressedEvent(KeyPressedEvent* NewKeyPressedEvent, KeyCode KeyPressed);
void InitializeKeyReleasedEvent(KeyReleasedEvent* NewKeyReleasedEvent, KeyCode KeyReleased);

#endif