#include <iostream>
#include <fstream>
#include <sstream>
#include "OpenFile.h"



void OpenFile::readCells(const Table& t, std::vector<Cell*>& row, std::stringstream& ss)
{
	if (ss.fail()) {
		throw std::invalid_argument("String stream is failed.");
	}
	std::string value;
	unsigned columns = getColumnsCount(ss) + 1;
	for (size_t i = 0; i < columns; i++) {
		char cell[1024];
		if (i == columns - 1) {
			ss.getline(cell, 1024);
		}
		else {
			ss.getline(cell, 1024, ',');
		}
		value.append(cell);
		removeWhiteSpases(value);
		row.push_back(cellFactory(t, value));
		value.clear();
	}
}
void OpenFile::readRow(const Table& t, std::vector<Cell*>& row, std::ifstream& ifs)
{
	if (!ifs.is_open()) {
		throw std::invalid_argument("File is failed.");
	}
	char buffer[1024];
	ifs.getline(buffer, 1024);
	std::stringstream ss(buffer);

	readCells(t, row, ss);
}
void OpenFile::makeTable(std::vector<std::vector<Cell*>>& table, const unsigned rows)
{
	unsigned maxColumns = getMaxColumns(table, rows);
	for (size_t i = 0; i < rows; i++) {
		if (maxColumns != table[i].size()) {
			unsigned size = maxColumns - table[i].size();
			for (size_t j = 0; j < size; j++) {
				table[i].push_back(nullptr);
			}
		}
	}
}
void OpenFile::readTable(Table& t, std::ifstream& ifs, const unsigned rows)
{
	if (!ifs.is_open()) {
		throw std::invalid_argument("File is failed.");
	}
	for (size_t i = 0; i < rows; i++) {
		std::vector<Cell*> row;
		readRow(t, row, ifs);
		t.getTable().push_back(row);
	}
	makeTable(t.getTable(), rows);
}

void OpenFile::execute(Table& table, const char* buffer)
{
	std::ifstream file(buffer);
	if (!file.is_open()) {
		std::ofstream newFile(buffer);
		newFile.close();
		throw std::invalid_argument("File is not open.");
	}
	unsigned rows = getRowsCount(file) + 1;
	if (!isValidFileData(file, rows)) {
		return;
	}
	if (table.isOpenTable()) {
		throw std::invalid_argument("Table is open.");
	}
	readTable(table, file, rows);
	table.setOpen();
	file.close();
	std::cout << "Successfully opened " << buffer << std::endl;
}

bool OpenFile::isValidFileData(std::ifstream& ifs, unsigned rows) const
{
	if (!ifs.is_open()) {
		throw std::invalid_argument("File is failed.");
	}
	for (size_t i = 0; i < rows; i++) {
		char buffer[1024];
		ifs.getline(buffer, 1024);
		std::stringstream ss(buffer);
		try
		{
			isValidRow(ss);
		}
		catch (unsigned e)
		{
			std::cout << "Invalid type of cell on row " << (i + 1) << " and column " << e << std::endl;
			return false;
		}
		catch (char e)
		{
			std::cout << "Missing comma on row " << (i + 1) << " after symbol " << e << std::endl;
			return false;
		}
	}
	ifs.clear();
	ifs.seekg(0, std::ios::beg);
	return true;
}
void OpenFile::isValidRow(std::stringstream& ss) const
{
	Table t;
	unsigned columns = getColumnsCount(ss) + 1;
	std::string value;
	for (unsigned i = 0; i < columns; i++) {
		char cell[1024];
		if (i == columns - 1) {
			ss.getline(cell, 1024);
		}
		else {
			ss.getline(cell, 1024, ',');
		}
		value.append(cell);
		removeWhiteSpases(value);
		try
		{
			Cell* cell = cellFactory(t, value);
			delete cell;
		}
		catch (const std::invalid_argument& e)
		{
			int index = isTwoCell(value);
			if (index != -1) {
				throw value[index - 1];
			}
			else {
				throw (i + 1);
			}
		}
		value.clear();
	}
}
int OpenFile::isTwoCell(const std::string& value) const
{
	int size = value.size();
	for (size_t i = 0; i < size; i++) {
		if (value[i] == '"') {
			i++;
			while (value[i] != '"') {
				i++;
			}
		}
		else if(value[i] == ' ') {
			return i;
		}
	}
	return -1;
}

void OpenFile::removeWhiteSpases(std::string& value) const
{
	if (value != "" && value != "\n") {
		int size = 0;
		for (size_t i = 0; value[i] == ' '; i++) {
			size++;
		}
		if (size != 0) {
			value.erase(0, size);
		}
		if (value.size() >= 1) {
			for (size_t i = value.size() - 1; value[i] == ' '; i--) {
				value.pop_back();
			}
		}
	}
}

