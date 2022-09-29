#ifndef _RESULT_DATA_H_
#define _RESULT_DATA_H_

#include <stdexcept>

#include "Data.h"

/**
\brief Class for multiply matrices and store the result
Stores and provides access to matrices data
*/
class ResultData final : public Data
{
public:
	/**
	\brief Constructor
	\param size_ Size of one dimension of the result matrix
	*/
	ResultData(const std::int32_t size_);
	
	/**
	\brief Method calculates the row of the final matrix
	
	Calculates matrix multiplication using the formula
  \f[
		ResultData_{lineNumber,j}= \sum_{i = 1}^{Data::size}(A_{lineNumber, i}*B_{i, lineNumber}),\\
		where\: lineNumber = 1..ResultData\!::\!size,\: i = 1..ResultData\!::\!size
  \f]
	\param lineNumber index of the line being calculated
	\param first matrix A for calculation
	\param second matrix B for calculation
	\throw runtime_error on incompatible sizes 
	*/
	void multLine(const std::int32_t lineNumber, const Data& first, const Data& second);
	
	/**
	\brief Method saves the result of multiplication to a file
	\param path to the matrix file
	*/
	void saveResult(const std::string& path) const;
};
#endif