#include "Save.h"
#include <iostream>
#include <fstream>
#include <sstream>


void Save::execute(Table& table, const char* buffer)
{
	if (!table.isOpenTable()) {
		throw std::invalid_argument("Table is not open and other function is forbidden.");
	}
	std::ofstream file(buffer);
	writeTableToFile(file, table.getTable(), table.getRows());
	file.close();
	std::cout << "Successfully saved " << buffer << std::endl;
}

void Save::writeRow(std::ofstream& ofs, const std::vector<Cell*>& row, const unsigned columns)
{
	for (size_t j = 0; j < columns; j++) {
		if (row[j] != nullptr) {
			row[j]->saveInFile(ofs);
		}
		if (j != columns - 1) {
			ofs << ",";
		}
	}
}

void Save::writeTableToFile(std::ofstream& ofs, const std::vector<std::vector<Cell*>>& table, const unsigned rows)
{
	for (size_t i = 0; i < rows; i++) {
		writeRow(ofs, table[i], table[i].size());
		if (i != rows - 1) {
			ofs << "\n";
		}
	}
}
