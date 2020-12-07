/******************************************************************************
* app.cpp
* CS 281 - 0798, Fall 2020
*
* App main with entry point main()
* New features: 'A)sk' calls up bogie and bogie will pick up weapons.
* 'F)ork over' will get bogie to drop weapons so player can pick them up.
*******************************************************************************
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

// app common include file
#include "app.h"

// local function prototypes
void displayMessageQueue(std::vector<std::string>& msgQueue);
int mapMoveCommand(char cmd);
char menuOption();

// global variables available (extern) to all app code
Room* g_pStaging          = nullptr;
Room* g_pClothing      = nullptr;
Room* g_pFurniture    = nullptr;
Room* g_pElectronics  = nullptr;
Room* g_pCheckout = nullptr;

/******************************************************************************
* int main()
* entry point
*******************************************************************************
*/
int main()
{
    // accumulate messages for display each game loop iteration
    std::vector<std::string> messageQueue;

    // init game rooms with text, Treasure, and Weapons
    g_pStaging = initStaging();
    g_pClothing = initClothing();
    g_pFurniture = initFurniture();
    g_pElectronics = initElectronics();
    g_pCheckout = initCheckout();
    // init game rooms done

    // all global pointers now valid for use as Room map pointers
    initRoomMap();

    // #TODO put Player in starting Room of your choice
    // set utility pointer used throughout app main()
    Room* pRoom = g_pStaging;

    // all-purpose string and message buffer
    std::string str;
    std::string playerName;

    // #TODO your game name goes here
    std::cout << "\nCS 281 Fall 2020 Game Project\n";
    std::cout << "What's your name? ";
    std::cin >> playerName;

    // display app version
    messageQueue.push_back("Welcome " + playerName + "!\n");

    // create Player, award Room points,
    // and queue messages for display
    Player* pPlayer = new Player(playerName);
    visitRoom(pPlayer, pRoom, messageQueue);

    // display things Player sees in this Room
    getInventory(pRoom, messageQueue);

    // display queued messages and clear queue
    displayMessageQueue(messageQueue);

    // one-character command from user cin >> userCmd
    char userCmd;
    int direction = ROOM_DEAD_END;

    // temp Room pointer for Player "movement"
    Room* pNextRoom = nullptr;

    // Bogie will always exist, calls to Bogie functions/text will make it
    // appear Bogie is entering and leaving
    Bogie* pBogie = new Bogie();

// main app loop: display game menu, handle user command
    do
    {
        userCmd = menuOption();

// handle move commands first
        // translate char command to int direction constant
        direction = mapMoveCommand(userCmd);
        if (direction != ROOM_DEAD_END)
            pRoom = movePlayer(pPlayer, pRoom, direction, messageQueue);
        // L)ook command
        else if (userCmd == 'l')
            lookAllDirections(pRoom, messageQueue);
        // G)et treasure command
        else if (userCmd == 'g')
        {
            if (pPlayer->getWeaponCount() != 0)
            {
                // local variables for treasure/weapon id number matching
                Treasure* l_treasure = pRoom->selectTreasure();
                Weapon* l_weapon = nullptr;

                if (l_treasure != nullptr)
                {   // l_treasure returns id type, pPlayer finds weapon that matches
                    // doesn't work as intended, section is broken
                    l_weapon = pPlayer->selectWeapon(l_treasure->getId());

                    // weapon type must be greater than treasure type before player can
                    // pick it up
                    if ((l_weapon) && (l_weapon->getId() >= l_treasure->getId()))
                        grabTreasure(pPlayer, pRoom, messageQueue);
                    else // display messages based on weapon/treasure scenario
                        messageQueue.push_back("Need the right weapon to pick that up.\n");
                }
                else
                    messageQueue.push_back("No treasure here.\n");
            }
            else
                messageQueue.push_back("Need a weapon.\n");
        }
        // dR)op treasure command
        else if (userCmd == 'r')
            dropTreasure(pPlayer, pRoom, messageQueue);
        // T)ake weapon command
        else if (userCmd == 't')
            grabWeapon(pPlayer, pRoom, messageQueue);
        // U)seless weapon command
        else if (userCmd == 'u')
            dropWeapon(pPlayer, pRoom, messageQueue);
        // A)sk for assistance
        else if (userCmd == 'a')
        {
            bogieMessage(pBogie, userCmd, messageQueue);
            grabWeapon(pBogie, pRoom, messageQueue);
        }
        // D)rop weapon, so player can pick up weapon
        else if (userCmd == 'd')
        {
            bogieMessage(pBogie, userCmd, messageQueue);
            dropWeapon(pBogie, pRoom, messageQueue);
        }
        else if (userCmd == 'h')
        {
            bogieMessage(pBogie, userCmd, messageQueue);
        }
        // T)ake weapon command
        else if (userCmd == 'f' && pBogie->getWeaponCount() > 0)
            dropWeapon(pBogie, pRoom, messageQueue);
        // B)argains magic word
        else if (userCmd == 'b')
            bargains(pRoom, messageQueue);
        // C)arts use to allow player to return carts at the end.
        else if (userCmd == 'c')
            loseWeapon(pPlayer, messageQueue);
        // I)nfo command
        else if (userCmd == 'i')
            getAllInfo(pPlayer, pRoom, messageQueue);
// Q)uit command 
        else if (userCmd == 'q')
            messageQueue.push_back("Leaving so soon?");
// handle bad input
        else
            messageQueue.push_back("\aSorry, I don't know that command.");

// display after every iteration
        if (userCmd != 'i' && userCmd != 'q')
            getInventory(pRoom, messageQueue);

        displayMessageQueue(messageQueue);

    } while (userCmd != 'q');
// end main input loop

    // status display and farewell to Player
    getInfo(pPlayer, pRoom, messageQueue);
    messageQueue.push_back("\nGoodbye " + playerName + "!\n");
    displayMessageQueue(messageQueue);

    system("pause");

   return 0;
}

