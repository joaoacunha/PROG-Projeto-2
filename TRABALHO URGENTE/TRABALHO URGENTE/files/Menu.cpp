#include "Menu.h"
#include "Interaction.h"


/**
*function that returns user input or error
*/
int starting_menu()
{
	cout << "Welcome" << endl;
	cout << "Please select an option: " << endl;
	cout << "(0) To exit" << endl;
	cout << "(1) Lines Management" << endl;
	cout << "(2) Drivers Management" << endl;
	cout << "(3) Data Visualization" << endl;
	cout << "> ";
	return verifies_int(0,3);	
}

/**
*function that returns user input or error
*/
int lines_menu()
{
	cout << "Lines Management" << endl;
	cout << "Please select an option: " << endl;
	cout << "(0) To go back" << endl;
	cout << "(1) Create a new line" << endl;
	cout << "(2) Change line" << endl;
	cout << "(3) Remove line" << endl;
	cout << "> ";

	return verifies_int(0,3);
}

/**
*function that returns user input or error
*/
int drivers_menu()
{
	cout << "Drivers Management" << endl;
	cout << "Please select an option: " << endl;
	cout << "(0) To go back" << endl;
	cout << "(1) Create new driver" << endl;
	cout << "(2) Change driver" << endl;
	cout << "(3) Remove driver" << endl;
	cout << "> ";

	return verifies_int(0, 3);
}

/**
*function that returns user input or error
*/
int visualization_menu()
{
	cout << "Data visualization" << endl;
	cout << "Please select an option: " << endl;
	cout << "(0) To go back" << endl;
	cout << "(1) Bus stop timetable" << endl;
	cout << "(2) Line timetable" << endl;
	cout << "(3) Work given to a driver (MAINTENANCE)" << endl; //I don't believe I have enough information
	cout << "(4) What lines include given bus stop" << endl; 
	cout << "(5) Drivers list" << endl;
	cout << "(6) Calculate time between two bus stops" << endl; //paragens estao na mesma linha
	cout << "(7) Calculate the number of necessary drivers (MAINTENANCE)" << endl; 
																		
	cout << "> ";

	return verifies_int(0, 7);
}


void starting_options(vector<Driver> driversVec, vector<Line> linesVec)
{
	int choice = 1;
	while (choice != 0)
	{
		switch(choice = starting_menu())
		{
		case 0: return;
			break;
		case 1: lines_options(linesVec);
			break;
		case 2: drivers_options(driversVec);
			break;
		case 3: visualization_options(driversVec, linesVec);
			break;
		case -1: cout << "Please type an integer number between 0 and 3" << endl;
			break;
		}
	}
}

void lines_options(vector<Line> linesVec)
{
	int choice = 1;
	while (choice != 0)
	{
		switch (choice = lines_menu())
		{
		case 0: return;
			break;
		case 1: new_line(linesVec);
			break;
		case 2: change_line(linesVec);
			break;
		case 3: remove_line(linesVec);
			break;
		case -1: cout << "Por favor introduza um numero inteiro entre 0 e 3" << endl;
			break;
		}
	}

}

void drivers_options(vector<Driver> driversVec)
{
	int choice = 1;
	while (choice != 0)
	{
		switch (choice = drivers_menu())
		{
		case 0: return;
			break;
		case 1: //new_driver(driversVec);
			break;
		case 2: //change_driver(driversVec);
			break;
		case 3: //remove_driver(driversVec);
			break;
		case -1: cout << "Please type an integer number between 0 and 3" << endl;
			break;
		}
	}

}

void visualization_options(vector<Driver> driversVec, vector<Line> linesVec)
{
	int choice = 1;
	while (choice != 0)
	{
		switch (choice = visualization_menu())
		{
		case 0: return;
			break;
		case 1: //bus_timetable(); //asks for bus stop, see what lines contain that bus stop and what time
			break;																		//(initial_time + frequency)		
		case 2: //line_timetable(gestao); //do first line then add frequency?
			break;
		case 3: cout << "Maintenance";
			return;
			break;
		case 4: //verifies_bus_stop(gestao); //see if bus stop belongs to line
			break;
		case 5: cout << "Maintenance";
			return;
			break;
		case 6: //time_between_stops(gestao); //ver o tempo entre duas paragens da mesma linha
			break;
		case 7: cout << "Maintenance";
			return;
			break;
		}
	}
}