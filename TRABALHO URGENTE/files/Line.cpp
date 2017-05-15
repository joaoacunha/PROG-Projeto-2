#include "Line.h"

using namespace std;


Line::Line(unsigned int new_id, unsigned int new_frequency, vector<string> new_busStopList, vector<int> new_timesList, unsigned int new_numberofBuses)
{
	this->id = new_id;
	this->frequency = new_frequency;
	this->busStopList = new_busStopList;
	this->timings = new_timesList;
	this->numberOfBuses = new_numberofBuses;

}
////////////////
// get methods
////////////////

unsigned int Line::getId() const{
  return this->id;
}

unsigned int Line::getFrequency() const {
	return this->frequency;
}

vector<string> Line::getBusStops() const{
  return this->busStopList;
}

vector<int> Line::getTimings() const{
  return this->timings;
}


void Line::setId(int id)
{
	this->id = id;
}

void Line::setFrequency(int frequency)
{
	this->frequency = frequency;
}

void Line::setBusStops(vector<string> busStops)
{
	this->busStopList = busStops;
}

void Line::setTimings(vector<int> timings)
{
	this->timings = timings;
}