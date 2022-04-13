//===================================================== 
// Daniel Ndayegamiye
// February 21, 2022
// file name: game.cpp
// Programming Assignment #3
// Description: this is the main file for this project 
//=====================================================

#include "gameHeader.h"
//***********************************************************************************
// Function main - the main function to be compiled
// There are no input for it
// return value – the function returns 0 so that the compiler will know the end of the program. 

int main()
{
	srand(time(0));
	// Create the window for graphics. 
	//  The "aliens" is the text in the title bar on the window. 
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");

	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(FRAME_RATE_LIMIT);

		
	// Create and Initialize a pixie class for the missile
	Pixie missile("missile.bmp", DEFAULT_COORDINATE, DEFAULT_COORDINATE, PLAYER_MISSILE_PIXIE);

	// Create and Initialize a pixie class for the alien
	//Alien alien;
	AlienArmy army;
	//army.drawList(window);
	// create pixie for the ship
	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y * 0.8f;
	Pixie ship("ship.png", shipX, shipY, PLAYER_SHIP_PIXIE);

	int missileCoordinateX;
	int missileCoordinateY;


	// Create and initialize a pixie object for the background
	Pixie background("stars.jpg", DEFAULT_COORDINATE, DEFAULT_COORDINATE, BACKGROUND_PIXIE);
	background.setScale(BACKGROUND_SCALE, BACKGROUND_SCALE);

	bool isMissileInFlight = false; // used to know if a missile is 'on screen'. 
	
	int counter = 0;// this variable will be used to increment the height of the army every time it touches the right edge

	bool isAlien = false; // this boolean checks to see if the missile shot by the alien is still on the screen
	// creating the pixie for the missile thrown by the army
	Pixie alienMissile("missile.bmp", DEFAULT_COORDINATE, DEFAULT_COORDINATE, PLAYER_MISSILE_PIXIE);

	int numberOfLives = 10;// this variable holds the total number of lives of the ship

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		// This while loop checks to see if anything happened since last time
		// we drew the window and all its graphics. 
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) // Did the user kill the window by pressing the "X"?
				window.close();
			else if (event.type == Event::KeyPressed) // did the user press a key on the keyboard?
			{
				if (event.key.code == Keyboard::Space && !isMissileInFlight)
				{
					isMissileInFlight = true;
					//the code to initialize missile position above the ship
					Vector2f pos = ship.getSprite().getPosition();
					missile.setPosition(pos.x + 10, pos.y - 15);
				}
			}
		}
		
		// this condition checks to see if the linked list is empty 
		// which means that the user killed the whole army
		if (army.isListEmpty())
		{
			cout << "YOU WONNNN!!!\n\n";
			exit(0);
		}
		// collecting the coordinate of an alien in the army
		missileCoordinateX = army.getAlienX() - 10;
		missileCoordinateY = army.getAlienY() + 50;

		// calling the function responsible of shooting missiles to the ship
		shootingMissiles(isAlien, alienMissile, missileCoordinateX,missileCoordinateY, numberOfLives, ship);

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		background.drawPixie(window);

		//detect key presses to update the position of the ship. 
		//See moveShip() function above.
		moveShip(ship);
		
		//alien.moveAlien();
		army.moveArmy(counter);
		// draw the alien on the screen
		//alien.drawPixie(window);
		army.drawList(window);

		// this two variables are created so that we can learn from them if the missile hits the alien
		//FloatRect missileBounds = missile.getSprite().getGlobalBounds();
		//FloatRect enemyBounds = alien.getSprite().getGlobalBounds();

		// draw the ship on top of background 
		ship.drawPixie(window);
		// check if the army reached the ship level
		army.checkShipY(ship);
		// make the missile shot by the army move
		alienMissile.move(0,DISTANCE);
		// draw the missile thrown by the army on the screen
		alienMissile.drawPixie(window);

		// this condition is for when the missile is in flight to move it up
		if (isMissileInFlight)
		{
			// move it "up" the screen by decreasing 'y' and then use 'setPosition()' 
			//     to place it at its new location. 
			missile.move(0, -DISTANCE);

			int locationY = static_cast<int>(missile.getSprite().getPosition().y);// the y location of the missile

			//to see if the missile is off screen!
			// if it's moved off the top, set the boolean to false!
			if (locationY < 0)
			{
				isMissileInFlight = false;
			}
			else if (army.MissileChecking(missile))//THE MISSILE HITS THE ALIEN
			{
				// Display 'hit' and set the boolean to false
				cout << "HIT\n\n";
				isMissileInFlight = false;
			}
				missile.drawPixie(window);// Draw the missile,
		}

		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

