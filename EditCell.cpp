#include "EditCell.h"
#include <iostream>
#include <fstream>
#include <sstream>

void EditCell::execute(Table& table, const char* buffer)
{
	if (!table.isOpenTable()) {
		throw std::invalid_argument("Table is not open and other function is forbidden.");
	}
	unsigned row, column;
	std::cout << "Enter row: ";
	std::cin >> row;
	std::cout << "Enter column: ";
	std::cin >> column;
	std::cin.ignore();
	
	editCell(table, row, column);
}

void EditCell::editCell(Table& table, const unsigned rows, const unsigned columns)
{
	if (!isValidCell(table.getTable(), rows - 1, columns - 1)) {
		throw std::invalid_argument("No row or column with such a number.");
	}
	std::cout << "Enter new cell data: ";
	char buffer[1024];
	std::cin.getline(buffer, 1024);
	std::string cell(buffer);
	Cell* newCell = cellFactory(table, cell);
	if (newCell) {
		delete table.getTable()[rows - 1][columns - 1];
		table.getTable()[rows - 1][columns - 1] = newCell;
	}
}
bool EditCell::isValidCell(const std::vector<std::vector<Cell*>>& table, const unsigned rows, const unsigned columns)
{
	return rows <= table.size() && columns <= table[0].size();
}
