#include "Interaction.h"
#include "Driver.h"

using namespace std;


//1 - LINES
bool new_line(vector<Line> &linesVec)
{
	
	string stop;
	int newId, newFrequency;
	vector<string> newBusStopList;
	vector<int> newTimesList;

	cout << "Line Creation" << endl;

	cout << "Enter the id (integer): ";
	newId = verifies_int();
	while (newId == -1)
	{
		cout << "Please enter an id that is a positive integer" << endl;
		newId = verifies_int();
	}

	cout << "Enter the frequency of the buses (integer in minutes): ";
	newFrequency = verifies_int();
	while (newFrequency == -1)
	{
		cout << "Please enter a positive integer in minutes" << endl;
		newFrequency = verifies_int();
	}

	cout << "Enter the stops (0 to finish)" << endl;
	while (stop != "0")
	{
		getline(cin, stop);
		if (stop == "0")
			break;
		newBusStopList.push_back(stop); 
	}
	
	cout << "Enter the time between stops" << endl;
	for (unsigned int i = 0; i < (newBusStopList.size() - 1);)
	{
		int time;
		time = verifies_int(0);
		if (time == -1)
			cout << "Please enter a positive integer in minutes" << endl;
		else
		{
			newTimesList.push_back(time);
			i++;
		}
	}

	Line temp = Line(newId, newFrequency, newBusStopList, newTimesList, 0);
	linesVec.push_back(temp);
	return true;
}

void change_line_frequency(vector<Line> &linesVec, int index) //alterei so precisas de saber qual Gestao e qual index da linha
{
	int newFrequency;

	cout << "Current frequency (integer in minutes): " << linesVec[index].getFrequency() << endl; //antiga frequencia
	cout << "New frequency: ";
	newFrequency = verifies_int();
	while (newFrequency == -1)
	{
		cout << "Please enter a positive integer in minutes" << endl;
		index = verifies_int();
	}

	linesVec[index].setFrequency(newFrequency); // criei esta funcao que altera a frequencia
}

void change_line_busStops(vector<Line> &linesVec, int index) //alterei as variaveis so precisas de saber a gestao e o index da linha
{
	string stop;
	vector<string> busStopList_temp;
	vector<int> timesList_temp;
	int novo_tempo_entre_paragens;

	cout << "Current stops: ";
	for (unsigned int i = 0; i < linesVec[i].getBusStops().size(); i++) //alterei
	{
		cout << linesVec[i].getBusStops()[i]; //obtem a stop com index i

		if (i == (linesVec[i].getBusStops().size() - 1)) //alterei
			cout << endl; 
		else
			cout << ", ";
	}

	cout << "Time between stops: ";
	for (unsigned int i = 0; i < linesVec[i].getTimings().size(); i++) //alterei
	{
		cout << linesVec[i].getTimings()[i]; //obtem a stop com index i

		if (i == (linesVec[i].getTimings().size() - 1)) //alterei
			cout << endl;
		else
			cout << ", ";
	}
	cout << "Enter the new stops (0 to finish):" << endl;
	while (stop != "0")
	{
		
		getline(cin, stop);
		if (stop == "0")
			break;
		busStopList_temp.push_back(stop);
	}

	cout << "Enter the time between stops (integer in minutes)" << endl;
	for (unsigned int i = 0; i < (linesVec[index].getBusStops().size() - 1);)
	{
		novo_tempo_entre_paragens = verifies_int(0);
		if (novo_tempo_entre_paragens == -1)
			cout << "Please enter a positive integer in minutes" << endl;

		else
		{
			timesList_temp.push_back(novo_tempo_entre_paragens);
			i++;
		} 
	}
	linesVec[index].getBusStops() = busStopList_temp;
	linesVec[index].getTimings() = timesList_temp;
}

