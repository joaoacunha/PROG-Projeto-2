#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Line
{
 private:
  unsigned int id;
  unsigned int frequency;
  vector<string> busStopList;
  vector<int> timings;
  unsigned int numberOfBuses;
 public:
	 Line(unsigned int id,unsigned int frequency, vector<string> busStopList, vector<int> timesList, unsigned int numberofBuses);
	 
	 unsigned int getId() const;
	 unsigned int getFrequency() const;
	 vector<string> getBusStops() const;
	 vector<int> getTimings() const;
	 
	 
	 void setId(int id);
	 void setFrequency(int frequency);
	 void setBusStops(vector<string> busStops);
	 void setTimings(vector<int> timings);
	 
  // set methods
  // other methods

};
