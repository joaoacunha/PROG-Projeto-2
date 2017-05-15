#include "Interaction.h"


//1- LINES
bool new_line(vector<Line> &linesVec)
{
	
	string stop;
	int newId, newFrequency;
	vector<string> newBusStopList;
	vector<int> newTimesList;

	cout << "Line Creation" << endl;

	cout << "Introduza o id (numero inteiro): ";
	newId = verifies_int();
	while (newId == -1)
	{
		cout << "Por favor introduza um id que seja numero inteiro e positivo" << endl;
		newId = verifies_int();
	}

	cout << "Introduza a frequencia de circulacao dos autocarros (numero inteiro de minutos): ";
	newFrequency = verifies_int();
	while (newFrequency == -1)
	{
		cout << "Por favor introduza um numero de minutos inteiro" << endl;
		newFrequency = verifies_int();
	}

	cout << "Introduza as paragens (0 para terminar)" << endl;
	while (stop != "0")
	{
		getline(cin, stop);
		if (stop == "0")
			break;
		newBusStopList.push_back(stop); 
	}
	
	cout << "Introduza o tempo entre as paragens" << endl;
	for (unsigned int i = 0; i < (newBusStopList.size() - 1);)
	{
		int time;
		time = verifies_int(0);
		if (time == -1)
			cout << "Por favor introduza um numero de minutos inteiro e positivo" << endl;
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

	cout << "Frequencia actual (numero inteiro de minutos): " << linesVec[index].getFrequency() << endl; //antiga frequencia
	cout << "Nova frequencia: ";
	newFrequency = verifies_int();
	while (newFrequency == -1)
	{
		cout << "Por favor introduza um numero inteiro e positivo " << endl;
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

	cout << "Paragens actuais: ";
	for (unsigned int i = 0; i < linesVec[i].getBusStops().size(); i++) //alterei
	{
		cout << linesVec[i].getBusStops()[i]; //obtem a stop com index i

		if (i == (linesVec[i].getBusStops().size() - 1)) //alterei
			cout << endl; 
		else
			cout << ", ";
	}

	cout << "Tempo entre cada stop: ";
	for (unsigned int i = 0; i < linesVec[i].getTimings().size(); i++) //alterei
	{
		cout << linesVec[i].getTimings()[i]; //obtem a stop com index i

		if (i == (linesVec[i].getTimings().size() - 1)) //alterei
			cout << endl;
		else
			cout << ", ";
	}
	cout << "Introduza as paragens novas (0 para terminar)" << endl;
	while (stop != "0")
	{
		
		getline(cin, stop);
		if (stop == "0")
			break;
		busStopList_temp.push_back(stop);
	}

	cout << "Introduza o tempo entre as paragens (em minutos)" << endl;
	for (unsigned int i = 0; i < (linesVec[index].getBusStops().size() - 1);)
	{
		novo_tempo_entre_paragens = verifies_int(0);
		if (novo_tempo_entre_paragens == -1)
			cout << "Por favor introduza um tempo que seja numero inteiro e positivo" << endl;

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
	cout << "Alterar " << endl;
	cout << "Indique o id da linha que pretende alterar: " << endl;
	cout << "> ";
	id = verifies_int();
	while (id == -1)
	{
		cout << "Por favor introduza um id que seja numero inteiro e positivo" << endl;
		id = verifies_int();
	}
	int i = 0;
	while (i < linesVec.size())
	{
		if (id == linesVec[i].getId())
		{
			cout << "Pretende alterar" << endl;
			cout << "(0) Frequencia circulacao" << endl;
			cout << "(1) Paragens" << endl;
			cout << "> ";
			choice = verifies_int();
			while (choice == -1)
			{
				cout << "Por favor um introduza 0 ou 1" << endl;
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
	cout << "Nao temos nenhuma linha com esse id" << endl;
	return false;

}

bool remove_line(vector<Line> &linesVec)
{
	int id;
	string choice;
	cout << "Indique o id da linha que pretende remover: " << endl;
	cout << "> ";
	id = verifies_int();
	while (id == -1)
	{
		cout << "Por favor introduza um id que seja numero inteiro e positivo" << endl;
		id = verifies_int();
	}
	int i = 0;

	while (i < linesVec.size())
	{
		if (id == linesVec[i].getId())
		{
			cout << "Tem a certeza que pretende mesmo apagar? (S para sim, N para nao)" << endl; //como se faz isto sabes? em vez de 0 ou 1 ter S ou N
			cout << "> ";
			getline(cin, choice);
			while (choice != "S" && choice != "N")
			{
				cout << "Por favor introduza S para sim ou N para nao" << endl;
				getline(cin, choice);
			}

			if (choice == "S")
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

	cout << "Criacao de condutores" << endl;

	cout << "Introduza o id (numero inteiro): ";
	newId = verifies_int();
	while (newId == -1)
	{
		cout << "Por favor introduza um id que seja numero inteiro e positivo" << endl;
		newId = verifies_int();
	}

	cout << "name do condutor: ";
	getline(cin, name);

	cout << "Numero de horas consecutivas que pode conduzir por dia (um turno): ";
	newShifts = verifies_int();
	while (newShifts == -1)
	{
		cout << "Por favor introduza um id que seja numero inteiro e positivo" << endl;
		newShifts = verifies_int();
	}

	cout << "Numero de horas maximas que pode conduzir por semana: ";
	newMaxWeekWorkingTime = verifies_int();
	while (newMaxWeekWorkingTime == -1)
	{
		cout << "Por favor introduza um numero que seja numero inteiro e positivo" << endl;
		newMaxWeekWorkingTime = verifies_int();
	}

	cout << "Numero de horas minimas de descanso: ";
	newMinRestTime = verifies_int();
	while (newMinRestTime == -1)
	{
		cout << "Por favor introduza um numero que seja numero inteiro e positivo" << endl;
		newMinRestTime = verifies_int();
	}

	vector<Shift> emptyShifts;
	newDriver = Driver(newId, name, newShifts, newMaxWeekWorkingTime, newMinRestTime, emptyShifts);
	driversVec.push_back(newDriver);
	return true; 
}

void change_driver_name(vector<Driver> &driversVec, string actualName, int index) //alterei parametros
{
	string novo_name;

	cout << "name actual do condutor: " << driversVec.[index].getname() << endl; //aceder a name
	cout << "Novo name: ";
	getline(cin, novo_name);

	drivesVec[index].setname(novo_name); //criei funcao altera name
}

void change_driver_maxHours(vector<Driver> &driversVec, int actualShift, int index) //alterei parametros
{
	{
		int newShifts;

		cout << "Turno (numero de horas por dia): " << driversVec[index].getTurno() << endl; //aceder a turno
		cout << "Novo turno: ";
		newShifts = verifies_int(0, 24);
		while (newShifts < 0)
		{
			cout << "Por favor introduza um numero inteiro e positivo, entre 0 e 24 horas" << endl;
			newShifts = verifies_int(0,24);
		}

		driversVec[index].setTurno(newShifts); //criei funcao altera turno
	}
}

void change_driver_maxHours(vector<Driver> &driversVec, int actualShift, int index) //alterei parametros
{
	int novo_horas_max = 0;

	cout << "Horas maximas por semana: " << driversVec[index].getHoras_max() << endl; //aceder a horas_max
	cout << "Novas horas maximas: ";
	novo_horas_max = verifies_int();
	while (novo_horas_max == -1)
	{
		cout << "Por favor introduza um numero inteiro e positivo " << endl;
		novo_horas_max = verifies_int();
	}

	driversVec[index].setHoras_Max(novo_horas_max); //criei funcao altera horas_max
}

void change_driver_minRestTime(vector<Driver> &driversVec, int index) //alterei parametros

{
	int novo_horas_descanso;

	cout << "Horas minimas de descanso entre turnos: " << driversVec[index].getHoras_descanso() << endl; //aceder a horas_descanso
	cout << "Novas horas minimas de descanso: ";
	novo_horas_descanso = verifies_int();
	while (novo_horas_descanso == -1)
	{
		cout << "Por favor introduza um numero inteiro e positivo " << endl;
		novo_horas_descanso = verifies_int();
	}

	driversVec[index].setHoras_Descanso(novo_horas_descanso); //criei funcao altera horas descanso
}

bool altera_condutor(vector<Driver> &driversVec)
{
	int choice, id;
	cout << "Alterar " << endl;
	cout << "Indique o id do condutor que pretende alterar: " << endl;
	cout << "> ";
	id = verifies_int();
	while (id == -1)
	{
		cout << "Por favor introduza um id que seja numero inteiro e positivo" << endl;
		id = verifies_int();
	}
	int i = 0;
	while (i < driversVec.size())
	{
		if (id == driversVec[i].getId())
		{
			cout << "Pretende alterar" << endl;
			cout << "(0) name" << endl;
			cout << "(1) Horas maximas por dia (turno)" << endl;
			cout << "(2) Horas maximas por semana" << endl;
			cout << "(3) Numero minimo de horas de descanso entre turnos" << endl;
			cout << "> ";
			choice = verifies_int(0,3);
			while (choice == -1)
			{
				cout << "Por favor um introduza um numero de 0 a 3" << endl;
				choice = verifies_int();
			}

			switch (choice)
			{
			case 0: altera_condutor_name(gestao, i);
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
			}
		}

		i++;
	}
	cout << "Nao temos nenhuma linha com esse id" << endl;
	return false;

}

bool remove_driver(vector<Driver> &driversVec)
{
	int id;
	string choice;
	cout << "Indique o id do condutor que pretende remover: " << endl;
	cout << "> ";
	id = verifies_int();
	while (id == -1)
	{
		cout << "Por favor introduza um id que seja numero inteiro e positivo" << endl;
		id = verifies_int();
	}
	int i = 0;
	while (i < driversVec.size())
	{
		if (id == driversVec[i].getId())
		{
			cout << "Tem a certeza que pretende mesmo apagar? (S para sim, N para nao)" << endl; 
			cout << "> ";
			getline(cin, choice);
			while (choice != "S" && choice != "N")
			{
				cout << "Por favor introduza S para sim ou N para nao" << endl;
				getline(cin, choice);
			}

			if (choice == "S")
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

*/
