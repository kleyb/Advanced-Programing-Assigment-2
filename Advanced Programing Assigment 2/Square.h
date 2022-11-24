#pragma once
#include"Movable.h"
#include"Shape.h"
class Square : public Shape, public Movable {
public:
	Square(int x ,int y,int e);
	int edge;
	void calculatePoint();
	int calculateArea();
	int calculatePerimeter();
	void toString();
};
