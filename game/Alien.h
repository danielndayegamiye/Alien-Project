#pragma once
#include "gameHeader.h"
//======================================================================
// Daniel Ndayegamiye
// April 22, 2022
// file name: Alien.h
// Programming Assignment #8
// Description: this file holds the class declaration for the Alien class
//=======================================================================

// This class is derived from the Pixie Class and holds the data for the alien
class Alien:public Pixie
{
private:
	bool isLimit; // used to know if the alien reached the edges of the screen
	Alien* nextPointer;// this pointer will hold the next node in the linked list
public:
	// default constructor
    Alien():Pixie("alien.bmp", ALIEN_X_POSITION, ALIEN_Y_POSITION, UNDEFINED_PIXIE)
    {
		isLimit = false;
		nextPointer = nullptr;
    }

	void moveAlien();

	void drawPixie(RenderWindow& window);

	//setters and getters
	Alien* getNext() { return nextPointer; }
	void setNext(Alien* ptr) { nextPointer = ptr; }
};

