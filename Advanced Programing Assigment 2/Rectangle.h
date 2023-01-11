#pragma once
#include"Movable.h"
#include"Shape.h"
#include"Points.h"
// Rectangle inherits from Movable class and from Shape 
class Rectangle : public Movable, public Shape {
public:
	Rectangle(int *x, int *y, int *h, int *w); // The constructor for rectangle uses pointer to define the values of it's fields
	~Rectangle();

	void calculatePoint();	
	int calculateArea();
	int calculatePerimeter();
	void toString();
	//These methods are inherited from movable and overriden 
	void move(int& newX, int& newY);
	void scale(float scaleX, float scaleY);	
private:
	//These fields will store the values of height and width
	int height;
	int width;
};