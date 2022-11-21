#pragma once
#include "Rectangle.h"
#include"Points.h"

Rectangle::Rectangle(int x, int y, int h, int w)
{
	leftTop.setX(x);
	leftTop.setY(y);
	height = h;
	width = w;
}

void Rectangle::calculatePoint()
{
	rightTop.setX(leftTop.getX()+width);
	rightTop.setX(leftTop.getX());

	leftBottom.setX(leftTop.getX());
	leftBottom.setY(leftTop.getY()+height);

	rightBottom.setX(leftTop.getX()+width);
	rightBottom.setY(leftTop.getY()+height);

}

int Rectangle::calculateArea()
{
	return height * width;
}

int Rectangle::calculatePerimeter()
{
	return (height + width) * 2;
}
