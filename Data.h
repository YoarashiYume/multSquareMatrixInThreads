#ifndef _DATA_H_
#define _DATA_H_

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>


/**
\brief Class for storing square matrices
Stores and provides access to matrices data
*/

class Data
{
protected:
	std::vector<std::int32_t> matrix;	///< matrix data
	std::int32_t size;	///< Size of one dimension of the stored matrix
	
	
	/**
	\brief Constructor
	\param size_ Size of one dimension of the matrix
	*/
	Data(const std::int32_t size_);
public:
	/**
	\brief Constructor
	\param path to the matrix file
	*/
	Data(const std::string& path);
	
	Data() = delete;
	
	/**
	\brief Matrix output method
	*/
	void showMatrix() const;
	
	/**
	\brief Method returning matrix element
	\param row element row index
	\param col element column index
	\return element on [row, col]
	*/
	std::int32_t getCell(const std::int32_t row, const std::int32_t col) const;
	
	/**
	\brief Method returning size of one dimension of the matrix
	\return Size of one dimension of the matrix
	*/
	std::int32_t getSize() const;
};

#endif