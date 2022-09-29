#include "ResultData.h"

ResultData::ResultData(const std::int32_t size_) 
	: Data(size_)
{
}

void ResultData::multLine(const std::int32_t lineNumber, const Data& first, const Data& second)
{
	if (first.getSize() != second.getSize()|| first.getSize() != this->getSize())
	{
		std::cout << "incorrect matrix size\n";
		throw std::runtime_error("incorrect matrix size");
	}
	for (size_t j = 0; j < this->size; ++j)
		for (size_t i = 0; i < this->size; ++i)
			this->matrix.at(lineNumber * this->size + j) += first.getCell(lineNumber, i) * second.getCell(i, j);
}

void ResultData::saveResult(const std::string& path) const
{
	std::ofstream out;
	out.open(path);
	try
	{
		for (size_t i = 0; i < this->size * this->size; ++i)
		{
			if (i % this->size == 0 && i != 0)
				out << std::endl;
			out << matrix.at(i) << " ";
		}
		out.close();
	}
	catch (const std::ifstream::failure& ex)
	{
		std::cout << "Exception opening/writing to file";
		out.close();
	}
}
