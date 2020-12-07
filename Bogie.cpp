/******************************************************************************
* Bogie.cpp
* CS 281-0798, Fall 2020
*
* Bogie class definition
*******************************************************************************
*/
#include <string>
#include <vector>


#include "Weapon.h"
#include "Room.h"
#include "Bogie.h"

//***********************************************************
// Bogie(string name)
//
// overload constructor
//***********************************************************
Bogie::Bogie(int bId)
{
	m_id = bId;
}

//***********************************************************
// Bogie(string name)
//
// overload constructor
//***********************************************************
Bogie::Bogie() : Bogie(2)
{
}

//***********************************************************
// ~Bogie()
//
// destructor, want bogie to drop weapon and then be
// deleted from memory
//***********************************************************
//Bogie::~Bogie() {}

//***********************************************************
// setId(int id)
//
// set's bogie type
//***********************************************************
bool Bogie::setId(int id)
{
	m_id = id;
	return true;
}

//***********************************************************
// addWeapon(Weapon* pW)
//
// allows bogie to pick up weapon,
// want to set a 50-50 chance of weapon pickup, either in 
// a constructor or app code
//***********************************************************
int Bogie::addWeapon(Weapon* pW)
{
	int n = Container::addWeapon(pW);

	return n;
}

//***********************************************************
// removeWeapon()
//
// allows bogie to drop weapon.
// bogie is holding onto weapon, player makes request for 
// weapon, bogie hands weapon over to player
//***********************************************************
Weapon* Bogie::removeWeapon()
{
	Weapon* pW = Container::removeWeapon();

	return pW;
}