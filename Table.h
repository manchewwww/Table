#pragma once
#include <sstream>
#include <fstream>
#include <vector>
#include "Cell.h"

class Table {
public:
	Table() = default;
	~Table();
	void free();
	unsigned getRows() const;
	unsigned getColumns() const;
	bool isOpenTable() const;
	void setOpen();
	std::vector<std::vector<Cell*>>& getTable();
	const Cell* getCell(const unsigned row, const unsigned column) const;
private:

private:
	bool isOpen = false;
	std::vector<std::vector<Cell*>> table;
};