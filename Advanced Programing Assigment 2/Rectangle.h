#pragma once
#include"Movable.h"
#include"Shape.h"

class Rectangle : public Movable, public Shape {
public:
	Rectangle(double x, double y, double h, double w);
	double height;
	double width;
	void calculatePoint() ;
	double calculateArea();
	double calculatePerimeter();
	Points leftBottom, rightTop;
};