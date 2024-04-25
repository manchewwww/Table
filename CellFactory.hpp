#pragma once
#include <sstream>
#include "DoubleCell.h"
#include "FormulaCell.h"
#include "IntCell.h"
#include "StringCell.h"


static Cell* cellFactory(const Table& t, const std::string& value) {
	int size = getDotsCount(value);
	if (value == "" || value == "\n") {
		return nullptr;
	}
	else if (isValidString(value)) {
		return new StringCell(value);
	}
	else if (value[0] == '=') {
		return new FormulaCell(value, &t);
	}
	else if (size == 0) {
		return new IntCell(convertStringToNumber(value));
	}
	else if (size == 1) {
		return new DoubleCell(convertStringToNumber(value));
	}
	else {
		throw std::invalid_argument("This is not correct type of cell.");
	}
}
