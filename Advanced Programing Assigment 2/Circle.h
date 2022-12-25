#pragma once

#include"Shape.h"
#include"Movable.h"

class Circle : public Shape ,public  Movable
{
public:	
	Circle(int *x, int *y, float r);
	void calculatePoint();
	void calculatePoint(int *newX, int *newY);
	int calculateArea();
	int calculatePerimeter();
	void move(int &newX, int &newY);
	void toString();
	void virtual scale(float scaleX, float scaleY);
private:
	const double pi = 3.14159265358979323846; // constant variable as PI values never changes
	float radius;
};