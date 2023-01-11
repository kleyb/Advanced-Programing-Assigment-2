#pragma once
#include"Shape.h"


Shape::Shape()
{	//Inialises the objects on the 
	Points leftTop{};
	Points rightBottom{};
	Points leftBottom{};
	Points rightTop{};
}

Shape::~Shape()
{	// Clear the points vectors if there are any points , then dealocates using shrink_to_fit
	points.clear();
	points.shrink_to_fit();
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
