#pragma once
#include"Movable.h"
#include"Shape.h"
class Square : public Shape, public Movable {
public:
	Square(int x ,int y,int e);
	int edge;
	void calculatePoint();
	void calculatePoint(int newX, int newY);
	void move(int newX, int newY);
	int calculateArea();
	int calculatePerimeter();
	void toString();
	void virtual scale(float scaleX, float scaleY);
};
