#pragma once
#include "Cell.h"
#include <string>

class StringCell : public Cell {
public:
	double getValue() const override;
	void saveInFile(std::ofstream& ofs) const override;
	void print() const override;
	unsigned getLenght() const override;


	StringCell() = default;
	StringCell(const char* value);
	StringCell(const std::string& value);
private:
	double convertStringToNumber() const;
private:
	std::string value;
};
