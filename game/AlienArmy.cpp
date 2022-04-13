#include "AlienArmy.h"
//===========================================================================================
// Daniel Ndayegamiye
// April 22, 2022
// file name: AlienArmy.cpp
// Programming Assignment #8
// Description: this file holds the definitions of the member functions of the class AlienArmy
//============================================================================================


//***********************************************************************************
// Function AlienArmy - this is the default constructor for the AlienArmy class
// There are no input for it
AlienArmy::AlienArmy()
{
	int counterWidth = 0; // this variable is the counter supposed to increment the width for the position of the alien in the army
	Alien* alienPtr = new Alien();// allocating or creating an alien to add to the army
	// this for loop adds as many aliens as required
	while (counterWidth < 600)
	{
		// calling of the append function and add the alien to the army
		append(alienPtr);
		// increment
		counterWidth += 60;
		// creating a new alien
		alienPtr = new Alien();
		// setting the position for the new alien but increase the x position for it
		alienPtr->setPosition(alienPtr->getPixieX() + counterWidth, alienPtr->getPixieY());
	}
	// initialization of the member variables
	isLimit = false; 
	countAlien = 10; // there is only 10 aliens in the game 
	missileY = 0;
}

//***********************************************************************************
// Function append - this is an append function for the AlienArmy class
// The input is newNodePtr which will be the new alien to be added to the list
void AlienArmy::append(Alien* newNodePtr)
{
	Alien* nodePtr; // To move through the list
	//If there are no nodes in the list
	// make newNode the first node.
	if (!head)
	{
		head = newNodePtr;
	}
	else // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;
		// Find the last node in the list.
		while (nodePtr->getNext() != nullptr)
		{
			nodePtr = nodePtr->getNext();
		}
		// Insert newNode as the last node.
		nodePtr->setNext(newNodePtr);
	}
}

//***********************************************************************************
// Function drawList - this function will draw the army on the screen
// The inputs are:
//					RenderWindow& window - used to draw the army  on the screen
// return value - no return

void AlienArmy::drawList(RenderWindow& window) {
	Alien* pixiePtr; // To move through the list

	// Initialize pixiePtr to head of list.
	pixiePtr = head;

	// Draw the alien until you reach the last one
	while (pixiePtr != nullptr)
	{
		pixiePtr->drawPixie(window);
		pixiePtr = pixiePtr->getNext();
	}
}

/*
*  moveArmy - This function is called to handle the movement of the army
*  INPUT: The integer counter handling the incrementation of the height along the way
*  RETURN: None
*/
void AlienArmy::moveArmy(int& counter) {
	Alien* pixiePtr; // To move through the list
	//If there are no nodes in the list
	// bail out.
	if (!head)
		return;
	else // Otherwise, move the army.
	{
		// Initialize pixiePtr to head of list.
		pixiePtr = head;

		// Move the aliens until you reach the last one
		while (pixiePtr != nullptr)
		{
			// setting the height of the alien at the beginning of the loop in case the height of the army have to change
			pixiePtr->setPixieY(ALIEN_Y_POSITION + counter);
			int alienX = static_cast<int>(pixiePtr->getSprite().getPosition().x); // this variable holds the position of the alien 

			//This condition checks to see if the position is less than 0 and the alien goes to the left
			if (alienX > 0 && !isLimit)
				pixiePtr->move(-ALIEN_DISTANCE, 0);//this moves the alien to the left
			else
			{
				//when the alien reachs 0, it goes back until it reaches the other edge
				isLimit = true; //This becomes true until the alien hits the other edge of the screen
				//This condition check to see if the alien reached the far right edge so it can go back to the left
				if (alienX < (WINDOW_WIDTH - 35))
					pixiePtr->move(ALIEN_DISTANCE, 0);
				else
				{

					isLimit = false;// this boolean is set to false in case the alien hits the right edge

					pixiePtr->move(ALIEN_DISTANCE, 0);// because when it hits the edge it would move position..
													  //.here I am making sure that it still goes on the other side
					counter += 30; // we change the height of the whole army when it reaches the right edge
				}
			}
			// Moving the pointer through the list
			pixiePtr = pixiePtr->getNext();
		}

	}
}

/*
*  MissileChecking - This function is called to check if the missile thrown by the ship hit the army
*  INPUT: The pixie missile is passed
*  RETURN: Boolean: true if the missile hit the army or not
*/
bool AlienArmy::MissileChecking(Pixie& missile) {
	Alien* pixiePtr; // To move through the list
	FloatRect missileBounds = missile.getSprite().getGlobalBounds(); // check the bounds of the missile
	if (!head)
		cout << "The List is Empty\n\n";
	else
	{
		// Initialize pixiePtr to head of list.
		pixiePtr = head;
		// Move through the linked list checking if the missile hit any of the alien in the army
		while (pixiePtr != nullptr)
		{
			FloatRect alienBounds = pixiePtr->getSprite().getGlobalBounds(); // check the bounds of the alien
			// if the missile hits the alien, erase the alien from the screen and return tre
			if (missileBounds.intersects(alienBounds))
			{
				deleteAlien(pixiePtr->getID());
				return true;
			}
			// moving to the next alien in the list
			pixiePtr = pixiePtr->getNext();
		}
	}
	return false;
}

//***********************************************************************************
// Function deleteAlien - this is a delete function for the AlienArmy class for whenever the alien is hit
// The input is the integer num holding the ID of the alien hit by the missile
// return: None
void AlienArmy::deleteAlien(int num)
{
	Alien* nodePtr; // To traverse the list
	Alien* previousNode = nullptr; // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;
	// Determine if the first node is the one and reduce the number of alien on the screen
	if (head->getID() == num)
	{
		nodePtr = head->getNext();
		delete head;
		countAlien--;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is
	   // not equal to num.
		while (nodePtr != nullptr && nodePtr->getID() != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->getNext();
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr and reduce the number of aliens
		if (nodePtr)
		{
			previousNode->setNext(nodePtr->getNext());
			delete nodePtr;
			countAlien--;
		}
	}
}

//***********************************************************************************
// Function checkShipY - this function checks to see if the army reached the ship position
// The input: the pixie ship is passed
// return: None
void AlienArmy::checkShipY(Pixie& ship)
{
	// Initialize pixiePtr to head of list.
	Alien* pixiePtr = head; 
	// Check to see if the army is on the same level as the ship
		if (pixiePtr->getPixieY() >= ship.getPixieY())
		{
			cout << "Game Over!!!\n";
			exit(0);
		}
}

//***********************************************************************************
// Function getAlienX - this function gets the x position of the alien to fire the missile
// The input: the pixie ship is passed
// return: integer holding the X position
int AlienArmy::getAlienX()
{
	// Initialize pixiePtr to head of list.
	Alien* alienPtr = head;
	// choose a random alien to fire the missile according to their ID
	int number = rand() % countAlien + 2;
	// Move through the linked list to find the alien that was chosen
	while (alienPtr->getNext() != nullptr)
	{
		// Find the alien and initialize the missile to be shoot by its position
		if (number == alienPtr->getID())
		{
			missileY = alienPtr->getPixieY();
			return alienPtr->getPixieX();
		}
		alienPtr = alienPtr->getNext();
	}

}

//**********************************************************************************
// Function isListEmpty - this function checks to see if there is no more alien left in the army
// The input: None
// return: Boolean: true if the list is empty
bool AlienArmy::isListEmpty()
{
	// if the list is empty return true otherwise return false
	if (!head)
		return true;
	else
		return false;
}