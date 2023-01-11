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
#include"CompareT.h"

#include <iostream>
#include <string>
#include <algorithm> // Use Algorithm STL for lambda expression 
#include "Driver.h"

using namespace std;

void commandsMenu()
{	// Dispplays all the commands and the format they must be entered 
	cout << "\nPlease note the commands available to you and remember to enter in the correct format:\n";
	cout << "For Rectangle:  addR <x_coordinate_leftTopPoint> <y_coordinate_leftTopPoint> <height> <width>\n";
	cout << "For Square:	addS <x_coordinate_leftTopPoint> <y_coordinate_leftTopPoint> <edge_length>\n";
	cout << "For Circle:	addC <x_coordinate_leftTopPoint> <y_coordinate_leftTopPoint> <radius>\n";
	cout << "For Moving:	move <shape_index> <x_coordinate_newLeftTopPoint> <y_coordinate_newLeftTopPoint>\n";
	cout << "For Scaling:	scale <shape_index> <x_scale_amount> <y_scale_amount>\n";
	cout << "For Displaying: display\n";
	cout << "For Clearing:   clear\n";
	cout << "For Comparing Area Size: compare <shape1_index> <shape2_index> \n";
	cout << "To Exit:	exit\n";
}

int main()
{
	string userCommand = "";
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters{}; // this one will hold parameters for the commands
	int x{}, y{}, h{}, e{}, w{}, r{};

	cout << "Welcome to Shapes Handler\n";
	
	// While use doesnt enter the command 'exit' keeps running the program
	while (userCommand.compare("exit") != 0)
	{			
		//Makes sure paramters is always cleaned before going through the loop 
		parameters.clear();
		cout << "Please,enter your command or type in menu to display the Menu: ";

		getline(cin, userCommand); // get the user input
		char* cstr = new char[userCommand.length() + 1];//Created a c string of the size of user command 
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str()); // Copies the string and sends to a specific destination

		//The following code uses a string tokenizer ( strtok_s) to extract every char from the char string
		//it adds every char togher until it finds a space (" ") ,when it starts a new parameter. 
		//It adds all parameters into the 'parameters' vector
		char* next_token = NULL;
		string paramter_s;
		char* parameter = strtok_s(cstr, " ", &next_token);
		while (parameter != NULL) {
			paramter_s = parameter;
			parameters.push_back(paramter_s);
			parameter = strtok_s(NULL, " ", &next_token);
		}
		//Checks if the vector is empty before continuing, preventing errors in case an empty or white space are entered
		if ( parameters.empty()) continue;
		
		//The first index of parameters holds the user command
		string command = parameters[0];

		//Uses the 'compare' method to compare the user command, it returns a 1 if false , 0 if true 
		if (command.compare("addR") == 0) {
			//Checks wether the user enter the correct number of parameters , if not goes back to the beginning of the loop
			if (parameters.size() !=5) {
				cout << "You have entered too few/many commands!\n ";
				continue;
			}
			//Gets all the parameters from the vector and convert them into 'Int'
			x = stoi(parameters[1]); 
			y = stoi(parameters[2]);
			h = stoi(parameters[3]);
			w = stoi(parameters[4]);
			// Create a instance of the Rectangle obj
			Rectangle* r = new Rectangle(&x, &y, &h, &w);
			//Pushes the new obj into the shapes vector
			shapes.push_back(r);
			
			//Overloaded stream extration operator , 
			//mofied into accesseing a non-constant obj in order to access it's methods in addition to properties
			cout << *r << endl;
			
		}
		else if (command.compare("addS") == 0) // compares the user command 
		{
			if (parameters.size() != 4) // Checks wether the user entered the right number of parameters
			{	// if not displayes a message and returns to the beginning of loop
				cout << "You have entered too few/many commands!\n ";
				continue;
			}
			//Gets the parameters
			x = stoi(parameters[1]);
			y = stoi(parameters[2]);
			e = stoi(parameters[3]);

			Square* s = new Square(&x, &y, &e);// new instance of Square obj is created
			shapes.push_back(s);
			//Overloaded stream extration operator 
			cout << *s << endl;
		}

		else if (command.compare("addC") == 0) // Compares the user command
		{
			if (parameters.size() != 4) // checks if user entered the right number of parameters
			{	//if not displays message and returns to the beginning of loop
				cout << "You have entered too few/many commands!\n ";
				continue;
			}
			//gets the parameters 
			x = stoi(parameters[1]);
			y = stoi(parameters[2]);
			r = stof(parameters[3]);
		
			Circle* c = new Circle(&x,&y,r); // new instance of Cicle is created
			shapes.push_back(c);
			//Overloaded stream extration operator 
			cout << *c << endl;
			
		}
		else if (command.compare("scale") == 0) {
			
			if (shapes.empty()) {
				cout << "There are no shapes to be scaled\n";
				continue;
			}
			// if shape is isotropic , only 'x' is taken into account
			else if (stoi(parameters[1]) > shapes.size() || (stoi(parameters[1])) < 1) {
				cout << "The shape you have selected doens't exist" << endl; continue;
			}
			else if (parameters.size() != 4 || parameters.size() == 1) {
				cout << "You have entered too many/little parameters\n";
				continue;
			}
			
			int shapeNo = stoi(parameters[1]);
			x = stoi(parameters[2]);
			y = stoi(parameters[3]);
			// creates a pointer to a derived class obj of movable, and uses it to scale 
			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo-1]);
			m->scale(x, y);
			//uses the operator overloading to display the new position
			cout << *shapes[shapeNo-1] << endl;
			
		}
		else if (command.compare("move") == 0) {
			if (shapes.empty()) {
				cout << "There are no shapes to be moved\n";
				continue;
			}			
			else if (stoi(parameters[1]) > shapes.size() || (stoi(parameters[1])) < 1) {
				// checks if the selected shape to scale exist
				// if shape doesn't exists ,displays message and continue loop
				cout << "The shape you have selected doens't exist" << endl; 
				continue;
			}
			else if (parameters.size() != 3 || parameters.size() == 1) {
				cout << "You have entered too many/little parameters\n";
				continue;
			}
			
			// move object at index 
			int shapeNo = stoi(parameters[1]);
			x = stoi(parameters[2]);
			y = stoi(parameters[3]);

			//uses dynamic cast to create a point from base class into a deverived class obj
			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			m->move(x, y);
			//uses overloaded operator
			cout << *shapes[shapeNo - 1] << endl;
		}
		else if (command.compare("display") == 0) // uses the compare method to check the user command
		{
			if (shapes.empty()) // Check if the shapes vector is empty , it is then it's not possible to display
			{	// if there are no shapes , display message and display
				cout << "The are no shapes to be displayed\n ";
				parameters.clear();
				continue;
			}

			//Lambda Function to iterate and display all shapes in the vector
			// the function is assigned into the variable called displayValues
			auto displayValues = [](auto shapesVec) {
				for_each(shapesVec.begin(), shapesVec.end(),
					[](auto i) { cout << *i << endl; }
				);
			};
			// Calls function to display shapes
			displayValues(shapes);
		}
		else if (command.compare("clear") == 0) // uses compare method to check the user command
		{	//Clears the shape vector
			shapes.clear();
			
			//shapes =vector <Shape*>();
			//vector<Shape*>().swap(shapes);
			shapes.shrink_to_fit(); // Dealocates the memory ,by reducing the size of array ,equivalent to swapping 
		}
		else if(command.compare("exit") == 0) continue; // Makes sure the game ends when the exit command is entered 
		else if ( command.compare("compare") == 0) {
			if (stoi(parameters[1]) > shapes.size() || (stoi(parameters[1])) < 1) {
				// checks if the selected shape to scale exist
				// if shape doesn't exists ,displays message and continue loop
				cout << "The shape you have selected doens't exist" << endl;
				continue;
			}
			else if (stoi(parameters[2]) > shapes.size() || (stoi(parameters[2])) < 1) {
				// checks if the selected shape to scale exist
				// if shape doesn't exists ,displays message and continue loop
				cout << "The shape you have selected doens't exist" << endl;
				continue;
			}

			x = stoi(parameters[1]);
			y = stoi(parameters[2]);
			compareT<Shape*> shapeM(shapes[x-1], shapes[y-1]);
			
			shapeM.comparing();
		}
		else if (command.compare("menu") == 0) {
			//Displays the menu to the user
			commandsMenu();
		}
		else // if no valid command is entered then displays message 
		{
			cout << "You have entered an invalid command, please try again\n ";
		}
		
		cout << endl << endl;
		
		cout << "Press any key to continue...\n";
		std::getchar();
	}
		return 0;
	
}
