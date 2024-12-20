#include "Appointment.h"


Appointment:: Appointment(int year,int month, int day, std::string title, std::string location):
year(year), month(month), day(day), title(title), location(location){}


std::string Appointment::getDate() const
{
    return (month < 10 ? "0" : "") + std::to_string(month) + "/" +
           (day < 10 ? "0" : "") + std::to_string(day) + "/" +
           std::to_string(year);

}

std::string Appointment::toString() const
{

    return "Appointment: " + getDate() + " - Title: " + title + ", Location: " + location;
}

std::string Appointment::getLocation() const
{
    return location;
}

