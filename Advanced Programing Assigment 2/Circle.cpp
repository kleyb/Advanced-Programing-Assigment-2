
#include "Circle.h"
//Uses pointers to set the values of leftTop, sets the value of Circular as true
Circle::Circle(int *x, int *y, float r)
{
	radius = r;
	leftTop.setX(*x);
	leftTop.setY(*y);
	isCircular = true;
}
Circle::~Circle() {
	points.clear();
	points.shrink_to_fit();
}
//Calculates the positions of every point
void Circle::calculatePoint()
{	//Clears the vector before adding the points
	points.clear();
	rightBottom.setX(round(leftTop.getX() + 2 * radius));
	rightBottom.setY(round(leftTop.getY() + 2 * radius));
	// Pushes every point object into the points vector 
	points.push_back(leftTop);
	points.push_back(rightBottom);
}

// Calculates the area of Circle
int Circle::calculateArea() //Needs to be checked
{
	area = round(pi * radius * radius);
	return area; // returns version of the result 
}
//Calculates the perimeter of Circle
int Circle::calculatePerimeter() //Needs to be checked
{
	perimeter = round(2 * pi * radius);
	return perimeter;
}
// Moves the shape by giving new values to X and Y
void Circle::move(int &newX, int &newY)
{	// Checks if the new values are valid
	if (newX < 0 || newY < 0) {
		printf("You have entered invalid coordinates, please enter values above or equal to 0\n");
		return;
	}
	//Gives the new values to lefttop 
	leftTop.setX(float(newX));
	leftTop.setX(float(newY));
}
// Displays the details of the Shape such as Radius, perimeter and points locations
void Circle::toString()
{
	//Uses printf to better format strings 
	printf("Circle [R = %f]\n", radius);
	printf("Points ");
	//For every point in points , prints values
	for (Points point : points)
	{
		printf("[(%i,%i)]", point.getX(), point.getY());
	}
	printf("\n");
	printf("Area= %d Perimeter=%d \n", calculateArea(), calculatePerimeter());
}
// Scales the circle is based on the first value given
// As Circles do not have 2 values , only one will be used 
void Circle::scale(float scaleX, float scaleY) 
{	
	radius = radius * scaleX; // Uses scaleXx to calculate the scale the radius , therefore scaling the shape
}
