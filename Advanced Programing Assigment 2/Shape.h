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
	//double* lefttop[2];
	Points leftTop, rightBottom;
	bool isCircular = false;
	vector<Points> points;

};
