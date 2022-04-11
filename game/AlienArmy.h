#pragma once
#include "gameHeader.h"


class AlienArmy
{
private:
	Alien* head;
	bool isLimit;
	bool isMissileInFlight;
public:
	AlienArmy()
	{
		int counter = 0;
		Alien* alienPtr = new Alien();
		while (counter < 600)
		{
			append(alienPtr);
			counter+=60;
			alienPtr = new Alien();
			alienPtr->setPosition(alienPtr->getPixieX() + counter, alienPtr->getPixieY() );
		}
		isLimit = false;
		isMissileInFlight = false;
	}

	void append(Alien* newNodePtr) 
	{

		Alien* nodePtr;
		if (!head)
		{
			head = newNodePtr;
		}
		else
		{
			nodePtr = head;

			while (nodePtr->getNext() != nullptr)
			{
				nodePtr = nodePtr->getNext();
			}
			nodePtr->setNext(newNodePtr);
		}
	}

	void drawList(RenderWindow& window) {
		Alien* pixiePtr;

		if (!head)
		{
			cout << "YOU WONNNN!!!\n\n";
			exit(0);
		}
		else
		{
			pixiePtr = head;

			while (pixiePtr != nullptr) 
			{
				pixiePtr->drawPixie(window);
				pixiePtr = pixiePtr->getNext();
			}
		}
	}

	void moveArmy(int& counter) {
		Alien* pixiePtr;
		bool isMoving = false;

		if (!head)
			return;
		else
		{
			pixiePtr = head;
			while (pixiePtr != nullptr)
			{
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
						//cout<<pixiePtr->getID()<<endl;
						/*if(pixiePtr->getID()==9)
							counter += 10;*/
						//pixiePtr->setPixieY(counter);
						counter += 30;
					}
				}
				pixiePtr = pixiePtr->getNext();
			}

		}
	}

	bool MissileChecking(Pixie& missile) {
		Alien* pixiePtr;
		FloatRect missileBounds = missile.getSprite().getGlobalBounds();
		if (!head)
			cout << "The List is Empty\n\n";
		else
		{
			pixiePtr = head;

			while (pixiePtr != nullptr)
			{
				FloatRect alienBounds = pixiePtr->getSprite().getGlobalBounds();
				if (missileBounds.intersects(alienBounds))
				{
					deleteAlien(pixiePtr->getID());
					return true;
				}
				pixiePtr = pixiePtr->getNext();
			}
		}
		return false;
	}

	void deleteAlien(int num)
	{
		Alien* nodePtr; // To traverse the list
		Alien* previousNode = nullptr; // To point to the previous node

			// If the list is empty, do nothing.
		if (!head)
			return;
		if (head->getID() == num)
		{
			nodePtr = head->getNext();
			delete head;
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
			// nodePtr, then delete nodePtr.
			if (nodePtr)
			{
				previousNode->setNext(nodePtr->getNext());
				delete nodePtr;
			}
		}
	}

	void shootMissile(int num, Pixie& missile, RenderWindow& window)
	{
		Alien* nodePtr; // To traverse the list

		if (!head)
			return;
		else
		{
			// Initialize nodePtr to head of list
			nodePtr = head;
			Alien* AlienPtr=nullptr;
			// Skip all nodes whose value member is
		   // not equal to num.
			while (nodePtr != nullptr)
			{
				if (nodePtr->getID() == num)
					AlienPtr = nodePtr;
			}

			Vector2f pos = AlienPtr->getSprite().getPosition();
			missile.setPosition(pos.x + 10, pos.y - 15);
			FloatRect missileBounds = missile.getSprite().getGlobalBounds();
			FloatRect enemyBounds = AlienPtr->getSprite().getGlobalBounds();

			if (isMissileInFlight) {

				missile.move(0, DISTANCE);

				int locationY = static_cast<int>(missile.getSprite().getPosition().y);// the y location of the missile
				if (locationY < 0)
				{
					isMissileInFlight = false;
				}
				else if (missileBounds.intersects(enemyBounds))//THE MISSILE HITS THE ALIEN
				{
					// Display 'hit' and set the boolean to false
					cout << "HITTED\n\n";
					isMissileInFlight = false;
				}
				missile.drawPixie(window);
			}
		}
	}

	void checkShipY(Pixie& ship)
	{
		Alien* pixiePtr = head;

		while (pixiePtr->getNext() != nullptr)
		{
			if (pixiePtr->getPixieY() >= ship.getPixieY())
			{
				cout << "Game Over!!!\n";
				exit(0);
			}
			pixiePtr = pixiePtr->getNext();
		}
	}
	

};

