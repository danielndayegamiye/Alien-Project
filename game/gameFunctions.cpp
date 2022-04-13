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

/*
*  shootingMissiles - This function is called to handle the missile shot by the army

*  INPUT: The ship pixie is passed.  
*		  The boolean isAlien is passed by reference
*		  The integers xPosition and yPosition holds the position of the alien to fire the missile.
*		  The integer numberOfLives holding the number of lives for the ship
*		  The alienMissile pixie is passed
*  RETURN: None
*/
void shootingMissiles(bool& isAlien, Pixie& alienMissile, int xPosition, int yPosition, int& numberOfLives, Pixie& ship)
{
	// this if block checks to see if there is a missile thrown by an alien on the screen
	if (!isAlien)
	{
		// setting the position of the missile according to the position of the alien
		alienMissile.setPosition(xPosition, yPosition);
		isAlien = true;// there is now a missile on the screen
	}
	else if (alienMissile.getPixieY() >= WINDOW_HEIGHT)
	{
		// setting the boolean to false meaning that the missile is off-screen
		isAlien = false;
	}
	// this two objects holds the bounds of the ship and the missile thrown by the alien
	FloatRect missileAlienBounds = alienMissile.getSprite().getGlobalBounds();
	FloatRect shipBounds = ship.getSprite().getGlobalBounds();
	// this if block statement checks to see if the ship was hit by the missile 
	if (shipBounds.intersects(missileAlienBounds))
	{
		// the missile disappears from the screen
		isAlien = false;
		// the number of lives reduce and display a message telling the player that he was hit
		numberOfLives--;
		cout << "SHIP HIT!!!!!CAREFUL MOVE!!!\n\n";
	}
	// the user does not have anymore life to spend and the game is over
	else if (numberOfLives < 1)
	{
		cout << "YOU LOSER!!!!\n\n";
		exit(0);
	}
}
