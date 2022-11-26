#pragma once
#include"Points.h"

int Points::getX() {
	return x;
}

int Points::getY()
{
	return y;
}

Points::Points()
{
	x = 0;
	x = 0;
}

void Points::setX(float x)
{
	this->x = x;
}

void Points::setY(float y)
{
	this->y = y;
}
