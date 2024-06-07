#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Cell.h"

static double convertStringToNumber(const std::string& value)
{
	return std::stod(value);

}
static unsigned getDotsCount(const std::string& other) {
	int count = 0;
	int i = 0;
	if (other[0] == '-') {
		i = 1;
	}
	for (i; i < other.size(); i++) {
		if (other[i] == '.') {
			count++;
		}
		else if (other[i] < '0' || other[i] > '9') {
			return 2;
		}
	}
	return count;
}
static bool isValidString(const std::string& other) {
	if (other[0] != '"' || other[other.size() - 1] != '"') {
		return false;
	}
	for (size_t i = 1; i < other.size() - 1; i++) {
		if (other[i] == '\"') {
			continue;
		}
		else if (other[i] == '"') {
			return false;
		}
	}
	return true;
}
static bool isValidFormula(const std::string& other) {
	int counter = 0;
	for (size_t i = 0; i < other.size(); i++) {
		if (other[i] == '=') {
			counter++;
		}
	} 
	return !(counter - 1);
}
template<typename T>
static unsigned getCharCountFromFile(T& ifs, char ch) {
	if (ifs.fail()) {
		throw std::invalid_argument("File is failed.");
	}
	size_t currentPosition = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	unsigned int count = 0;
	while (true) {
		char current = ifs.get();
		if (ifs.eof()) {
			break;
		}
		if (current == ch) {
			count++;
		}
	}
	ifs.clear();
	ifs.seekg(currentPosition);
	return count;
}


template<typename T>
static unsigned getColumnsCount(T& ifs) {
	if (ifs.fail()) {
		throw std::invalid_argument("File is failed.");
	}
	return getCharCountFromFile(ifs, ',');
}
template<typename T>
static unsigned getRowsCount(T& ifs) {
	if (ifs.fail()) {
		throw std::invalid_argument("File is failed.");
	}
	return getCharCountFromFile(ifs, '\n');
}
static unsigned getMaxColumns(const std::vector<std::vector<Cell*>>& table, const unsigned rows) {
	unsigned max = 0;
	for (size_t i = 0; i < rows; i++) {
		if (max < table[i].size()) {
			max = table[i].size();
		}
	}
	return max;
}