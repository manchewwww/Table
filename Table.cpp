#include "Table.h"

Table::~Table()
{
	free();
}

void Table::free() {
	for (size_t i = 0; i < table.size(); i++) {
		for (size_t j = 0; j < table[i].size(); j++) {
			delete[] table[i][j];
			table[i][j] = nullptr;
		}
	}
	isOpen = false;
	table.clear();
}

unsigned Table::getRows() const
{
	return table.size();	
}

unsigned Table::getColumns() const
{
	return table[0].size();
}

bool Table::isOpenTable() const
{
	return isOpen;
}

void Table::setOpen()
{
	isOpen = true;
}

std::vector<std::vector<Cell*>>& Table::getTable()
{
	return table;
}

const Cell* Table::getCell(const unsigned row, const unsigned column) const
{
	if (table.size() < row - 1) {
		throw std::invalid_argument("Row is bigger than rows of table.");
	}
	if (table[row - 1].size() < column - 1) {
		throw std::invalid_argument("Columns are bigger than rows of table.");
	}
	return table[row - 1][column -1];
}
