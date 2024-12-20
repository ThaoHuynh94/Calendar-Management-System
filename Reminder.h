#ifndef REMINDER_H
#define REMINDER_H
#include <sstream>
#include <iomanip>
#include "Schedulable.h"



/**
 * @class Reminder
 * This class represents a reminder event.
 * The Reminder class is a derived class of the Schedulable - an abstract base class.
 * It encapsulates a date and a task that needs to be reminded on that date.
 * This class allows creating reminders with specified dates and associated tasks.
 */
class Reminder : public Schedulable{
private:
    int month; //The month of the reminder
    int year;  // The year of the reminder
    int day;  //The day of the reminder
    std::string task;
public:
    /**
    * @brief Default constructor for Reminder.
    *
    * Initializes the reminder to a default date of January 1, 2024
    * with no task assigned.
    */
    Reminder():  day(1), month(1), year(2024), task("No task"){}

    /**
    * @brief Parameterized constructor for Reminder.
    *
    * Constructs a Reminder object with the specified year, month, day, and task.
    *
    * @param year The year of the reminder.
    * @param month The month of the reminder (1-12).
    * @param day The day of the reminder (1-31).
    * @param task A string representing the task associated with the reminder.
    */
    Reminder(int year, int month, int day, std::string task);

    /**
    * @brief to get the date of the reminder.
    *
    * @return A string representing the date of the reminder in the format  "MM/DD/YYYY".
    */
    std::string getDate() const override;

    /**
     * @brief to get a string representation of the reminder.
     *
     * Returns a detailed description of the reminder, including the date and the associated task.
     *
     * @return A string containing a representation of the reminder.
     */

    std::string toString() const override;

    /**
    * @brief Destructor for Reminder.
    *
    * Cleans up any resources held by the Reminder object.
    */

    ~Reminder() override{}

};


#endif //REMINDER_H
