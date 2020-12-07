/******************************************************************************
* Bogie.h
* CS 281-0798, Fall 2020
*
* Bogie class declaration
*******************************************************************************
*/
#ifndef BOGIE_H
#define BOGIE_H

#include <string>
#include <vector>

#include "Weapon.h"
#include "Container.h"

class Bogie : public Container
{
	private:

	public:
		Bogie();
		Bogie(int bId);
		// Bogie() instances will persist for app lifetime
		// so destructor not needed
		//~Bogie();

		bool setId(int id);

		// Weapon management support, bogie can pick up/drop weapon
		// player/customer can ask for 'Cart' weapon and bogie will
		// drop
		int addWeapon(Weapon* pW);
		Weapon* removeWeapon();
};

#endif

