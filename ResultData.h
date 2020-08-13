#ifndef _RESULT_DATA_H_
#define _RESULT_DATA_H_
#include "Data.h"
#include <fstream>
class ResultData : public Data
{
public:
	ResultData(int size_);
	void multLine(int lineNumber, Data& first, Data& second);
	void saveResult(std::string patch);
};
#endif