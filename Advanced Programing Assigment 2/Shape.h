#pragma once
//#include<array>
#include<iostream>
#include<string>
#include<vector>
#include"Points.h"

using namespace std;

class Shape {
public:
	Shape();
	virtual int calculateArea() = 0;
	virtual int calculatePerimeter() = 0;
	virtual void calculatePoint() = 0;
	virtual void toString();
	Points leftTop;
	Points rightBottom;
	Points leftBottom;
	Points rightTop;
	bool isCircular = false;
	vector<Points> points;
	
};
