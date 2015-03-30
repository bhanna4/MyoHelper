#pragma once
ref class myoguyo
{
public:
	myoguyo(void);
	myoguyo(int xPos, int yPos);
	static int xPos, yPos;
	int distance, xBound, yBound;
	char orientation;
	char changeDirection(char orientation);
	void moveForward();
	void reverse();

};

