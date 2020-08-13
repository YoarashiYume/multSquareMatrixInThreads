#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_
#include <thread>
#include <vector>
#include <chrono>
#include <functional>
#include "ResultData.h"
#include "Data.h"
class ThreadPool
{
private:
	static int countOfThread;
	bool isWorkStart = false;
	std::vector<std::thread> workers; //vector of threads
	void start(int iter,Data & first,Data & second,ResultData & result);
public:
	ThreadPool(Data& first, Data& second, ResultData& result);
	ThreadPool(const int threadCount, Data& first, Data& second, ResultData& result);
	void runningThreads();
	void waitingEnd();
};
#endif // !_THREADPOOL_H_