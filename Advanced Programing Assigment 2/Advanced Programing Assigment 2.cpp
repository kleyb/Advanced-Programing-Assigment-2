/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK!

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string userCommand = "";
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters{}; // this one will hold parameters for the commands
	int x{}, y{}, h{}, e{}, w{}, r{};

	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";

		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str()); // Copies the string and sends to a specific destination

		// implement a string tokenizer to populate the parameters vector 
		// check function strtok_s

		char* next_token = NULL;
		string paramter_s;
		char* parameter = strtok_s(cstr, " ", &next_token);

		while (parameter != NULL) {
			//cut << parameter << endl;
			paramter_s = parameter;
			parameters.push_back(paramter_s);
			parameter = strtok_s(NULL, " ", &next_token);

		}
		//Checks if the vector is empty before contining , preventing errors in case an empty or white space is entered
		if ( parameters.empty()) continue;
		
		// as a result of the process, parameters[0] should hold your command, followed by your parameters 
		string command = parameters[0];


		// in the following code, consider checking for the arguments.
		// in case of too few arguments, you may remind the user the correct format

		if (command.compare("addR") == 0) {
			// get parameters in the correct order
			// The following four lines have a type mismatch error
			// note that the the parameters vector contains ascii values
			// HINT: stoi function converts from string to int

			x = stoi(parameters[1]); // fix me! also note that x is not previously defined :(
			y = stoi(parameters[2]);
			h = stoi(parameters[3]);
			w = stoi(parameters[4]);


			Rectangle* r = new Rectangle(x, y, h, w);
			shapes.push_back(r);
			
			//Overloaded stream extration operator , 
			//mofied into accesseing a non-constant obj in order to access it's methods in addition to properties
			cout << *r << endl;
			
		}
		else if (command.compare("addS") == 0) {
			x = stoi(parameters[1]);
			y = stoi(parameters[2]);
			e = stoi(parameters[3]);
			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			//Overloaded stream extration operator 
			cout << *s << endl;
		}

		else if (command.compare("addC") == 0) {

			x = stoi(parameters[1]);
			y = stoi(parameters[2]);
			r = stoi(parameters[3]);
			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			//Overloaded stream extration operator 
			cout << *c << endl;
		}
		else if (command.compare("scale") == 0) {
			// scale object at index... the scaling needs to be isotropic in case of circle and square 
			// you may want to check if the index exists or not!
			int shapeNo = stoi(parameters[1]);
			x = stoi(parameters[2]);
			y = stoi(parameters[3]);
			// Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
			// As a result all your derived classes have scale functions... 
			// You may need to use type casting wisely to use polymorphic functionality!
			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo]);
			m->scale(x, y);

			cout << *shapes[shapeNo] << endl;
		}
		else if (command.compare("move") == 0) {
			// move object at index 
			if ((stoi(parameters[1])) > shapes.size()) continue;
			
			int shapeNo = stoi(parameters[1]);
			x = stoi(parameters[2]);
			y = stoi(parameters[3]);
			
			 // read from parameters
			// you may want to check if the index exists or not!

			// Study the following code. A Shape object is not Movable, but all derived classes are...
			// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			m->move(x, y);
			// scale should work similarly...

			// note that here you should see the corresponding toString output for the derived classes...
			// if toString is not a virtual function, you may see the base class functionality :(
			
			cout << *shapes[shapeNo - 1] << endl;

		}
		else if (command.compare("display") == 0) {
			if (shapes.empty())
			{
				parameters.clear();
				continue;
			}
			for (auto value : shapes )
			{
				cout << *value << endl;
			}
		}
		else if (command.compare("clear") == 0)
		{
			shapes.clear();
			
			//shapes =vector <Shape*>();
			vector<Shape*>().swap(shapes);
			//shapes.shrink_to_fit(); // Dealocates the memory , by reducing the size of array , equivalent to swapping 
		}
		else if(command.compare("exit") == 0) continue; // Makes sure the game ends when the exit command is entered 
		else 
		{
			cout << "You have entered an invalid value, please try again\n ";
		}

		// do any necessary postprocessing at the end of each loop...
		// yes, there is some necessary postprocessing...

		cout << endl << endl;
		
		parameters.clear();
		//userCommand = "";
		cout << "Press any key to continue...";
		std::getchar();
	}
		return 0;
	
}
