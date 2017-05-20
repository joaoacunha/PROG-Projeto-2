#pragma once
#include "Line.h"
#include "Driver.h"
#include "Auxiliar.h"

void starting_options(vector<Driver> driversVec, vector<Line> linesVec);
void lines_options(vector<Line> linesVec);
void drivers_options(vector<Driver> driversVec);
void visualization_options(vector<Driver> driversVec, vector<Line> linesVec);
int starting_menu();
int lines_menu();
int drivers_menu();
int visualization_menu();
