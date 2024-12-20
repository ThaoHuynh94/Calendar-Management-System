#include "Meeting.h"


Meeting:: Meeting(int year, int month, int day, std::string title, std::string location):
        year(year), month(month), day(day),title(title), location(location){}


std::string Meeting:: getDate() const
{
    return (month < 10 ? "0" : "") + std::to_string(month) + "/" +
           (day < 10 ? "0" : "") + std::to_string(day) + "/" +
           std::to_string(year);

}
std::string Meeting:: toString() const
{
    std::string listOfAttendees;


    for (const std::string &attendee : attendees)
    {
        listOfAttendees += attendee + " ";
    }

    return "Meeting: " + getDate() + " - Attendees: " + listOfAttendees+" - Titles: "+title+ " - Location: "+ location;
}

std::string Meeting::getLocation()const
{
    return location;
}

void Meeting::addAttendee(std::string attendee)
{
    attendees.push_back(attendee);
}

