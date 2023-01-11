#include "Square.h"
//Uses pointers to set the values of leftTop and of edge
Square::Square(int *x, int *y, int *e)
{
	leftTop.setX(*x); 
	leftTop.setY(*y);
	edge = *e;	
}
//Clears the points vector then calculates the points positions
void Square::calculatePoint()
{
	points.clear();
	rightTop.setX(leftTop.getX() + edge);
	rightTop.setY(leftTop.getY());

	rightBottom.setX(leftTop.getX() + edge);
	rightBottom.setY(leftTop.getY() + edge);

	leftBottom.setX(leftTop.getX());
	leftBottom.setY(leftTop.getY() + edge);
	// Pushes every point object into the points vector 
	points.push_back(leftTop);
	points.push_back(rightTop);
	points.push_back(rightBottom);
	points.push_back(leftBottom);

}
//Moves the shape by giving new values to X and Y
void Square::move(int &newX, int &newY)
{	// Checks if the new values are valid
	if (newX < 0 || newY < 0) {
		printf("You have entered invalid coordinates, please enter values above or equal to 0\n");
		return;
	}
	//calculatePoint(&newX, &newY);
	leftTop.setX(float(newX));
	leftTop.setX(float(newY));
}
// Calculates the area of Square
int Square::calculateArea()
{
	area = edge * edge;
	return area;
}
//Calculates the perimeter of Square
int Square::calculatePerimeter()
{
	perimeter = edge * 4;
	return perimeter;
}
// Displays the values of the Square object , such as points positions , area , perimeter and edge
void Square::toString()
{
	//Uses printf for a better string formatting
	printf("Square [E = %i]\n",edge);
	printf("Points ");
	for (Points point : points)
	{
		printf("[(%i,%i)]", point.getX(), point.getY());

	}
	printf("\n");	
	printf("Area= %d Perimeter=%d \n", calculateArea(), calculatePerimeter());
}
// Scales the object , no need to calculate the points at this moment as they will be done at a later moment
//As Squares only use one value , only X will be taken
void Square::scale(float scaleX, float scaleY)
{
	edge = edge* scaleX;

}
