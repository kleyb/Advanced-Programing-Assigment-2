
#include "Circle.h"
Circle::Circle(int x, int y, double r)
{
	radius = r;
	leftTop.setX(x);
	leftTop.setY(y);
	isCircular = true;
}

void Circle::calculatePoint()
{
	points.clear();
	rightBottom.setX(round(leftTop.getX() + 2 * radius));
	rightBottom.setY(round(leftTop.getY() + 2 * radius));

	points.push_back(leftTop);
	points.push_back(rightBottom);
}

void Circle::calculatePoint(int newX, int newY)
{
	leftTop.setX(newX);
	leftTop.setY(newY);

	calculatePoint();
}

int Circle::calculateArea() //Needs to be checked
{
	int temp = round(pi * radius * radius);
	return temp; // returns version of the result 
}

int Circle::calculatePerimeter() //Needs to be checked
{
	return round(2 * pi * radius);
}

void Circle::move(int newX, int newY)
{
	if (newX < 0 || newY < 0) printf("You have entered invalid cordinates, please enter values above or equal to 0"); return;
	calculatePoint(newX, newY);
}

void Circle::toString()
{
	calculatePoint();
	printf("Circle [R = %f]\n", radius);

	printf("Points ");
	for (Points point : points)
	{
		printf("[(%i,%i)]", point.getX(), point.getY());

	}
	printf("\n");
	printf("Area= %d Perimeter=%d \n", calculateArea(), calculatePerimeter());
}
// Scales the circle based on the first value given
// As Circles do not have 2 values , only one will be used 
void Circle::scale(float scaleX, float scaleY) 
{	
	radius = radius * scaleX; // Uses scaleXx to calculate the scale the radius , therefore scaling the shape
	calculatePoint();
}
