#include "FormulaCell.h"
#include <iostream>

double FormulaCell::getValue() const
{
	char op = '\0';
	unsigned index = takeOperator(op);
	double firstNumber = getNumber(1,index);
	double secondNumber = getNumber(index + 1, value.size());
	switch (op)
	{
	case '+': return (firstNumber + secondNumber);
	case '-': return (firstNumber - secondNumber);
	case '*': return (firstNumber * secondNumber);
	case '/': {
		if (secondNumber == 0) {
			throw std::invalid_argument("ERROR");
		}
		else {
			return firstNumber / secondNumber;
		}
	}
	case '<': return firstNumber < secondNumber ? 1 : 0;
	case '<=': return firstNumber <= secondNumber ? 1 : 0;
	case '>': return firstNumber > secondNumber ? 1 : 0;
	case '>=': return firstNumber >= secondNumber ? 1 : 0;
	case '==': return firstNumber == secondNumber ? 1 : 0;
	case '!=': return firstNumber != secondNumber ? 1 : 0;
	default:
		throw std::invalid_argument("Invalid operator.");
		break;
	}
}

void FormulaCell::saveInFile(std::ofstream& ofs) const
{
	ofs << value;
}

void FormulaCell::print() const
{
	try
	{
		std::cout << getValue();
	}
	catch (const std::invalid_argument& e)
	{
		throw std::invalid_argument("ERROR");
	}
}
unsigned FormulaCell::getLenght() const
{
	double number;
	try {
		number = getValue();
	}
	catch (const std::invalid_argument& e) {
		return 5;
	}
	std::stringstream ss;
	ss << number;
	std::string numberString = ss.str();
	int length = numberString.length();
	return length;
}
FormulaCell::FormulaCell(const std::string& value, const Table* tableAdress)
{
	this->value = value;
	this->tableAdress = tableAdress;
}

double FormulaCell::getNumber(unsigned startPosition, unsigned endPosition) const
{
	unsigned row = 0;
	unsigned column = 0;
	if (isValidNumber(startPosition, endPosition)) {
		std::string number;
		for (size_t i = startPosition; i < endPosition; i++) {
			number.push_back(value[i]);
		}
		return convertStringToNumber(number);
	}
	else if(isValidCell(startPosition,endPosition)) {
		startPosition++;
		row = getRow(startPosition);
		startPosition++;
		column = getColumn(startPosition, endPosition);
		return ((*tableAdress).getCell(row, column) != this) ? (*tableAdress).getCell(row, column)->getValue() : throw std::invalid_argument("This is same cell and formula is not completed.");
	}
	else {
		throw std::invalid_argument("Invalid type of argument.");
	}
}
bool FormulaCell::isValidNumber(unsigned startPosition, unsigned endPosition) const
{
	for (size_t i = startPosition; i < endPosition; i++) {
		if (value[i] == '.') {
			continue;
		}
		else if ((value[i] < '0' || value[i] > '9')) {
			return false;
		}
	}
	return true;
}
bool FormulaCell::isValidCell(unsigned startPosition, unsigned endPosition) const
{
	for (size_t i = startPosition; i < endPosition; i++) {
		if ((value[i] < '0' || value[i] > '9') && (value[i] != 'R' && value[i] != 'C' && value[i] != ' ')) {
			return false;
		}
	}
	return true;
}

unsigned FormulaCell::getRow(unsigned& index) const
{
	std::string numberOfRow;
	while (value[index] != 'C') {
		numberOfRow.push_back(value[index]);
		index++;
	}
	return convertStringToNumber(numberOfRow);
}
unsigned FormulaCell::getColumn(unsigned& start, const unsigned& end) const
{
	std::string numberOfColumn;
	for (size_t i = start; i < end; i++) {
		numberOfColumn.push_back(value[i]);
	}
	return convertStringToNumber(numberOfColumn);;
}
unsigned FormulaCell::takeOperator(char& op) const
{
	int index = 0;
	for (size_t i = 2; i < value.size(); i++)
	{
		if (value[i] == '+' || value[i] == '-' || value[i] == '*' || value[i] == '/' || value[i] == '<' || value[i] == '<=' || value[i] == '>' || value[i] == '>=' || value[i] == '==' || value[i] == '!=') {
			op = value[i];
			index = i;
			break;
		}
	}
	return index;
}

double FormulaCell::convertStringToNumber(const std::string& value) const
{
	return std::stod(value);
}

