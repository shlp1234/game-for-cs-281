/******************************************************************************
* Weapon.h
* CS 281-0798, Fall 2020
*
* Weapon class declaration
*******************************************************************************
*/
#ifndef WEAPON_H
#define WEAPON_H

#include <string>

// base class declaration
#include "CarryIt.h"

//----------------------------------------------------------
// Weapon class derived from base class for carried items
//----------------------------------------------------------
class Weapon : public CarryIt
{
private:
    int m_usesRemaining;
    int m_powerRating;

public:
    Weapon();
    Weapon(std::string wName);
    // Weapon persists for app lifetime
    // so destructor not needed
    //~Weapon();

    bool setUsesRemaining(int uses);
    int getUsesRemaining() const;
    int addUsesRemaining(int uses);

    bool setPower(int power);
    int getPower() const;

    // must implement pure virtual base class member function
    bool setId(int id);

    // must implement pure virtual base class member function
    bool modifyPoints();
};

#endif
