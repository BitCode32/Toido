#include "../../Include/Events/MouseEvent.h"

void InitializeMouseMovedEvent(MouseMovedEvent* NewMouseMovedEvent, unsigned int X, unsigned int Y)
{

    NewMouseMovedEvent->MouseEvent.Type = EventTypeMouseMoved;
    NewMouseMovedEvent->MouseEvent.Category = EventCategoryInput | EventCategoryMouse;

    NewMouseMovedEvent->X = X;
    NewMouseMovedEvent->Y = Y;

}

void InitializeMouseScrolledEvent(MouseScrolledEvent* NewMouseScrolledEvent, unsigned int DeltaScroll)
{

    NewMouseScrolledEvent->MouseEvent.Type = EventTypeMouseScrolled;
    NewMouseScrolledEvent->MouseEvent.Category = EventCategoryInput | EventCategoryMouse;

    NewMouseScrolledEvent->DeltaScroll = DeltaScroll;

}

void InitializeMouseButtonPressedEvent(MouseButtonPressedEvent* NewMouseButtonPressedEvent, MouseCode MouseButtonPressed)
{

    NewMouseButtonPressedEvent->MouseEvent.Type = EventTypeMouseButtonPressed;
    NewMouseButtonPressedEvent->MouseEvent.Category = EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton;

    NewMouseButtonPressedEvent->MouseButtonPressed = MouseButtonPressed;

}

void InitializeMouseButtonReleasedEvent(MouseButtonReleasedEvent* NewMouseButtonReleasedEvent, MouseCode MouseButtonReleased)
{

    NewMouseButtonReleasedEvent->MouseEvent.Type = EventTypeMouseButtonReleased;
    NewMouseButtonReleasedEvent->MouseEvent.Category = EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton;

    NewMouseButtonReleasedEvent->MouseButtonReleased = MouseButtonReleased;

}