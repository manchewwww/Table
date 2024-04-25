#pragma once
#include "Cell.h"
#include <fstream>

class DoubleCell : public Cell {
public:
	double getValue() const override;
	void saveInFile(std::ofstream& ofs) const override;
	void print() const override;
	unsigned getLenght() const override;


	DoubleCell() = default;
	DoubleCell(const double value);
private:

private:
	double value;
};