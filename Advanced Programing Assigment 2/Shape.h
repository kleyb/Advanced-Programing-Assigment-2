#pragma once
//#include<array>
#include<iostream>
#include<string>
#include<vector>
#include"Points.h"
#include"CompareT.h"

using namespace std;

class Shape {
public:
	Shape();
	~Shape();
	virtual int calculateArea() = 0;
	virtual int calculatePerimeter() = 0;
	virtual void calculatePoint() = 0;
	virtual void toString();
	Points leftTop;
	Points rightBottom;
	Points leftBottom;
	Points rightTop;
	bool isCircular = false;
	vector<Points> points; //Holds the points
	friend std::ostream& operator<<(std::ostream& os, Shape& object); //Friend function to overload the stream operator
	template<class T> friend class compareT;

};
