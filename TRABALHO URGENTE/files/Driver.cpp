#include "Driver.h"


Driver::Driver(unsigned int NewId, string NewName, unsigned int NewMaxHours, unsigned int NewMaxWeekWorkingTime, unsigned int NewMinRestTime, vector<Shift> NewShifts)
{
	this->id = NewId;
	this->name = NewName;
	this->maxHours = NewMaxHours;
	this->maxWeekWorkingTime = NewMaxWeekWorkingTime;
	this->minRestTime = NewMinRestTime;
	this->shifts = NewShifts;
}


//////////////
// get methods
//////////////

unsigned int Driver::getId() const{
  return this->id;
}

string Driver::getName() const{
  return this->name;
}

unsigned int Driver::getMaxHours() const{
  return this->maxHours;
}

unsigned int Driver::getMaxWeekWorkingTime() const{
  return this->maxWeekWorkingTime;
}

unsigned int Driver::getMinRestTime() const{
  return this->minRestTime;
}

vector<Shift> Driver::getShifts() const{
  return this->shifts;
}

///////////////
// set methods
//////////////

void Driver::setId(int id)
{
	this->id = id;
}

void Driver::setName(string name)
{
	this->name = name;
}

void Driver::setMaxHours(int maxHours)
{
	this->maxHours = maxHours;
}

void Driver::setMaxWeekWorkingTime(int maxWeekWorkingTime)
{
	this->maxWeekWorkingTime = maxWeekWorkingTime;
}

void Driver::setMinRestTime(int minRestTime)
{
	this->minRestTime = minRestTime;
}

void Driver::setShifts(vector<Shift> shifts)
{
	this->shifts = shifts;
}
