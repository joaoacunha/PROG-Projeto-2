#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


#include "Driver.h"
#include "Line.h"

using namespace std;

vector<Driver> readDriver();
vector<Line> readLine();
bool writeLine(vector<Line> linesVec);




