#include "Auxiliar.h"


int verifies_int(int beginning, int end)
{
	string temp;							//saves user input
	int choice;
	getline(cin, temp);

	for (int i = 0; i < temp.size(); i++)	//verfies if characters are integer
	{
		if (!isdigit(temp[i]))
			return -1;						//1st error: not an integer
	}

							
	stringstream ss;						//moves string to ss, and then to an int variable(choice)
	ss << temp;
	ss >> choice;

	if (choice >= beginning && choice <= end)
		return choice;
	else
		return -2;							//2nd error: a number outside the given limits
}

int verifies_int()
{
	string temp;							//saves user input
	int choice;
	getline(cin, temp);

	for (int i = 0; i < temp.size(); i++)	
	{
		if (!isdigit(temp[i]))
			return -1;						
	}

	stringstream ss;						
	ss << temp;
	ss >> choice;

	return choice;

}

int verifies_int(int minimum)
{
	string temp;							
	int choice;
	getline(cin, temp);

	for (int i = 0; i < temp.size(); i++)	
	{
		if (!isdigit(temp[i]))
			return -1;						
	}


	stringstream ss;						
	ss << temp;
	ss >> choice;

	if (choice >= minimum)
		return choice;
	else
		return -2;							
}
