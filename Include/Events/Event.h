#ifndef TOIDO_EVENT
#define TOIDO_EVENT

typedef enum 
{

    EventTypeWindowResize, EventTypeWindowClose, EventTypeWindowFocus, EventTypeWindowLostFocus, EventTypeApplicationComponent,
    EventTypeKeyPressed, EventTypeKeyReleased,
    EventTypeMouseButtonPressed, EventTypeMouseButtonReleased, EventTypeMouseMoved, EventTypeMouseScrolled

} EventType;

typedef enum 
{

    None = 0,
    EventCategoryApplication = 0x00001, 
    EventCategoryInput = 0x00010,
    EventCategoryKeyboard = 0x00100, 
    EventCategoryMouse = 0x01000,
    EventCategoryMouseButton = 0x10000

} EventCategory;

typedef struct
{

    EventType Type;
    EventCategory Category;    

} Event;

#endif