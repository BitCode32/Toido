#include "../../Include/Events/KeyEvent.h"

void InitializeKeyPressedEvent(KeyPressedEvent* NewKeyPressedEvent, KeyCode KeyPressed)
{

    NewKeyPressedEvent->KeyEvent.Type = EventTypeKeyPressed;
    NewKeyPressedEvent->KeyEvent.Category = EventCategoryInput | EventCategoryKeyboard;

    NewKeyPressedEvent->KeyPressed = KeyPressed;

}

void InitializeKeyReleasedEvent(KeyReleasedEvent* NewKeyReleasedEvent, KeyCode KeyReleased)
{

    NewKeyReleasedEvent->KeyEvent.Type = EventTypeKeyReleased;
    NewKeyReleasedEvent->KeyEvent.Category = EventCategoryInput | EventCategoryKeyboard;
    
    NewKeyReleasedEvent->KeyReleased = KeyReleased;

}