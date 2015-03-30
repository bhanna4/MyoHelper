#include "myoguyo.h"


myoguyo::myoguyo(void)
{
	xPos = 100;
	yPos = 150;
	yBound = 477;
	xBound = 643;
	distance = 2;
	orientation = 'r';
}

myoguyo::myoguyo(int xPos, int yPos)
{
	this->xPos = xPos;
	this->yPos = yPos;
	yBound = 500;
	xBound = 650;
	distance = 10;
	orientation = 'r';
}
char myoguyo::changeDirection(char o)
{
	switch (orientation)
	{
	case 'u':
		{
			if(o=='l')
				orientation='y';
			else if(o=='r')
				orientation='i';
			break;
		}
	case 'd':
		{
			if(o=='l')
				orientation='k';
			else if(o=='r')
				orientation='h';
			break;
		}
	case 'l':
		{
			if(o=='l')
				orientation='h';
			else if(o=='r')
				orientation='y';
			break;
		}
	case 'r':
		{
			if(o=='l')
				orientation='i';
			else if(o=='r')
				orientation='k';
			break;
		}
	case 'y':
		{
			if(o=='l')
				orientation='l';
			else if(o=='r')
				orientation='u';
			break;
		}
	case 'i':
		{
			if(o=='l')
				orientation='u';
			else if(o=='r')
				orientation='r';
			break;
		}
	case 'h':
		{
			if(o=='l')
				orientation='d';
			else if(o=='r')
				orientation='l';
			break;
		}
	case 'k':
		{
			if(o=='l')
				orientation='r';
			else if(o=='r')
				orientation='d';
			break;
		}
	default:
		break;
	}
	return orientation;
}
void myoguyo::moveForward()
{
	if(orientation=='u'&&yPos>66)
	{
		yPos -= distance;
	}
	else if(orientation=='d'&&yPos<yBound)
	{
		yPos += distance;
	}
	else if(orientation=='l'&&xPos>60)
	{
		xPos -= distance;
	}
	else if(orientation =='r'&&xPos<xBound)
	{
		xPos += distance;
	}
	else if(orientation=='y'&&yPos>66&&xPos>60)
	{
		xPos-=distance/2;
		yPos-=distance/2;
		
	}
	else if(orientation=='h'&&yPos<yBound&&xPos>60)
	{
		xPos-=distance/2;
		yPos+=distance/2;
		
	}
	else if(orientation=='i'&&yPos>66&&xPos<xBound)
	{
		xPos+=distance/2;
		yPos-=distance/2;
		
	}
	else if(orientation=='k'&&yPos<yBound&&xPos<xBound)
	{
		xPos+=distance/2;
		yPos+=distance/2;
		
	}
}

void myoguyo::reverse()
{
	if(orientation=='u'&&yPos<yBound)
	{
		yPos += distance;
	}
	else if(orientation=='d'&&yPos>66)
	{
		yPos -= distance;
	}
	else if(orientation=='l'&&xPos<xBound)
	{
		xPos += distance;
	}
	else if(orientation =='r'&&xPos>60)
	{
		xPos -= distance;
	}
	else if(orientation=='k'&&yPos>66&&xPos>60)
	{
		xPos-=distance/2;
		yPos-=distance/2;
		
	}
	else if(orientation=='i'&&yPos<yBound&&xPos>60)
	{
		xPos-=distance/2;
		yPos+=distance/2;
		
	}
	else if(orientation=='h'&&yPos>66&&xPos<xBound)
	{
		xPos+=distance/2;
		yPos-=distance/2;
		
	}
	else if(orientation=='y'&&yPos<yBound&&xPos<xBound)
	{
		xPos+=distance/2;
		yPos+=distance/2;
		
	}
}
