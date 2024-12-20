#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "Schedulable.h"
#include "Locatable.h"
#include <string>
#include <sstream>
#include <iomanip>


/**
 * @class Appointment
 * This class represents an appointment event and multiple inheritance.
 *
 * The Appointment class is a derived class of both abstract classes (Schedulable and Locatable)
 * It encapsulates a date, a title, and a location for the appointment.
 */
class Appointment: public Schedulable, public Locatable{
private:
    int year;   //The year of the appointment
    int month; //The month of the appointment
    int day;   //The day of the appointment
    std::string title; //The title of the appointment
    std::string location; //The location of the appointment
public:

    /**
    * @brief Default constructor for Appointment.
    *
    * Initializes the appointment to a default date of January 1, 2024, with no title and no location.
    */
    Appointment(): month(1), day(1), year(2024), title("No tittle"), location("No location"){}

    /**
     * @brief Parameterized constructor for Appointment.
     *
     * Constructs an Appointment object with the specified year, month, day, title, and location.
     *
     * @param year The year of the appointment.
     * @param month The month of the appointment (1-12).
     * @param day The day of the appointment (1-31).
     * @param title A string representing the title of the appointment.
     * @param location A string representing the location of the appointment.
     */
    Appointment(int year,int month, int day,  std::string title, std::string location);

    /**
    * @brief to get the date of the appointment.
    *
    * Returns the date of the appointment in the format "MM/DD/YYYY".
    *
    * @return A string representing the date of the appointment.
    */
     std::string getDate() const override;

    /**
    * @brief to get a string representation of the appointment.
    *
    * Returns a detailed description of the appointment, including the date, title, and location.
    *
    * @return A string containing a representation of the appointment.
    */

     std::string toString() const override;

    /**
    * @brief to get the location of the appointment.
    *
    * Returns the location where the appointment will take place.
    *
    * @return A string representing the location of the appointment.
    */
     std::string getLocation() const override;

    /**
    * @brief Virtual Destructor for Appointment.
    *
    * Cleans up any resources held by the Appointment object.
    */
     ~Appointment() override{}

};


#endif //APPOINTMENT_H
