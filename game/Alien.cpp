#include "gameHeader.h"
//=======================================================================================
// Daniel Ndayegamiye
// April 22, 2022
// file name: Alien.cpp
// Programming Assignment #8
// Description: this file holds the definitions of the member functions of the class Alien
//========================================================================================


/*
*  moveAlien - This function is called to handle the alien's move.
*  INPUT: None
*  RETURN: None
*/
void Alien::moveAlien()
{
	int alienX = static_cast<int>(this->getSprite().getPosition().x); // this variable holds the position of the alien 

		//This condition checks to see if the position is less than 0 and the alien goes to the left
	if (alienX > 0 && !isLimit)
		this->move(-ALIEN_DISTANCE, 0);//this moves the alien to the left
	else
	{
		//when the alien reachs 0, it goes back until it reaches the other edge
		isLimit = true; //This becomes true until the alien hits the other edge of the screen
		//This condition check to see if the alien reached the far right edge so it can go back to the left
		if (alienX < (WINDOW_WIDTH - 35))
			this->move(ALIEN_DISTANCE, 0);
		else
			isLimit = false; // this boolean is set to false in case the alien hits the right edge
	}
}

//***********************************************************************************
// Function drawPixie - this function will draw the alien on the screen
// The inputs are:
//					RenderWindow& window - used to draw the pixie on the screen
// return value - no return
void Alien::drawPixie(RenderWindow& window)
{
	// draw the alien on the screen
	window.draw(this->getSprite());
}
