#pragma once
#include"Movable.h"
#include"Shape.h"
//Square inherits form Shape and Movable Classes
class Square : public Shape, public Movable {
public:
	Square(int *x ,int *y,int *e); // Square Constructor will assign values into positions x and y of left , as well as the value of edge 
	void calculatePoint(); // Method to calculate points
	int calculateArea();
	int calculatePerimeter();
	void toString();
	//These methods are inherited from movable and overriden 
	void scale(float scaleX, float scaleY); 
	void move(int& newX, int& newY);
private:
	int edge;
};
