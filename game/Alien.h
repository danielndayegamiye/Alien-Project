#pragma once
#include "gameHeader.h"
class Alien:public Pixie
{
private:
	bool isLimit;
	Alien* nextPointer;
public:
    Alien():Pixie("alien.bmp", ALIEN_X_POSITION, ALIEN_Y_POSITION, UNDEFINED_PIXIE)
    {
		isLimit = false;
		nextPointer = nullptr;
    }
	void moveAlien()
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
	void drawPixie(RenderWindow& window)
	{
		window.draw(this->getSprite());
	}
	Alien* getNext() { return nextPointer; }
	void setNext(Alien* ptr) { nextPointer = ptr; }
};

