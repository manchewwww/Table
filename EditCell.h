#pragma once
#include "Command.h"

class EditCell : public Command {
public:
	void execute(Table& table, const char* buffer) override;
private:
	void editCell(Table& table, const unsigned rows, const unsigned columns);
	bool isValidCell(const std::vector<std::vector<Cell*>>& table, const unsigned rows, const unsigned columns);
};