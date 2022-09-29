#include "ThreadPool.h"

void ThreadPool::start(std::int32_t index,const Data & first,const Data & second,ResultData & result)
{
	while (!isWorkStart.load())
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	//waiting for starting all threads
	while (index < result.getSize())
	{
		result.multLine(index, first, second);
		index += this->countOfThread;
	}
}

ThreadPool::ThreadPool(const Data & first,const Data & second, ResultData& result)
{
	countOfThread = 2;
	for (size_t i = 0; i < 2; ++i)
		workers.emplace_back(std::thread (&ThreadPool::start, this, i, std::ref(first), std::ref(second), std::ref(result)));
}
ThreadPool::ThreadPool(const std::int32_t threadCount, const Data & first,const Data & second, ResultData& result)
{
	countOfThread = threadCount < 1 ? 1 : threadCount;
	for (std::int32_t i = 0; i < countOfThread; ++i)
		workers.emplace_back(std::thread(&ThreadPool::start, this, i, std::ref(first), std::ref(second), std::ref(result)));
}
void ThreadPool::runThreads()
{
	isWorkStart.store(true);
}
void ThreadPool::waitEnd()
{
	//wait all threads
	for (auto & th : workers)
		th.join();
	isWorkStart.store(false);
}
std::int32_t ThreadPool::countOfThread = 0;