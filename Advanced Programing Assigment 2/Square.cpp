#include "Square.h"

Square::Square(int x, int y, int e)
{
	leftTop.setX(x);
	leftTop.setY(y);
	edge = e;
}

void Square::calculatePoint()
{
	points.clear();
	rightTop.setX(leftTop.getX() + edge);
	rightTop.setY(leftTop.getY());

	rightBottom.setX(leftTop.getX() + edge);
	rightBottom.setY(leftTop.getY() + edge);

	leftBottom.setX(leftTop.getX());
	leftBottom.setY(leftTop.getY() + edge);

	points.push_back(leftTop);
	points.push_back(rightTop);
	points.push_back(rightBottom);
	points.push_back(leftBottom);

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
	printf("Square [E = %i]\n",edge);
	printf("Points ");
	for (Points point : points)
	{
		printf("[(%i,%i)]", point.getX(), point.getY());

	}
	printf("\n");	
	printf("Area= %d Perimeter=%d \n", calculateArea(), calculatePerimeter());
}

void Square::scale(float scaleX, float scaleY)
{
	edge = edge* scaleX;
	calculatePoint();

}
