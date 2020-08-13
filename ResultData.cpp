#include "ResultData.h"

ResultData::ResultData(int size_) : Data(size_)
{
}

void ResultData::multLine(int lineNumber, Data& first, Data& second)
{
	if (first.getSize() != second.getSize()|| first.getSize() != this->getSize())
	{
		std::cout << "incorrect matrix size\n";
		std::exit(1);
	}
	for (size_t j = 0; j < SIZE; ++j)
	{
		for (size_t i = 0; i < SIZE; ++i)
		{
			//counting of one cell value
			this->matrix[lineNumber * SIZE + j] += first.getCell(lineNumber, i) * second.getCell(i, j);
		}
	}
}

void ResultData::saveResult(std::string patch)
{
	std::ofstream out;
	out.open(patch);
	try
	{
		for (size_t i = 0; i < SIZE * SIZE; ++i)
		{
			if (i % SIZE == 0 && i != 0)
				out << std::endl;
			out << matrix[i] << " ";
		}
		out.close();
	}
	catch (const std::ifstream::failure& ex)
	{
		std::cout << "Exception opening/readin file";
		out.close();
	}
}
