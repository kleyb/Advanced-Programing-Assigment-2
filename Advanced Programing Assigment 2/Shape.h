#pragma once
//#include<array>
#include<iostream>
#include<string>
#include<vector>
#include"Points.h"
#include"CompareT.h"

using namespace std;
//Shapes is an abstract to which all shapes will inherit from
class Shape {
public:
	Shape();
	~Shape();
	// Defines virtual and pure virtual functions to be implemented at children classes
	virtual int calculateArea() = 0;
	virtual int calculatePerimeter() = 0;
	virtual void calculatePoint() = 0;
	virtual void toString();
	//Creates an object for each point
	Points leftTop;
	Points rightBottom;
	Points leftBottom;
	Points rightTop;
	bool isCircular = false; // idicates if the shape is circular
	vector<Points> points; //Holds the points
	friend std::ostream& operator<<(std::ostream& os, Shape& object); //Friend function to overload the stream operator
	template<class T> friend class compareT; // compareT is a template that will compare the area of 2 objects type Shape
protected:
	int perimeter, area; // Protected fields to be implemented by all children classes

};
