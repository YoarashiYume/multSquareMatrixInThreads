#include "Data.h"

Data::Data(std::string patch)
{
	SIZE = 0;
	std::fstream in;
	in.open(patch);
	try
	{
		while (!in.eof())
		{
			int value;
			in >> value;
			matrix.push_back(value);
		}
		if (sqrt(matrix.size()) != (int)sqrt(matrix.size()))
		{
			matrix.clear();
			std::cout << "incorrect matrix size\n";
			std::exit(1);
		}
		else
			SIZE = sqrt(matrix.size());
		in.close();
	}
	catch (const std::ifstream::failure& ex)
	{
		std::cout << "Exception opening/readin file";
		in.close();
	}
}

Data::Data(int size_)
{
	SIZE = size_;
	matrix = std::vector<int>(SIZE * SIZE);
}

void Data::showMatrix()
{
	
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		if (i % SIZE == 0)
			std::cout << std::endl;
		std::cout << matrix[i] << " ";
	}
	std::cout << std::endl;
}

int Data::getCell(int row, int col)
{
	return matrix[row, SIZE+col];
}

int Data::getSize()
{
	return SIZE;
}
