#pragma once
#include "Rectangle.h"
#include"Points.h"
#include <format>

Rectangle::Rectangle(int x, int y, int h, int w)
{
	leftTop.setX(x);
	leftTop.setY(y);
	height = h;
	width = w;
}

Rectangle::~Rectangle()
{
}

void Rectangle::calculatePoint()
{
	rightTop.setX(leftTop.getX()+width);
	rightTop.setY(leftTop.getY());

	leftBottom.setX(leftTop.getX());
	leftBottom.setY(leftTop.getY()+height);

	rightBottom.setX(leftTop.getX()+width);
	rightBottom.setY(leftTop.getY()+height);
}

void Rectangle::calculatePoint(int newX, int newY)
{
	leftTop.setX(newX);
	leftTop.setY(newY);

	calculatePoint();
}

void Rectangle::move(int newX, int newY)
{
	calculatePoint(newX, newY);
}

int Rectangle::calculateArea()
{
	return height * width;
}

int Rectangle::calculatePerimeter()
{
	return (height + width) * 2;
}

void Rectangle::toString()
{
	calculatePoint();
	printf("Rectangle [H = %i,w = %i]\n",height,width);
	printf("Points[(%i, %i)(%i, %i)(%i, %i)(%i, %i)]\n",leftTop.getX(),leftTop.getY(), 
		rightTop.getX(),rightTop.getY(), rightBottom.getX(),rightBottom.getY(), leftBottom.getX(), leftBottom.getY());
	printf("Area= %d Perimeter=%d \n", calculateArea(), calculatePerimeter());

}

void Rectangle::scale(float scaleX, float scaleY)
{
	height = height * scaleX;
	width = width * scaleY;

	calculatePoint();
}
