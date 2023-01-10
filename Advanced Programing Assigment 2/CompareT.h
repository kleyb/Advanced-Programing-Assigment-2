#pragma once

//
template <class T>
class compareT
{
public:
	compareT(T obj1, T obj2) {
		a = obj1;
		b = obj2;
	};
	void comparing()
	{
		std::cout << "The Shape with the Biggest area is:\n ";

		if (a->calculateArea() > b->calculateArea()) {
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


