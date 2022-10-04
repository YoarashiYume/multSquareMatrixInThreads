#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#include <thread>
#include <vector>
#include <chrono>
#include <atomic>

#include "ResultData.h"

/**
\brief Simple ThreadPool class
Run ResultData::multLine in threads
*/
class ThreadPool final
{
private:
	static std::int32_t countOfThread;		///< number of running threads
	std::atomic_bool isWorkStart{false};	///< current state
	
	std::vector<std::thread> workers;		///< vector of threads
	
	/**
	\brief Method calculates the row of the final matrix
	
	Calculates matrix multiplication using the formula
  \f[
		ResultData_{lineNumber,j}= \sum_{i = 1}^{Data::size}(A_{lineNumber, i}*B_{i, lineNumber}),\\
		where\: lineNumber = 1..ResultData\!::\!size,\: i = 1..ResultData\!::\!size
  \f]
	\param index index of the line being calculated
	\param first,second input matrices
	\param result output matrices
	\throw runtime_error on incompatible sizes 
	*/
	void start(const std::int32_t index,const Data & first,const Data & second,ResultData & result) ;
public:
	ThreadPool() = delete;
	/**
	\brief Constructor
	\param first,second input matrices
	\param result output matrices
	*/
	ThreadPool(const Data & first,const Data & second, ResultData& result);
	
	/**
	\brief Constructor
	\param threadCount ThreadPool size
	\param first,second input matrices
	\param result output matrices
	*/
	ThreadPool(std::int32_t threadCount, const Data & first,const Data & second, ResultData& result);
	
	/**
	\brief Starts threads to execute
	*/
	void runThreads();
	
	/**
	\brief waiting for threads to stop
	*/
	void waitEnd();
};
#endif // !_THREADPOOL_H_
