#pragma once
#include "Command.h"

class Print : public Command {
public:
	void execute(Table& table, const char* buffer) override;
private:
	unsigned getMaxLenghtOnCol(const std::vector<std::vector<Cell*>>& vector, const unsigned rows, const unsigned col) const;
	void printSpase(const unsigned size) const;
	void printRow(const std::vector<std::vector<Cell*>>& vector, const unsigned* lenghtsOfCell, const unsigned maxCol, const unsigned row) const;
	void printTable(const std::vector<std::vector<Cell*>>& vector) const;
};
