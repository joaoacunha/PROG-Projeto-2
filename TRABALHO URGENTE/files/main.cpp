#include <iostream>
#include <vector>
#include "FileManagement.h"
#include "Menu.h"


int main()
{
	vector<Driver> newDriver;
	vector<Line> newLine;

	newDriver = readDriver();
	newLine = readLine();
	starting_options(newDriver, newLine);

  return 0;
}
