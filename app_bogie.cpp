/******************************************************************************
* app_bogie.cpp
* CS 281 - 0798, Fall 2020
*
* Bogie initialization and management functions
*******************************************************************************
*/
#include <sstream>
#include <vector>

#include "app.h"

/******************************************************************************
* grabWeapon()
*
* transfer Weapon from Room to Bogie
* add messages to caller's vector for display
*******************************************************************************
*/
bool grabWeapon(Bogie* pBogie, Room* pRoom, std::vector<std::string>& msgQ)
{
    Weapon* pWeapon = pRoom->removeWeapon();

    if (pWeapon == nullptr)
    {
        msgQ.push_back("There's no weapon here.");
        return false;
    }

    pBogie->addWeapon(pWeapon);
    std::string str;
    pWeapon->getName(str);

    // build message string with string stream
    std::stringstream ss;
    ss << "Store Associate took " << str << " worth "
        << pWeapon->getPoints() << " points";

    // copy completed message string to caller's vector
    msgQ.push_back(ss.str());

    return true;
}

/******************************************************************************
* dropWeapon()
*
* transfer Weapon from Bogie to Room
* fill caller's vector with message strings for display
*******************************************************************************
*/
bool dropWeapon(Bogie* pBogie, Room* pRoom, std::vector<std::string>& msgQ)
{
    Weapon* pWeapon = pBogie->removeWeapon();

    if (pWeapon == nullptr)
    {
        msgQ.push_back("Your pockets are empty!");
        return false;
    }

    // transfer Weapon from Bogie to Room
    pRoom->addWeapon(pWeapon);

    // for queueing display message
    std::string str;
    pWeapon->getName(str);

    msgQ.push_back("Bogie dropped a " + str);

    return true;
}

/******************************************************************************
* bogieMessage()
*
* displays entry/exit and related text for bogie
*******************************************************************************
*/
bool bogieMessage(Bogie* pBogie, char cmd, std::vector<std::string>& msgQ)
{
    if (cmd == 'a')
        msgQ.push_back("Store Associate(bogie) has entered.");
    else if (cmd == 'd' && pBogie->getWeaponCount() != 0)
        msgQ.push_back("Store Associate(bogie) has left.");
    else if (cmd == 'h' && pBogie->getWeaponCount() > 0)
        msgQ.push_back("You might need a Cart or two. (Hint)");
    else
        msgQ.push_back("Store Associate(bogie) is helping other customers.");

    return true;
}