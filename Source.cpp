#include <iostream>
#include <string>
#include "Data.h"
#include "ResultData.h"
#include "ThreadPool.h"

int main(int argc, char* argv[])
{
	if (argc < 5) {
		std::cout << "usage: <prog-name> <thread-amount> <file1.txt> <file2.txt>  <output.txt>\n";
		std::system("pause");
		return 1;
	}
	int threadAmount = std::stoi(argv[1]);
	std::string firstPach = argv[2];
	std::string secondPach = argv[3];
	std::string savePach = argv[4];
	/*reading matrix*/
	Data a(firstPach);
	Data b(secondPach);
	ResultData result(a.getSize());
	ThreadPool threadP(threadAmount,a, b, result);
	/*start and wait threads*/
	threadP.runningThreads();
	threadP.waitingEnd();
	result.saveResult(savePach);
	return 0;
}