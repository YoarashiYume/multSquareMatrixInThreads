#ifndef _DATA_H_
#define _DATA_H_
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
class Data
{
protected:
	//keep matrix in one vector
	std::vector<int> matrix; 
	int SIZE;
	Data(int size_);
public:
	Data(std::string patch);
	void showMatrix();
	int getCell(int row, int col);
	int getSize();
};
#endif