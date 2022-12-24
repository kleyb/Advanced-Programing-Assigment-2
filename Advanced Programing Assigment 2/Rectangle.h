#pragma once
#include"Movable.h"
#include"Shape.h"
#include"Points.h"

class Rectangle : public Movable, public Shape {
public:
	Rectangle(int x, int y, int h, int w);
	~Rectangle();
	void calculatePoint();
	void calculatePoint(int newX, int newY);
	void move(int newX, int newY);
	int calculateArea();
	int calculatePerimeter();
	void toString();
	void virtual scale(float scaleX, float scaleY);	
private:
	int height{};
	int width{};
};