bool change_line(vector<Line> &linesVec)
{

	int choice, id;
	cout << "Edit" << endl;
	cout << "Specify the id of the line you intend to edit: " << endl;
	cout << "> ";
	id = verifies_int();
	while (id == -1)
	{
		cout << "Please enter an id that is a positive integer" << endl;
		id = verifies_int();
	}
	int i = 0;
	while (i < linesVec.size())
	{
		if (id == linesVec[i].getId())
		{
			cout << "Do you intend to edit:" << endl;
			cout << "(0) Frequency" << endl;
			cout << "(1) Stops" << endl;
			cout << "> ";
			choice = verifies_int();
			while (choice == -1)
			{
				cout << "Please enter 0 or 1" << endl;
				choice = verifies_int();
			}

			switch (choice)
			{
			case 0: change_line_frequency(linesVec, i);
				return true;
				break;
			case 1: change_line_busStops(linesVec, i);
				return true;
				break;
			}
		}

		i++;
	}
	cout << "There is no line with that id" << endl;
	return false;

}

bool remove_line(vector<Line> &linesVec)
{
	int id;
	string choice;
	cout << "Specify the id of the line you intend to remove: " << endl;
	cout << "> ";
	id = verifies_int();
	while (id == -1)
	{
		cout << "Please enter an id that is a positive integer" << endl;
		id = verifies_int();
	}
	int i = 0;

	while (i < linesVec.size())
	{
		if (id == linesVec[i].getId())
		{
			cout << "Are you sure you want to remove this line? (Y for yes, N for no)" << endl; //como se faz isto sabes? em vez de 0 ou 1 ter S ou N
			cout << "> ";
			getline(cin, choice);
			while (choice != "Y" && choice != "N")
			{
				cout << "Please enter Y for yes or N for no" << endl;
				getline(cin, choice);
			}

			if (choice == "Y")
			{
				//Fazer funcao para apagar
				linesVec.erase(linesVec.begin() + i);
				return true;
			}
			else
				return false;
		}
		i++;
	}
	return false; 
}

//-------------------------------------------------------------------

void change_driver_name(vector<Driver> &driversVec, string actualName, int index);
void change_driver_maxHours(vector<Driver> &driversVec, int actualShift, int index);
void change_driver_maxWeekWorkingTime(vector<Driver> &driversVec, int actualMaxHours, int index);
void change_driver_minRestTime(vector<Driver> &driversVec, int actualMinRestTime, int index);
bool remove_driver(vector<Driver> &driversVec);

bool new_driver(vector<Driver> &driversVec)
{
	string stop;
	int newId, newMaxWeekWorkingTime, newShifts, newMinRestTime;
	string name;
	vector<Driver> newDriver;

	cout << "Driver Creation" << endl;

	cout << "Enter the id (integer): ";
	newId = verifies_int();
	while (newId == -1)
	{
		cout << "Please enter an id that is a positive integer" << endl;
		newId = verifies_int();
	}

	cout << "Driver's name: ";
	getline(cin, name);

	cout << "Number of consecutive hours he can drive in one shift: ";
	newShifts = verifies_int();
	while (newShifts == -1)
	{
		cout << "Please enter a positive integer in hours" << endl;
		newShifts = verifies_int();
	}

	cout << "Maximum number of hours he can drive in one week: ";
	newMaxWeekWorkingTime = verifies_int();
	while (newMaxWeekWorkingTime == -1)
	{
		cout << "Please enter a positive integer in hours" << endl;
		newMaxWeekWorkingTime = verifies_int();
	}

	cout << "Minimum number of hours he has to rest between shifts: ";
	newMinRestTime = verifies_int();
	while (newMinRestTime == -1)
	{
		cout << "Please enter a positive integer in hours" << endl;
		newMinRestTime = verifies_int();
	}

	vector<Shift> emptyShifts;
	//newDriver = Driver(newId, name, newShifts, newMaxWeekWorkingTime, newMinRestTime, emptyShifts);
	//driversVec.push_back(newDriver);
	return true; 
}

void change_driver_name(vector<Driver> &driversVec, string actualName, int index) //alterei parametros
{
	string name;

	//cout << "Current name: " << driversVec.[index].getName() << endl; //aceder a name
	//cout << "New name: ";
	getline(cin, name);

	driversVec[index].setName(name); //criei funcao altera name
}

