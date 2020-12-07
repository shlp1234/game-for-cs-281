/******************************************************************************
* app_init_rooms.cpp
* CS 281 - 0798, Fall 2020
*
* Room initialization functions
*   - set Room entry text, exit text, direction text
*   - install Treasures in Room Treasure vector or in Room mixed vector
*   - install Weapons in Room Weapon vector or in Room mixed vector
* #TODO
*   - install bogies in Room Bogie vector
*   - install magic words in Room MagicWord vector
*******************************************************************************
*/
#include <cstdlib>

#include "app.h"

/******************************************************************************
* Room* initStaging()
*******************************************************************************
*/
Room* initStaging()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "the Staging Room";
    pRoom->setName(str);

    str = "Entering the Staging Room. The crystal floor shines brightly.";       
    pRoom->setEntryText(str);

    str = "You are leaving the Staging Room.";
    pRoom->setExitText(str);

    str = "Nothing to the north";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Nothing to the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Nothing to the east";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Clothing Department to the west";
    pRoom->setDirectionText(ROOM_WEST, str);

    // create and initialize Treasure instance
    Weapon* pWeapon = new Weapon();
    str = "Cart";
    pWeapon->setId(1);
    pWeapon->setName(str);
    pWeapon->setPoints(50);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addWeapon(pWeapon);

    return pRoom;
}

/******************************************************************************
* Room* initClothing()
*******************************************************************************
*/
Room* initClothing()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "the Clothing Department";
    pRoom->setName(str);

    str = "Welcome to the Clothing Department. A wall of ice chills the air.";
    pRoom->setEntryText(str);

    str = "You are emerging from the Clothing Department.";
    pRoom->setExitText(str);

    str = "Electronics to the north";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Nothing to the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Staging Room to the east";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Furniture Department to the west";
    pRoom->setDirectionText(ROOM_WEST, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Designer Clothes(basic)";
    pTreasure->setId(1);
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Bargains(MagicWord)";
    pWeapon->setName(str);
    pWeapon->setPoints(50);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    return pRoom;
}

/******************************************************************************
* Room* initFurniture()
*******************************************************************************
*/
Room* initFurniture()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(200);

    std::string str = "the Furniture Department";
    pRoom->setName(str);

    str = "Entering the Furniture Department. Cool water laps your toes.";
    pRoom->setEntryText(str);

    str = "You turn away from Furniture.";
    pRoom->setExitText(str);

    str = "Nothing to the north";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Nothing to the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Clothing Department to the east";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Nothing to the west";
    pRoom->setDirectionText(ROOM_WEST, str);

    // create and initialize Treasure instances
    Treasure* pTreasure = new Treasure();
    str = "Premium Bed(Premium)";
    pTreasure->setId(2);
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // same as above
    pTreasure = new Treasure();
    str = "Leather Sofa(basic)";
    pTreasure->setId(1);
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    pRoom->addTreasure(pTreasure);

    return pRoom;
}

/******************************************************************************
* Room* initElectronics()
*******************************************************************************
*/
Room* initElectronics()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(150);

    std::string str = "the shimmering Electronics Department";
    pRoom->setName(str);

    str = "Electronics Department. Circuit boards crowd the desert landscape.";
    pRoom->setEntryText(str);

    str = "You turn away from the Electronic's crunchy mess of E-waste";
    pRoom->setExitText(str);

    str = "Nothing to the north";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Clothing Department to the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Checkout to the east";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Nothing to the west";
    pRoom->setDirectionText(ROOM_WEST, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Blu-ray Player(basic)";
    pTreasure->setId(1);
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // same as above
    pTreasure = new Treasure();
    str = "HDTV(premium)";
    pTreasure->setId(2);
    pTreasure->setName(str);
    pTreasure->setPoints(150);

    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Cart";
    pWeapon->setId(2);
    pWeapon->setName(str);
    pWeapon->setPoints(50);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    return pRoom;
}

/******************************************************************************
* Room* initCheckout()
*******************************************************************************
*/
Room* initCheckout()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(50);

    std::string str = "a high pass in Checkout";
    pRoom->setName(str);

    str = "Are you ready to Checkout? Press C to return carts.";
    pRoom->setEntryText(str);

    str = "You gingerly descend from your perch high in Checkout.";
    pRoom->setExitText(str);

    str = "Nothing to the north";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Nothing to the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Nothing to the east";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Electronics Department to the west";
    pRoom->setDirectionText(ROOM_WEST, str);

    return pRoom;
}