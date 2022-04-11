#include "gameHeader.h"
//===================================================== 
// Daniel Ndayegamiye
// February 21, 2022
// file name: gameFunctions.cpp
// Programming Assignment #3
// Description: this file holds the functions used in the game
//=====================================================


// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen

/*
*  moveShip - This function is called to handle a keyPress event. 
*     Keyboard input is detected and ship is moved.
*   ** Part of the lab is to also handle firing a missile **
*  INPUT: The ship sprite is passed.  This merely a drawn object on the screen.
*  RETURN: None
*/

void moveShip(Sprite& ship)
{
	int locationX = static_cast<int>(ship.getPosition().x);
	int locationY = static_cast<int>(ship.getPosition().y);
	/*
	 *  This first If-then-else-if Block handles
	 */
	if (Keyboard::isKeyPressed(Keyboard::Left) && locationX > 0)
	{
		// left arrow is pressed: move our ship left 5 pixels ( this is -5 pixels to go left)
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && locationX < (WINDOW_WIDTH - 20))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);

	}

}
/*
*  moveShip - This function is called to handle a keyPress event.
*     Keyboard input is detected and ship is moved.
*   ** Part of the lab is to also handle firing a missile **
*  INPUT: The ship pixie is passed.  This merely a drawn object on the screen.
*  RETURN: None
*/

void moveShip(Pixie& ship)
{
	int locationX = static_cast<int>(ship.getSprite().getPosition().x);
	int locationY = static_cast<int>(ship.getSprite().getPosition().y);
	/*
	 *  This first If-then-else-if Block handles
	 */

	if (Keyboard::isKeyPressed(Keyboard::Left) && locationX > 0)
	{
		// left arrow is pressed: move our ship left 5 pixels ( this is -5 pixels to go left)
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && locationX < (WINDOW_WIDTH - 20))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);

	}
}

void moveAlien(Pixie& alien, bool& isLimit) 
{
	int alienX = static_cast<int>(alien.getSprite().getPosition().x); // this variable holds the position of the alien 

		//This condition checks to see if the position is less than 0 and the alien goes to the left
	if (alienX > 0 && !isLimit)
		alien.move(-ALIEN_DISTANCE, 0);//this moves the alien to the left
	else
	{
		//when the alien reachs 0, it goes back until it reaches the other edge
		isLimit = true; //This becomes true until the alien hits the other edge of the screen
		//This condition check to see if the alien reached the far right edge so it can go back to the left
		if (alienX < (WINDOW_WIDTH - 35))
			alien.move(ALIEN_DISTANCE, 0);
		else
			isLimit = false; // this boolean is set to false in case the alien hits the right edge

	}
}