/******************************************************************************
* displayMessageQueue()
*
* display queued messages and clear queue
*
*******************************************************************************
*/
void displayMessageQueue(std::vector<std::string>& msgQ)
{
    std::cout << std::endl;

    // add a newline after each queued message 
    for (std::string msg : msgQ)
        std::cout << msg << "\n";

    // reset queue for next iteration
    msgQ.clear();
 }

/******************************************************************************
* mapMoveCommand()
*
* assumes parameter is lower case
* 
* if passed command char is a move command,
* return the direction constant
* 
* otherwise return ROOM_DEAD_END
* 
* #TODO add custom direction mappings here
*******************************************************************************
*/
int mapMoveCommand(char cmd)
{
    if (cmd == 'n')         // n)orth
        return ROOM_NORTH;   
    if (cmd == 's')         // s)outh
        return ROOM_SOUTH;
    if (cmd == 'e')         // e)ast
        return ROOM_EAST;
    if (cmd == 'w')         // w)est
        return ROOM_WEST;

    // this is not a move command!
    return ROOM_DEAD_END;
}

/******************************************************************************
* char menuOption()
*
* display menu and prompt
* 
* return lower case user command
*
*******************************************************************************
*/
char menuOption()
{
    char cmd;
    
    // display game menu
    std::cout << std::endl;
    std::cout << "N)orth, S)outh, E)ast, W)est, I)nfo, L)ook,\n";
    std::cout << "G)et treasure, dR)op treasure, T)ake weapon,\n";
    std::cout << "U)seless weapon, A)ssistance, H)int, D)ismiss,\n";
    std::cout << "F)ork Over, B)argains, C)arts, Q)uit ?";

    // get user command
    std::cin >> cmd;
    
    // lower case simplifies command handling
    cmd = tolower(cmd);

    return cmd;
}

