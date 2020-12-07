/******************************************************************************
* app_init_map.cpp
* CS 281 - 0798, Fall 2020
*
* Room map initialization functions
* 
* The Room map is an array of Room pointers in each Room.
* Each Room knows which Room can be accessed in each direction.
* There is no overall map of the Rooms.
*******************************************************************************
*/
#include "app.h"

/******************************************************************************
* void initRoomMap()
*******************************************************************************
*/
void initRoomMap()
{
    // #TODO
    // In this example map, the Nexus is at the center of all other Rooms
    // Customize your Room map according to your game design
    g_pStaging = initStaging();
    g_pClothing = initClothing();
    g_pFurniture = initFurniture();
    g_pElectronics = initElectronics();
    g_pCheckout = initCheckout();

    // set the room map initialization pointers
    g_pStaging->setDirectionPtr(ROOM_NORTH, g_pStaging);
    g_pStaging->setDirectionPtr(ROOM_SOUTH, g_pStaging);
    g_pStaging->setDirectionPtr(ROOM_WEST, g_pClothing);
    g_pStaging->setDirectionPtr(ROOM_EAST, g_pStaging);

    g_pClothing->setDirectionPtr(ROOM_NORTH, g_pElectronics);
    g_pClothing->setDirectionPtr(ROOM_SOUTH, g_pClothing);
    g_pClothing->setDirectionPtr(ROOM_WEST, g_pFurniture);
    g_pClothing->setDirectionPtr(ROOM_EAST, g_pStaging);

    g_pFurniture->setDirectionPtr(ROOM_NORTH, g_pFurniture);
    g_pFurniture->setDirectionPtr(ROOM_SOUTH, g_pFurniture);
    g_pFurniture->setDirectionPtr(ROOM_WEST, g_pFurniture);
    g_pFurniture->setDirectionPtr(ROOM_EAST, g_pClothing);

    g_pElectronics->setDirectionPtr(ROOM_NORTH, g_pElectronics);
    g_pElectronics->setDirectionPtr(ROOM_SOUTH, g_pClothing);
    g_pElectronics->setDirectionPtr(ROOM_WEST, g_pElectronics);
    g_pElectronics->setDirectionPtr(ROOM_EAST, g_pCheckout);

    g_pCheckout->setDirectionPtr(ROOM_NORTH, g_pCheckout);
    g_pCheckout->setDirectionPtr(ROOM_SOUTH, g_pCheckout);
    g_pCheckout->setDirectionPtr(ROOM_WEST, g_pElectronics);
    g_pCheckout->setDirectionPtr(ROOM_EAST, g_pCheckout);
}
