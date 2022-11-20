#pragma once
//#include<array>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Shape {
public:
	Shape();
	virtual int calculateArea() = 0;
	virtual int calculaPerimeter() = 0;
	virtual int calculatePoint() = 0;
	void toString();
	int lefttop[2];
	bool isCircular = false;
	vector<int> points;

};
