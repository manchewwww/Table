#pragma once
#include "Command.h"

class Save : public Command {
public:
	void execute(Table& table, const char* buffer) override;
private:
	void writeRow(std::ofstream& ofs, const std::vector<Cell*>& row, const unsigned columns);
	void writeTableToFile(std::ofstream& ofs, const std::vector<std::vector<Cell*>>& table, const unsigned rows);
};