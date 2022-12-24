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

void Shape::toString() {
	cout << "Shape Details\n";
}

std::ostream& operator<<(std::ostream& os, Shape& object)
{
	object.calculatePoint();
	object.toString();
	return os;
}
