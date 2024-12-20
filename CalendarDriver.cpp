#include <iostream>
#include "Appointment.h"
#include "Meeting.h"
#include "Reminder.h"
#include "Calendar.h"
#include <limits>


const int REMINDER_OPTION       = 1; // Option for creating a reminder
const int MEETING_OPTION        = 2; // Option for creating a meeting
const int APPOINTMENT_OPTION    = 3; // Option for creating an appointment
const int DISPLAY_OPTION        = 4; // Option for displaying events
const int EXIT_OPTION           = 5; // Option for exiting the program

// Function prototypes
/**
 * @brief to creates a reminder in the calendar.
 * @param calendar Pointer to the Calendar object to add the reminder.
 */
void createReminder(Calendar*);


/**
 *@brief to create a meeting in the calendar.
 * @param calendar Pointer to the Calendar object to add the meeting.
 */
void createMeeting(Calendar*);

/**
 * @brief to create an appointment in the calendar.
 * @param calendar Pointer to the Calendar object to add the appointment.
 */
void createAppointment(Calendar*);


/**
 *@brief to display events for a specific date in the calendar.
 * @param calendar Pointer to the Calendar object to retrieve events.
 */
void displayEvents(Calendar*);


/**
 * @brief to display the menu of options to the user and handles their choices.
 * Choices: create reminders, meetings, appointments, display events, or exit the program.
 *
 * @param calendar Pointer to the Calendar object that stores events.
 *
 * @return true if the user chooses to exit the program;
 *         otherwise returns false to continue the main loop and get user input
 */
bool showMenu(Calendar*);


int main()
{

    Calendar calendar; // Create a Calendar object

    while (true)
    {
        if(showMenu(&calendar))
        {
            break; // Exit the loop if the user chooses to exit
        }
    }

    // The destructor for 'calendar' will automatically be called to delete all the events added to it.

    return 0;
}

void createReminder(Calendar* calendar)
{
    int month, day, year; // Variables to store the date
    std::string task;     // Variable to store the task for the reminder

    std::cout << "Enter the day, month, year for the reminder: ";
    // Input validation for date
    while (!(std::cin >> day >> month >> year) || (day < 1 || day > 31) ||
           (month < 1) || (month > 12) || (year < 0))
    {
        std::cout << "Invalid input! Please try again: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    }

    std::cout << "Enter the task for the reminder: ";
    std::cin.ignore(); // Ignore leftover newline from previous input
    std::getline(std::cin, task); // Use getline to allow spaces in task

    Reminder* reminder = new Reminder(year, month, day, task); // Create a new reminder
    calendar->addEvent(reminder); // Add the reminder to the calendar
}

void createMeeting(Calendar* calendar)
{
    int month, day, year; // Variables to store the date
    int attendeeNum;      // Variable to store the number of attendees
    std::string attendeeNames; // Variable to store attendee names
    std::string title, location; // Variables to store title and location of the meeting

    std::cout << "Enter the day, month, year for the meeting: ";
    // Input validation for date
    while (!(std::cin >> day >> month >> year) || (day < 1 || day > 31) ||
           (month < 1) || (month > 12) || (year < 0))
    {
        std::cout << "Invalid input! Please try again: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    }

    std::cout << "Enter the title for the meeting: ";
    std::cin.ignore(); // Ignore leftover newline from previous input
    std::getline(std::cin, title); // Use getline to allow spaces in title

    std::cout << "Enter the location for the meeting: ";
    std::getline(std::cin, location); // Use getline for location

    Meeting* meeting = new Meeting(year, month, day, title, location); // Create a new meeting

    std::cout << "How many attendees? ";
    // Input validation for number of attendees
    while (!(std::cin >> attendeeNum) || attendeeNum < 0)
    {
        std::cout << "Invalid input! Please try again: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    }

    // Input attendees' names
    for (int i = 0; i < attendeeNum; i++)
    {
        std::cout << "Enter #" << (i + 1) << " attendee's name: ";
        std::cin >> attendeeNames; // Enter the attendee's name
        meeting->addAttendee(attendeeNames); // Add attendee to the meeting
    }

    calendar->addEvent(meeting); // Add the meeting to the calendar
}


void createAppointment(Calendar* calendar)
{
    int month, day, year; // Variables to store the date
    std::string title, location; // Variables to store title and location of the appointment

    std::cout << "Enter the day, month, year for the appointment: ";
    // Input validation for date
    while (!(std::cin >> day >> month >> year) || (day < 1 || day > 31) ||
           (month < 1) || (month > 12) || (year < 0))
    {
        std::cout << "Invalid input! Please try again: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    }

    std::cout << "Enter the title for the appointment: ";
    std::cin.ignore(); // Ignore leftover newline
    std::getline(std::cin, title); // Use getline to allow spaces in title

    std::cout << "Enter the location for the appointment: ";
    std::getline(std::cin, location); // Use getline for location

    Appointment* appointment = new Appointment(year, month, day, title, location); // Create a new appointment
    calendar->addEvent(appointment); // Add the appointment to the calendar
}

void displayEvents(Calendar* calendar)
{
    std::string date; // Variable to store the date input

    std::cout << "Enter the date in MM/DD/YYYY format to check your calendar (Ex: 12/12/2012): ";
    std::cin >> date; // Read the date input

    // Get events for the given date
    std::string events = calendar->getDaysEvents(date);

    // Check if there are any events for the entered date
    if (events.empty()) {
        std::cout << "No events for " << date << std::endl; // Notify if no events
    } else {
        std::cout << "Events on " << date << ":\n" << events; // Display events
    }
}


bool showMenu(Calendar* calendar)
{


    int choice; // Variable to store user input

    std::cout << "\nMenu Options:\n";
    std::cout << "1. Create Reminder\n";
    std::cout << "2. Create Meeting\n";
    std::cout << "3. Create Appointment\n";
    std::cout << "4. Display Events\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";

    // Loop until valid input
    while (true)
    {
        std::cin >> choice; // Read user choice

        // Input validation for choice
        if (std::cin.fail() || choice < REMINDER_OPTION || choice > EXIT_OPTION)
        {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid choice. Please enter a number between " << REMINDER_OPTION
                      << " and " << EXIT_OPTION << ": ";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore leftover input
            break; // Valid input, exit the loop
        }
    }

        // Handle user choices
        switch (choice)
        {
            case REMINDER_OPTION:
                {createReminder(calendar); // Call function to create a reminder
                break;}
            case MEETING_OPTION:
                {createMeeting(calendar); // Call function to create a meeting
                break;}
            case APPOINTMENT_OPTION:
                {createAppointment(calendar); // Call function to create an appointment
                break;}
            case DISPLAY_OPTION:
                {displayEvents(calendar); // Call function to display events
                break;}
            case EXIT_OPTION:
                {std::cout << "Exiting the calendar!" << std::endl; // Notify exit
                return true;}  //exit the main loop
            default:
                return false; // Unreachable but kept for safety
        }

    return false;   //continue the main loop to get user input
}
