#pragma once

//This template is used to compare the area of 2 shapes
// It is declared in the Shape header file as a friend class , giving access to the fields of the Shape class 
template <class T>
class compareT
{
public:
	compareT(T obj1, T obj2) {
		// Copies the objects 
		a = obj1;
		b = obj2;
	};
	// This method compares the values
	void comparing()
	{
		std::cout << "The Shape with the Biggest area is:\n\n";

		//Compares the 2 objects areas , displays the one which has the biggest area
		if (a->area > b->area) {
			 a->toString();
		}
		else
		{
			 b->toString();
		}
	}
private:
	T a,b;
};


