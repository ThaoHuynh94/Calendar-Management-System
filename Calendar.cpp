#include "Calendar.h"


// Adds an event to the calendar
void Calendar::addEvent(Schedulable *event)
{
    events.push_back(event); // Store the event in the vector
}

// Returns all events for a given day
std::string Calendar::getDaysEvents(const std::string &date) const
{
    std::string eventsOnDate;

    for (const Schedulable *event : events) {
        if (event->getDate() == date) {
            eventsOnDate += event->toString() + "\n";
        }
    }

    return eventsOnDate; // Return all events for the date
}

// Destructor
Calendar::~Calendar() {
    // clean up the vector
    for (Schedulable* event : events) {
        delete event;
    }
}
