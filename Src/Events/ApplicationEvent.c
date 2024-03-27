#include "../../Include/Events/ApplicationEvent.h"

void InitializeWindowResizeEvent(WindowResizeEvent* NewResizeEvent, unsigned int Width, unsigned int Height)
{

    NewResizeEvent->ApplicationEvent.Type = EventTypeWindowResize;
    NewResizeEvent->ApplicationEvent.Category = EventCategoryApplication;

    NewResizeEvent->Width = Width;
    NewResizeEvent->Height = Height;

}

void InitializeWindowCloseEvent(WindowCloseEvent* NewCloseEvent)
{

    NewCloseEvent->ApplicationEvent.Type = EventTypeWindowClose;
    NewCloseEvent->ApplicationEvent.Category = EventCategoryApplication;

}

void InitializeWindowFocusEvent(WindowFocusEvent* NewFocusEvent)
{

    NewFocusEvent->ApplicationEvent.Type = EventTypeWindowFocus;
    NewFocusEvent->ApplicationEvent.Category = EventCategoryApplication;

}

void InitializeWindowLostFocusEvent(WindowLostFocusEvent* NewLostFocusEvent)
{

    NewLostFocusEvent->ApplicationEvent.Type = EventTypeWindowLostFocus;
    NewLostFocusEvent->ApplicationEvent.Category = EventCategoryApplication;

}

void InitializeComponentEvent(ComponentEvent* NewComponentEvent, unsigned int ComponentId, unsigned int ComponentEvent)
{

    NewComponentEvent->ApplicationEvent.Type = EventTypeApplicationComponent;
    NewComponentEvent->ApplicationEvent.Category = EventCategoryApplication;

    NewComponentEvent->ComponentId = ComponentId;
    NewComponentEvent->ComponentEvent = ComponentEvent;

}