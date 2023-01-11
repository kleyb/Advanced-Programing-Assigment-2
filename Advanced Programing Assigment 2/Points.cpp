#pragma once
#include"Points.h"
//getter to return the value of x
int Points::getX() {
	return x;
}
//getter to return the value of y
int Points::getY()
{
	return y;
}
// Default Constructor sets field values to 0
Points::Points()
{
	x = 0;
	y = 0;
}
//Setter to set the value of x
void Points::setX(float x)
{
	this->x = x;
}
//Setter to set the value of y
void Points::setY(float y)
{
	this->y = y;
}
