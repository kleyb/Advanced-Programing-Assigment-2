#pragma once
#include"Movable.h"
#include"Shape.h"
#include"Points.h"

class Rectangle : public Movable, public Shape {
public:
	Rectangle(int x, int y, int h, int w);
	int height{};
	int width{};
	void calculatePoint() ;
	int calculateArea();
	int calculatePerimeter();
	void toString();

};