#pragma once
#include "Rectangle.h"
#include"Points.h"
#include <format>

Rectangle::Rectangle(int *x, int *y, int *h, int *w)
{
	leftTop.setX(*x);
	leftTop.setY(*y);
	height = *h;
	width = *w;

}

Rectangle::~Rectangle()
{
	
}

void Rectangle::calculatePoint()
{
	points.clear();
	rightTop.setX(leftTop.getX()+width);
	rightTop.setY(leftTop.getY());

	leftBottom.setX(leftTop.getX());
	leftBottom.setY(leftTop.getY()+height);

	rightBottom.setX(leftTop.getX()+width);
	rightBottom.setY(leftTop.getY()+height);

	points.push_back(leftTop);
	points.push_back(rightTop);
	points.push_back(rightBottom);
	points.push_back(leftBottom);
	
}

void Rectangle::calculatePoint(int *newX, int *newY)
{
	leftTop.setX(*newX);
	leftTop.setY(*newY);

	calculatePoint();
}

void Rectangle::move(int &newX, int &newY)
{
	calculatePoint(&newX, &newY);
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
	printf("Rectangle [H = %i,w = %i]\n",height,width);
	printf("Points ");
	for (Points point : points)
	{
		printf("[(%i,%i)]", point.getX(),point.getY());
		
	}
	printf("\n");
	printf("Area= %d Perimeter=%d \n", calculateArea(), calculatePerimeter());
}

void Rectangle::scale(float scaleX, float scaleY)
{
	height = height * scaleX;
	width = width * scaleY;

	calculatePoint();
}
