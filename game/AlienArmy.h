#pragma once
#include "gameHeader.h"
//======================================================================
// Daniel Ndayegamiye
// April 22, 2022
// file name: AlienArmy.h
// Programming Assignment #8
// Description: this file holds the class declaration for the AlienArmy class
//=======================================================================


class AlienArmy
{
private:
	Alien* head; // the head of the Linked List
	bool isLimit; // this boolean checks to see if the missile thrown by the ship hit the army
	int countAlien; // this variable keeps the count of how many aliens are left on the screen
	int missileY; // this variable holds the height of the alien firing the missile
public:
	// constructor
	AlienArmy();
	// appending node to the list
	void append(Alien* newNodePtr);
	// drawing the army to the screen
	void drawList(RenderWindow& window);
	// moving army on the screen
	void moveArmy(int& counter);
	// checking if the army was hit by a missile
	bool MissileChecking(Pixie& missile);
	// deleting alien hit by a missile
	void deleteAlien(int num);
	// checking the height of the army
	void checkShipY(Pixie& ship);
	// getter of the width of the alien firing the missile
	int getAlienX();
	// getter of the height of the alien firing the missile
	int getAlienY()
	{
		return missileY;
	}
	// checking if the list is empty
	bool isListEmpty();

};

