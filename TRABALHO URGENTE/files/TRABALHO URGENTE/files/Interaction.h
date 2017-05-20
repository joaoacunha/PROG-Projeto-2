#pragma once

#include "Menu.h"
#include "Shift.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


bool new_line(vector<Line> &linesVec);
bool change_line(vector<Line> &linesVec);
void change_line_frequency(vector<Line> &linesVec, int index);
void change_line_busStops(vector<Line> &linesVec, int index);
bool remove_line(vector<Line> &linesVec);


bool new_driver(vector<Driver> &driversVec);
bool change_driver(vector<Driver> &driversVec);
void change_driver_name(vector<Driver> &driversVec, string actualName, int index);
void change_driver_maxHours(vector<Driver> &driversVec, int actualShift, int index);
void change_driver_maxWeekWorkingTime(vector<Driver> &driversVec, int actualMaxHours, int index);
void change_driver_minRestTime(vector<Driver> &driversVec, int actualMinRestTime, int index);
bool remove_driver(vector<Driver> &driversVec);