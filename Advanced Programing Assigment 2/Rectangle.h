#pragma once
#include"Movable.h"
#include"Shape.h"
class Rectangle : Movable, Shape {
public:
	double height;
	double width;
};