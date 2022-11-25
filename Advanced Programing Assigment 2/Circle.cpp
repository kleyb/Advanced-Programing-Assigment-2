
#include "Circle.h"
Circle::Circle(int x, int y, double r)
{
	radius = r;
	leftTop.setX(x);
	leftTop.setY(y);
}

void Circle::calculatePoint()
{
	rightBottom.setX(round(leftTop.getX() + 2 * radius));
	rightBottom.setY(round(leftTop.getY() + 2 * radius));
}

void Circle::calculatePoint(int newX, int newY)
{
	leftTop.setX(newX);
	leftTop.setY(newY);

	calculatePoint();
}

int Circle::calculateArea()
{
	return round(pi * radius * radius); // returns version of the result 
}

int Circle::calculatePerimeter() {
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
	printf("Rectangle [R = %d]\n", radius);
	printf("Points[(%i, %i)(%i, %i)]\n", leftTop.getX(), leftTop.getY(), rightBottom.getX(), rightBottom.getY());
	printf("Area= %d Perimeter=%d \n", calculateArea(), calculatePerimeter());
}

void Circle::scale(float scaleX, float scaleY)
{

}
