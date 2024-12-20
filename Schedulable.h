#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H
#include <string>


/**
 * @class Schedulable - an abstract base class representing a schedulable event.
 *
 * The Schedulable class provides an interface for all events
 * that have a date and can be represented as a string.
 * This class cannot be instantiated directly and must be derived by classes
 * such as Reminder, Appointment, and Meeting.
 */
class Schedulable {
public:
    /**
     * @brief to get the date of the event.
     *
     * This pure virtual function must be implemented by derived classes
     * to return the date in the format "MM/DD/YYYY".
     *
     * @return A string representing the date of the event.
     */
    virtual std::string getDate() const = 0;


    /**
     * @brief to get a string representation of the event.
     *
     * This pure virtual function must be implemented by derived classes
     * to provide a detailed description of the event.
     *
     * @return A string containing a representation of the event.
     */
    virtual std::string toString() const = 0;

    /**
    * @brief Virtual destructor for Schedulable class.
    *
    * Ensures proper cleanup of derived class resources when an object is deleted
    * through a base class pointer.
    */

    virtual ~Schedulable(){}
};


#endif //SCHEDULABLE_H
