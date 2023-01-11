#pragma once
class Points {
public:
	Points();
	void setX(float x); // sets value of x
	void setY(float y); //sets value of y
	int getX(); // returns value of x
	int getY(); // returns value of y
private:
	float x, y;
};
