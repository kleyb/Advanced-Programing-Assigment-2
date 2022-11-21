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
	virtual double calculateArea() = 0;
	virtual int calculaPerimeter() = 0;
	virtual void calculatePoint() = 0;
	void toString();
	Points leftTop;
	Points rightBottom;
	Points leftBottom;
	Points rightTop;
	bool isCircular = false;
	vector<Points> points;

};
