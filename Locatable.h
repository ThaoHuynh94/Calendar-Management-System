#ifndef LOCATABLE_H
#define LOCATABLE_H
#include <string>


/**
 * @class Locatable -  an abstract class that defines a pure virtual function to get location
 * This class cannot be instantiated directly and must be derived by classes
 * such as Appointment and Meeting.
 */


class Locatable {
public:
    /**
    * @brief to get the location of the object.
    *
    * This pure virtual function should be implemented by derived classes
    * to return the location of the object as a string.
    *
    * @return A string representing the location of the object.
    */
    virtual std::string getLocation() const =0;


    /**
    * @brief Virtual destructor for proper cleanup of derived classes.
    *
    * This virtual destructor ensures that destructors of derived classes
    * are called correctly when an object is deleted through a pointer
    * to the base class.
    */
    virtual ~Locatable(){}

};


#endif //LOCATABLE_H
