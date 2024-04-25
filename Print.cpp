#include "Print.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Print::execute(Table& table, const char* buffer)
{
	if (!table.isOpenTable()) {
		throw std::invalid_argument("Table is not open and other function is forbidden.");
	}
	printTable(table.getTable());
	std::cout << "Print is successfully" << std::endl;
}

unsigned Print::getMaxLenghtOnCol(const std::vector<std::vector<Cell*>>& vector, const unsigned rows, const unsigned col) const
{
	unsigned maxLenght = 0;
	for (size_t row = 0; row < rows; row++) {
		if (col < vector[row].size()) {
			if (vector[row][col] != nullptr) {
				unsigned size = vector[row][col]->getLenght();
				if (maxLenght < size) {
					maxLenght = size;
				}
			}
		}
	}
	return maxLenght;
}

void Print::printSpase(const unsigned size) const
{
	for (size_t i = 0; i < size; i++) {
		std::cout << " ";
	}
}

void Print::printRow(const std::vector<std::vector<Cell*>>& vector, const unsigned* lengthsOfCell, const unsigned maxCol, const unsigned row) const
{
	for (size_t j = 0; j < maxCol; j++) {
		if (vector[row][j] != nullptr) {
			try
			{
				vector[row][j]->print();
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what();
			}
			printSpase(lengthsOfCell[j] - vector[row][j]->getLenght());
		}
		else {
			printSpase(lengthsOfCell[j]);
		}
		std::cout << " | ";
	}
}

void Print::printTable(const std::vector<std::vector<Cell*>>& table) const
{
	unsigned rows = table.size();
	unsigned maxCol = getMaxColumns(table, rows);
	unsigned* lengthsOfCell = new unsigned[maxCol];
	for (size_t i = 0; i < maxCol; i++) {
		lengthsOfCell[i] = getMaxLenghtOnCol(table, rows, i);
	}
	for (size_t i = 0; i < rows; i++) {
		printRow(table, lengthsOfCell, maxCol, i);
		std::cout << std::endl;
	}
	delete[] lengthsOfCell;
}
