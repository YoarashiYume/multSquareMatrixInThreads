#include <iostream>
#include <string>

#include "Data.h"
#include "ResultData.h"
#include "ThreadPool.h"

/**

\brief Main function
\throw std::invalid_argument on std::stoi failure
\return 0 for success and 1 for failure

The function checks the number of arguments and starts the multiplication

*/
std::int32_t main(std::int32_t argc, char* argv[])
{
	if (argc < 5) 
	{
		std::cout << "usage: <prog-name> <thread-amount> <file1.txt> <file2.txt>  <output.txt>\n";
		return 1;
	}
	//Prepare data
	std::int32_t threadAmount = std::stoi(argv[1]);
	std::string firstPath = argv[2];
	std::string secondPath = argv[3];
	std::string resultPath = argv[4];
	
	//Matrix and ThreadPool initialization
	Data a{firstPath};
	Data b{secondPath};
	ResultData result{a.getSize()};
	
	ThreadPool threadP{threadAmount,a, b, result};
	
	//Start of calculations
	threadP.runThreads();
	threadP.waitEnd();
	result.saveResult(resultPath);
	
	return 0;
}