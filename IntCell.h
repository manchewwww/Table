#pragma once
#include "Cell.h"
#include <fstream>

class IntCell : public Cell {
public:
	double getValue() const override;
	void saveInFile(std::ofstream& ofs) const override;
	void print() const override;
	unsigned getLenght() const override;


	IntCell() = default;
	IntCell(const int value);
private:

private:
	int value;
};