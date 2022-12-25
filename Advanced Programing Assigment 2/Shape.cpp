#pragma once
#include"Shape.h"


Shape::Shape()
{
	Points leftTop{};
	Points rightBottom{};
	Points leftBottom{};
	Points rightTop{};
}

Shape::~Shape()
{
	delete[] & leftTop;
	delete[] & rightBottom;
	delete[] & leftBottom;
	delete[] & rightTop;
	delete[] & points;
	
}
//Base to string function which displays the details of the shape
void Shape::toString() {
	cout << "Shape Details\n";
}

//The ostream is overloaded, to calculate the points and then display each derived class' methods
std::ostream& operator<<(std::ostream& os, Shape& object)
{	
	object.calculatePoint();
	object.toString();
	return os;
}
