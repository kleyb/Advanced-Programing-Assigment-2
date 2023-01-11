#pragma once
// Movable Class is an abstract class inherited by the shapes but not of type Shape
class Movable
{
public:
	// Declares 2 pure virtual methods to be overriden in children classes
	void virtual move(int &newX, int &newY) = 0; // Moves an object by giving new X and Y locations
	void virtual scale(float scaleX,float scaleY) = 0; // Scales an object by X and Y positions
};