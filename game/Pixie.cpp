//=======================================================================================
// Daniel Ndayegamiye
// February 21, 2022
// file name: Pixie.cpp
// Programming Assignment #3
// Description: this file holds the definitions of the member functions of the class Pixie
//========================================================================================

#include "gameHeader.h"

int Pixie::nextPixieID = 0; // sets the static variable to 0

//***********************************************************************************
// Function pixie - this is the default constructor for the Pixie class
// There are no input for it
Pixie::Pixie()
{
	// set all the member variables to default values
	pixieType = UNDEFINED_PIXIE;
	myID = nextPixieID++;
	pixieX = 0.0;
	pixieY = 0.0;
	nextPixie = nullptr;
	previousPixie = nullptr;
	pixieSprite.setTexture(pixieTexture);
}

//***********************************************************************************
// Function pixie - this is a constructor for the Pixie class
// The inputs are:
//					string imageFile - this variable holds the string of the name of the file containing
//										the picture used to set the texture
//					float xLocation - this variable holds the x position of the pixie
//					float yLocation - this variable holds the y position for the pixie
//					int type - this will be used later
Pixie::Pixie(string imageFile, float xLocation, float yLocation, int type)
{
	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.

	// a Texture is an image of pixels. You can load a .png file
	//   or a bitmap file.  These files are in the "Resource files" section of
	//   the solution explorer. 

	if (!pixieTexture.loadFromFile(imageFile))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	pixieSprite.setTexture(pixieTexture);
	// sets the pixie position 
	pixieSprite.setPosition(xLocation, yLocation);
	// sets the pixie member variables with the given values
	pixieX = xLocation;
	pixieY = yLocation;
	pixieType = type;
	// sets the member variables with default values
	myID = nextPixieID++;
	nextPixie = nullptr;
	previousPixie = nullptr;
}
//***********************************************************************************
// Function drawPixie - this function will draw the pixie on the screen
// The inputs are:
//					RenderWindow& window - used to draw the pixie on the screen
// return value - no return
void Pixie::drawPixie(RenderWindow& window)
{
	window.draw(pixieSprite);// draw the pixie on the screen
}
//***********************************************************************************
// Function move - this function moves the pixie
// The inputs are:
//					float x - x coordinate given by the user of our class
//					float y - y coordinate given by the user of our class
// return value - no return
void Pixie::move(float x, float y)
{
	// add the coordinates to the current position and set the new position
	pixieX += x;
	pixieY += y;
	pixieSprite.setPosition(pixieX, pixieY);
}

//***********************************************************************************
// Function setScale - this function sets the scale for the pixie
// The inputs are:
//					float xScale - x coordinate given by the user of our class for the scale
//					float yScale - y coordinate given by the user of our class for the scale
// return value - no return
void Pixie::setScale(float xScale, float yScale)
{
	// set the scale
	pixieSprite.setScale(xScale, yScale);
}

//***********************************************************************************
// Function setPosition - this function sets the position of the sprite
// The inputs are:
//					float x - x coordinate given by the user of our class
//					float y - y coordinate given by the user of our class
// return value - no return
void Pixie::setPosition(float x, float y)
{
	// setting the coordinates and setting the position
	pixieX = x;
	pixieY = y;
	pixieSprite.setPosition(x, y);
}