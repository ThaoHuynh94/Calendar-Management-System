#include "Reminder.h"


Reminder::Reminder(int year, int month, int day, std::string task):
year(year), month(month), day(day), task(task){}


std::string Reminder:: getDate() const
{
    return (month < 10 ? "0" : "") + std::to_string(month) + "/" +
           (day < 10 ? "0" : "") + std::to_string(day) + "/" +
           std::to_string(year);
}


std::string Reminder:: toString() const
{
    return "Reminder: " + getDate() + " - Task: " + task;
}
