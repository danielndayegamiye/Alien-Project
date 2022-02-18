#pragma once
#include <iostream>
//======================================================================
// Daniel Ndayegamiye
// February 21, 2022
// file name: Pixie.h
// Programming Assignment #3
// Description: this file holds the class declaration for the pixie class
//=======================================================================

class Pixie {
private:
	Texture pixieTexture; // this variable will hold the pixie texture
	Sprite pixieSprite; // this variable will hold the pixie sprite
	float pixieX; // this variable will hold the pixie x position
	float pixieY; // this variable will hold the pixie y position
	Pixie* nextPixie; // this pointer will be used later
	Pixie* previousPixie; // this pointer will be used later
	static int nextPixieID; // this variable will be used later
	int myID; // this variable will be used later
	int pixieType; // this variable will be used later
public:
	// member functions 
	Pixie();
	Pixie(string, float, float, int);
	void drawPixie(RenderWindow& window);
	void move(float x, float y);

	//setters
	void setType(int type) { pixieType = type; }
	void setPixieX(float x) { pixieX = x; }
	void setPixieY(float y) { pixieY = y; }
	void setScale(float xScale, float yScale);
	void setPosition(float x, float y);

	//getters
	float getPixieX() { return pixieSprite.getPosition().x; }
	float getPixieY() { return pixieSprite.getPosition().y; }
	Sprite getSprite() { return pixieSprite; }
	Texture getPixieTexture() { return pixieTexture; }
	int getID() { return myID; }
	int getType() { return pixieType; }
	Pixie* getNext() { return nextPixie; }
	Pixie* getPrevious() { return previousPixie; }
	Pixie* getSelfPointer() { return this; }
	
};

