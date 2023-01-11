#pragma once

#include"Shape.h"
#include"Movable.h"
// Circle inherits from Shape and Movable classes
class Circle : public Shape ,public  Movable
{
public:	
	Circle(int *x, int *y, float r); // The constructor uses pointers for positions x ,y but not for radius 
	~Circle();
	void calculatePoint();
	void calculatePoint(int *newX, int *newY);
	int calculateArea();
	int calculatePerimeter();
	void toString();
	//These methods are inherited from movable and overriden 
	void move(int& newX, int& newY);
	void virtual scale(float scaleX, float scaleY);
private:
	const double pi = 3.14159265358979323846; // constant variable as pi's value never changes
	float radius; // radius as a float as 
};