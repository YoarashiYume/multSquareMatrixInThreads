#include "ThreadPool.h"

void ThreadPool::start(int iter, Data& first, Data& second, ResultData& result)
{
	while (!isWorkStart)
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	//waiting for starting all threads
	while (iter < result.getSize())
	{
		result.multLine(iter, first, second);
		iter += this->countOfThread;
	}
}

ThreadPool::ThreadPool(Data& first, Data& second, ResultData& result)
{
	countOfThread = 2;
	for (size_t i = 0; i < 2; ++i)
		workers.push_back(std::thread (&ThreadPool::start, this, i, std::ref(first), std::ref(second), std::ref(result)));
}
ThreadPool::ThreadPool(const int threadCount, Data& first, Data& second, ResultData& result)
{
	countOfThread = threadCount < 1 ? 1 : threadCount;
	for (int i = 0; i < countOfThread; ++i)
		workers.push_back(std::thread(&ThreadPool::start, this, i, std::ref(first), std::ref(second), std::ref(result)));
}
void ThreadPool::runningThreads()
{
	isWorkStart = true;
}
void ThreadPool::waitingEnd()
{
	for (auto & th : workers)
		th.join();
	//wait all threads
	isWorkStart = false;
}
int ThreadPool::countOfThread = 0;