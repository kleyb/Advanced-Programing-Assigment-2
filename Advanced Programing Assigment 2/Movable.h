#pragma once
class Movable
{
public:
	
	void virtual move(int newX, int newY) = 0;
	void scale();
};