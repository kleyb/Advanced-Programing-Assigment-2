#include "Square.h"

Square::Square(int x, int y, int e)
{
	leftTop.setX(x);
	leftTop.setY(y);
	edge = e;
}

void Square::calculatePoint()
{
	rightTop.setX(leftTop.getX() + edge);
	rightTop.setY(leftTop.getY());

	rightBottom.setX(leftTop.getX() + edge);
	rightBottom.setY(leftTop.getY() + edge);

	leftBottom.setX(leftTop.getX());
	leftBottom.setY(leftTop.getY() + edge);
}

void Square::calculatePoint(int newX, int newY)
{
	leftTop.setX(newX);
	leftTop.setY(newY);

	calculatePoint();
}

void Square::move(int newX, int newY)
{
	calculatePoint(newX, newY);
}

int Square::calculateArea()
{
	return edge * edge;
}

int Square::calculatePerimeter()
{
	return edge * 4;
}

void Square::toString()
{
	calculatePoint();
	printf("Rectangle [E = %i]\n",edge);
	printf("Points[(%i, %i)(%i, %i)(%i, %i)(%i, %i)]\n", leftTop.getX(), leftTop.getY(),
		rightTop.getX(), rightTop.getY(), rightBottom.getX(), rightBottom.getY(), leftBottom.getX(), leftBottom.getY());
	printf("Area= %d Perimeter=%d \n", calculateArea(), calculatePerimeter());
}

void Square::scale(float scaleX, float scaleY)
{
}