void change_driver_shift(vector<Driver> &driversVec, int actualShift, int index) //alterei parametros
{
	{
		int newShifts;

		//cout << "Current shift (number of hours per day): " << driversVec[index].getShifts() << endl; //aceder a turno
		cout << "New shift (number of hours per day): ";
		newShifts = verifies_int(0, 24);
		while (newShifts < 0)
		{
			cout << "Please enter a positive integer in hours between 0 and 24" << endl;
			newShifts = verifies_int(0,24);
		}

		//driversVec[index].setShifts(newShifts); //criei funcao altera turno
	}
}

void change_driver_maxHours(vector<Driver> &driversVec, int actualShift, int index) //alterei parametros
{
	int maxHours = 0;

	cout << "Current maximum hours per week: " << driversVec[index].getMaxHours() << endl; //aceder a horas_max
	cout << "New maximum hours per week: ";
	maxHours = verifies_int();
	while (maxHours == -1)
	{
		cout << "Please enter a positive integer in hours" << endl;
		maxHours = verifies_int();
	}

	driversVec[index].setMaxHours(maxHours); //criei funcao altera horas_max
}

void change_driver_minRestTime(vector<Driver> &driversVec, int index) //alterei parametros

{
	int minRestTime;

	cout << "Current minimum resting hours between shifts: " << driversVec[index].getMinRestTime() << endl; //aceder a horas_descanso
	cout << "New minimum resting hours between shifts: ";
	minRestTime = verifies_int();
	while (minRestTime == -1)
	{
		cout << "Please enter a positive integer in hours" << endl;
		minRestTime = verifies_int();
	}

	driversVec[index].setMinRestTime(minRestTime); //criei funcao altera horas descanso
}

bool altera_condutor(vector<Driver> &driversVec)
{
	int choice, id;
	cout << "Edit" << endl;
	cout << "Specify the id of the driver you intend to edit: " << endl;
	cout << "> ";
	id = verifies_int();
	while (id == -1)
	{
		cout << "Please enter an id that is a positive integer" << endl;
		id = verifies_int();
	}
	int i = 0;
	while (i < driversVec.size())
	{
		if (id == driversVec[i].getId())
		{
			cout << "Do you intend to edit:" << endl;
			cout << "(0) Name" << endl;
			cout << "(1) Shift (hours per day)" << endl;
			cout << "(2) Maximum hours per week" << endl;
			cout << "(3) Minimum resting hours between shifts" << endl;
			cout << "> ";
			choice = verifies_int(0,3);
			while (choice == -1)
			{
				cout << "Please enter a positive integer between 0 and 3" << endl;
				choice = verifies_int();
			}

			/*switch (choice) //WE NEED TO CHANGE THIS SHIET
			{
			case 0: altera_condutor_name(gestao, i);                //TEMOS MESMO DE MUDAR ISTO, PRECISO DE AJUDA
				return true;
				break;
			case 1: altera_condutor_turno(gestao, i);
				return true;
				break;
			case 2: altera_condutor_horas_maximas(gestao, i);
				return true;
				break;
			case 3: altera_condutor_horas_descanso(gestao, i);
				return true;
				break;
			}*/
		}

		i++;
	}
	cout << "There is no line with that id" << endl;
	return false;

}

bool remove_driver(vector<Driver> &driversVec)
{
	int id;
	string choice;
	cout << "Specify the id of the driver you intend to remove: " << endl;
	cout << "> ";
	id = verifies_int();
	while (id == -1)
	{
		cout << "Please enter an id that is a positive integer" << endl;
		id = verifies_int();
	}
	int i = 0;
	while (i < driversVec.size())
	{
		if (id == driversVec[i].getId())
		{
			cout << "Are you sure you want to remove this driver? (Y for yes, N for no)" << endl; 
			cout << "> ";
			getline(cin, choice);
			while (choice != "Y" && choice != "N")
			{
				cout << "Please enter Y for yes or N for no" << endl;
				getline(cin, choice);
			}

			if (choice == "Y")
			{
				//Fazer funcao para apagar
				driversVec.erase(driversVec.begin() + i);				return true;
			}
			else
				return false;
		}
		i++;
	}
	return false;
}
