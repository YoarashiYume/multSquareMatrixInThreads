#include "Data.h"

//Reads matrix and checks if it is square
Data::Data(const std::string& path)
{
	size = 0;
	std::fstream in;
	in.open(path);
	try
	{
		while (!in.eof())
		{
			std::int32_t value;
			in >> value;
			matrix.emplace_back(value);
		}
		if (std::sqrt(matrix.size()) != static_cast<std::int32_t>(std::sqrt(matrix.size())))
		{
			matrix.clear();
			std::cout << "incorrect matrix size\n";
			std::exit(1);
		}
		else
			size = std::sqrt(matrix.size());
		in.close();
	}
	catch (const std::ifstream::failure& ex)
	{
		std::cout << "Exception opening/reading to file";
		in.close();
	}
}

Data::Data(const std::int32_t size_)
	:size(size_)
{
	matrix = std::vector<std::int32_t>(size * size);
}

//Output matrix to console
void Data::showMatrix() const
{
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		if (i % size == 0)
			std::cout << std::endl;
		std::cout << matrix.at(i) << " ";
	}
	std::cout << std::endl;
}

std::int32_t Data::getCell(const std::int32_t row, const std::int32_t col) const
{
	return matrix.at(row * size + col);
}

std::int32_t Data::getSize() const
{
	return size;
}
