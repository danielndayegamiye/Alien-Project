#pragma once
//===================================================== 
// Daniel Ndayegamiye
// February 21, 2022
// file name: gameHeader.h
// Programming Assignment #3
// Description: this file holds the function prototypes used in the game
//=====================================================

// includes go below
#include <iostream>
#include <time.h>
using namespace std;
// these two lines are specific to the SFML graphics library. 
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Pixie.h"

// Constants for the game 
const float DISTANCE = 5.0f; // When the ship moves it moves 5 pixels at a time. 
const int WINDOW_WIDTH = 800; // window is 800 pixels wide
const int WINDOW_HEIGHT = 600;// window is 600 pixels vertically "high"
const int UNDEFINED_PIXIE = 10;// this will be used later
const int PLAYER_SHIP_PIXIE = 20;// this will be used later
const int PLAYER_MISSILE_PIXIE = 30;// this will be used later
const int BACKGROUND_PIXIE = 40;// this will be used later
const int FRAME_RATE_LIMIT = 60;// this variable holds the framerate per second
const int DEFAULT_COORDINATE = 0;// this variable sets the coordinate to 0 as default
const int ALIEN_X_POSITION = 200;// this variable holds the x position of the alien
const int ALIEN_Y_POSITION = 100;// this variable holds the y position of the alien
const float BACKGROUND_SCALE = 1.5f;// this variable holds the scale used for the background
const float ALIEN_DISTANCE = 3.5f;// when the alien moves it moves 4 pixels at a time

#include "Alien.h"
#include "AlienArmy.h"


// Game Functions
void moveShip(Sprite& ship); 
void moveShip(Pixie& ship);
void shootingMissiles(bool& isAlien, Pixie& alienMissile, int x, int y, int& numberOfLives, Pixie& ship);