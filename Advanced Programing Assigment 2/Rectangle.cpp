#pragma once
#include "Rectangle.h"
#include"Points.h"
#include <format>

//Uses pointers to set the pointers and values to height and width
Rectangle::Rectangle(int *x, int *y, int *h, int *w)
{
	leftTop.setX(*x); 
	leftTop.setY(*y);
	height = *h;
	width = *w;
}
//Clear points vector and dealocates the memory
Rectangle::~Rectangle()
{
	points.clear();
	points.shrink_to_fit();
}
//Calculates the points positions
void Rectangle::calculatePoint()
{	//Before the calculation makes sure that the points vector is clean 
	points.clear();
	rightTop.setX(leftTop.getX()+width);
	rightTop.setY(leftTop.getY());

	leftBottom.setX(leftTop.getX());
	leftBottom.setY(leftTop.getY()+height);

	rightBottom.setX(leftTop.getX()+width);
	rightBottom.setY(leftTop.getY()+height);

	//After determining the points locations , push it to 'points' vector
	points.push_back(leftTop);
	points.push_back(rightTop);
	points.push_back(rightBottom);
	points.push_back(leftBottom);
	
}

//The move method takes new values for x and y then uses the overloaded function to give new positions for lefttop
//then calculates points locations again
void Rectangle::move(int &newX, int &newY)
{// Checks if the new values are valid
	if (newX < 0 || newY < 0) {
		printf("You have entered invalid coordinates, please enter values above or equal to 0\n");
		return;
	}
	leftTop.setX(float(newX));
	leftTop.setX(float(newY));
}
// Calculates the area and returns
int Rectangle::calculateArea()
{	
	area = height * width;
	return area;
}
//Calculates the perimeter and returns
int Rectangle::calculatePerimeter()
{
	perimeter = (height + width) * 2;
	return perimeter;
}
// the toString function displays to the user the details of the shape, such as height ,width, area and perimeter , as well as points locations
void Rectangle::toString()
{	// printf is used here for a better string formating
	printf("Rectangle [H = %i,w = %i]\n",height,width);
	printf("Points ");
	//for each point , displays it's value
	for (Points point : points)
	{
		printf("[(%i,%i)]", point.getX(),point.getY());
		
	}
	printf("\n");
	printf("Area= %d Perimeter=%d \n", calculateArea(), calculatePerimeter());
}
//The scale method scales the shapes but there is no need to recalculate again as this will be done at later point
void Rectangle::scale(float scaleX, float scaleY)
{	
	height = height * scaleX;
	width = width * scaleY;
}
