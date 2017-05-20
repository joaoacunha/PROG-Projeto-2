#include "FileManagement.h"


/**
Reads the Drivers' file
*/
vector<Driver> readDriver()
{
	string fileName;
	vector<Driver> driversVec;
	ifstream myfile;
	char dummy;
	cout << "Please enter drivers file's name" << endl;
	cout << "> ";
	getline(cin, fileName);
	fileName = fileName + ".txt";
	myfile.open(fileName);

	while (!myfile.is_open())
	{
		cerr << "File not found !\n";
		cout << "Please try again" << endl;
		cout << "> ";
		getline(cin, fileName);
		fileName = fileName + ".txt";
		myfile.open(fileName);
	}

	while (myfile.good())
	{
		unsigned int id, shift, maxHours, maxWeekWorkingTime, minRestTime;
		string name, b;
		istringstream ss;

		myfile.clear();
		getline(myfile, b, '\n');			//we extract 1st line to b
		ss.str(b);							//ss: 1 ; Antonio Manuel ; 4 ; 36 ; 2
		ss >> id;							//saves id
		ss >> dummy;

		getline(ss, name, ';');				//name now has the full name
		name.erase(0, 1);					//removes the space before
		name.resize(name.size() - 1);		//removes the space afterwards

		ss >> maxHours;
		ss >> dummy;
		ss >> maxWeekWorkingTime;
		ss >> dummy;
		ss >> minRestTime;
		vector<Shift> emptyShift;

		Driver newDriver = Driver(id, name, maxHours, maxWeekWorkingTime, minRestTime, emptyShift); //creates the new Driver
		driversVec.push_back(newDriver);
	}
	myfile.close();
	return driversVec;
}

/**
Reads the Lines' file
*/
vector<Line> readLine()
{
	string fileName;
	vector<Line> LinesVec;
	ifstream myfile;
	char dummy;

	cout << "Please enter lines file's name" << endl;
	cout << "> ";
	getline(cin, fileName);
	fileName = fileName + ".txt";
	myfile.open(fileName);

	while (!myfile.is_open())
	{
		cerr << "File not found !\n";
		cout << "Please try again" << endl;
		cout << "> ";
		getline(cin, fileName);
		fileName = fileName + ".txt";
		myfile.open(fileName);
	}

	while (myfile.good())
	{
		unsigned int id, frequency, numberofBuses;
		vector<string> busStopList;
		vector<int> timesList;
		string name, b;
		istringstream ss;				//para ser mais facil a extracao

		myfile.clear();
		getline(myfile, b, '\n');       //passamos a primeira linha para b
		ss.str(b);						//201 ; 20 ; Paranhos, Monte dos Burgos, ISEP, Hospital de Sao Joao; 10, 20, 45
		ss >> id;						//o inteiro(201)
		ss >> dummy;					//tira o ';'
		ss >> frequency;				//frequencia(20)
		ss >> dummy;					//tira o ';'


										//ss = Paranhos, Monte dos Burgos, ISEP, Hospital de Sao Joao; 10, 20, 45
		string c;
		getline(ss, c, ';');			// c = "Paranhos, Monte dos Burgos, ISEP, Hospital de Sao Joao"
		c = c + ",";					// c = " Paranhos, Monte dos Burgos, ISEP, Hospital de Sao Joao,"
		stringstream ss2;
		ss2.str(c);


		while (getline(ss2, c, ','))
		{
			c.erase(0, 1);
			busStopList.push_back(c);
		}

		string d;
		int e;
		getline(ss, d);
		d = d + ",";
		stringstream ss3;
		ss3.str(d);

		while (getline(ss3, d, ','))
		{
			e = stoi(d);
			timesList.push_back(e);
		}
		unsigned int noBuses = 0;													//every line starts with 0 buses
		Line newLine = Line(id, frequency, busStopList, timesList, noBuses);
		LinesVec.push_back(newLine);
	}

	myfile.close();
	return LinesVec;
}

/**
*funcao que escreve a informacao do vetor linesVec no ficheiro
@param linesVec vector que armazena a informacao de cada linha presente no ficheiro .txt
*/

bool writeLine(vector<Line> linesVec)
{
	string fileName;
	ofstream myfile;
	cout << "Please enter drivers file's name" << endl;
	cout << "> ";
	getline(cin, fileName);
	fileName = fileName + ".txt";
	myfile.open(fileName);

	while (!myfile.is_open())
	{
		cerr << "File not found !\n";
		cout << "Please try again" << endl;
		cout << "> ";
		getline(cin, fileName);
		fileName = fileName + ".txt";
		myfile.open(fileName);
	}

	while (myfile.good())
	{
		for (unsigned int i = 0; i < linesVec.size(); i++)
		{
			//201 ; 20 ; Paranhos, Monte dos Burgos, ISEP, Hospital de Sao Joao; 10, 20, 45
			myfile.clear();
			myfile << linesVec[i].getId();
			myfile << " ; ";
			myfile << linesVec[i].getFrequency();
			myfile << " ; ";

			unsigned int j = 0;
			while (j < linesVec[i].getBusStops().size())
			{
				if (j == (linesVec[i].getBusStops().size() - 1))
				{
					myfile << linesVec[i].getBusStops()[j];
					myfile << "; ";
					break;
				}
				else
				{
					myfile << linesVec[i].getBusStops()[j];
					myfile << ", ";
					j++;
				}
			}

			unsigned int j2 = 0;
			while (j2 < linesVec[i].getTimings().size())
			{
				if (j2 == (linesVec[i].getTimings().size() - 1))
				{
					myfile << linesVec[i].getTimings()[j2];
					if (i != linesVec.size() - 1)
						myfile << endl;
					break;
				}

				else
				{
					myfile << linesVec[i].getTimings()[j2];
					myfile << ", ";
					j2++;
				}
			}
			i++;
		}
		myfile.close();
		return true;
	}
}