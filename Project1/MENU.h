#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//MENU
class MENU 
{
public:
	//Metoda wirtualna (abstrakcyjna)
	virtual void run(int n) = 0;
	string read();
	void sortAndDisplayTop10Results(const std::string& filename);
};

