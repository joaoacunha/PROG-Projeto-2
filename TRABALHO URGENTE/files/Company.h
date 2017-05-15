#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Line.h"
#include "Driver.h"


using namespace std;

class Company{
 private:
  string nome;
  vector<Driver> condutores;
  vector<Line> linhas;
 public:
	 Company(string name, string DriversFile, string LinesFile);
  // metodos get
  string getName() const;
  // metodos set
  // outros metodos
};
