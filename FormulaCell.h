#pragma once
#include "Cell.h"
#include "Table.h"

class FormulaCell : public Cell {
public:
	double getValue() const override;
	void saveInFile(std::ofstream& ofs) const override;
	void print() const override;
	unsigned getLenght() const override;
	
	FormulaCell() = default;
	FormulaCell(const std::string& value, const Table* tableAdress);

private:
	double getNumber(unsigned startPosition,unsigned endPosition) const;

	bool isValidNumber(unsigned startPosition, unsigned endPosition) const;
	bool isValidCell(unsigned startPosition, unsigned endPosition) const;
	unsigned getRow(unsigned& index) const;
	unsigned getColumn(unsigned& start,const unsigned& end) const;
	unsigned takeOperator(char& op) const;
	double convertStringToNumber(const std::string& value) const;
private:
	const Table* tableAdress;
	std::string value;
};