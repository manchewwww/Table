#pragma once
#include <vector>
#include <cstring>
#include <iostream>
#include "Command.h"


class OpenFile : public Command {
public:
	void execute(Table& table, const char* buffer) override;
private:
	bool isValidFileData(std::ifstream& ifs, unsigned rows) const;
	void isValidRow(std::stringstream& ss) const;
	int isTwoCell(const std::string& value) const;

	void readCells(const Table& t, std::vector<Cell*>& row, std::stringstream& ss);
	void readRow(const Table& t, std::vector<Cell*>& row, std::ifstream& ifs);
	void makeTable(std::vector<std::vector<Cell*>>& table, const unsigned rows);
	void readTable(Table& t, std::ifstream& ifs, const unsigned rows);

	void removeWhiteSpases(std::string& value) const;

};