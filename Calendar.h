#ifndef CALENDAR_H
#define CALENDAR_H

#include "Schedulable.h"
#include "Reminder.h"
#include "Meeting.h"
#include "Appointment.h"
#include "Locatable.h"
#include <vector>
#include <iostream>
#include <string>

/**
 * @class Calendar
 * @brief to manage a collection of schedulable events such as reminders, meetings, and appointments.
 *
 * This class provides functionality to add events to the calendar and retrieve events for specific dates.
 */
class Calendar {
private:
    std::vector<Schedulable*> events; // Vector to hold Schedulable events

public:
    /**
     * @brief Default Constructor a Calendar object.
     *
     * to initialize an empty calendar that can hold various events.
     */
    Calendar(){}

    /**
     * @brief to add a Schedulable event to the calendar.
     *
     * @param event Pointer to the Schedulable event to be added.
     */
    void addEvent(Schedulable *event);

    /**
     * @brief to retrieve events scheduled for a specific date.
     *
     * @param date A string representing the date in MM/DD/YYYY format.
     * @return A string containing all events scheduled for the specified date.
     */
    std::string getDaysEvents(const std::string &date) const;

    /**
     * @brief Constructor to destroy the Calendar object and deallocates any resources.
     *
     * to ensure that all dynamically allocated events are properly cleaned up.
     */
    ~Calendar(); // Destructor
};

#endif // CALENDAR_H
