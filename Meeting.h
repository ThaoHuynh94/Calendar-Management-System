#ifndef MEETING_H
#define MEETING_H
#include <sstream>
#include <iomanip>
#include <vector>
#include "Schedulable.h"
#include "Locatable.h"


/**
 * @class Meeting
 * This class represents a meeting event and multiple inheritance.
 *
 * The Meeting class is a derived class of both abstract classes (Schedulable and Locatable)
 * It encapsulates a date, a title, a location, and a list of attendees.
 */

class Meeting :public Schedulable, public  Locatable{
private:
    int month; //The month of the meeting
    int year; //The year of the meeting
    int day;  //The day of the meeting
    std::string title;      //The title of the meeting
    std::string location;   //The location of the meeting
    std:: vector<std::string> attendees;  // List of attendees for the meeting.

public:
    /**
    * @brief Default constructor for Meeting.
    *
    * Initializes the meeting to a default date of January 1, 2024, with no title and no location.
    */
    Meeting():  day(1), month(1), year(2024), title("No title"), location("No location"){}


    /**
     * @brief Parameterized constructor for Meeting.
     *
     * Constructs a Meeting object with the specified year, month, day, title, and location.
     *
     * @param year The year of the meeting.
     * @param month The month of the meeting (1-12).
     * @param day The day of the meeting (1-31).
     * @param title A string representing the title of the meeting.
     * @param location A string representing the location of the meeting.
     */
    Meeting(int year, int month, int day, std::string title, std::string location);

    /**
    * @brief to get the date of the meeting.
    *
    * @return A string representing the date of the meeting in the format "MM/DD/YYYY"
    */
     std::string getDate() const override;

    /**
    * @brief to get a string representation of the meeting.
    *
    * Returns a detailed description of the meeting, including the date
    * and the list of attendees.
    *
    * @return A string containing a representation of the meeting.
    */
     std::string toString() const override;

    /**
    * @brief Get the location of the meeting.
    *
    * Returns the location where the meeting will take place.
    *
    * @return A string representing the location of the meeting.
    */
     std::string getLocation()const override;

    /**
    * @brief to add an attendee to the meeting.
    *
    * This function adds the specified attendee's name to the list of attendees.
    *
    * @param attendee A string representing the name of the attendee to add.
    */

     void addAttendee(std::string attendee);


    /**
     * @brief Virtual Destructor for Meeting.
     *
     * Cleans up any resources held by the Meeting object.
     */

     ~Meeting() override{}

};


#endif //MEETING_H
