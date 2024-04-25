#include "StringCell.h"
#include <iostream>
#include <fstream>
#include <sstream>

double StringCell::getValue() const
{
    return convertStringToNumber();
}

void StringCell::saveInFile(std::ofstream& ofs) const
{
    ofs << value;
}

void StringCell::print() const
{
    for (size_t i = 1; i < value.size() - 1; i++) {
        std::cout << value[i];
    }
}

unsigned StringCell::getLenght() const
{
    return value.length() - 2;//size;
}

StringCell::StringCell(const char* value)
{
    this->value = value;
}

StringCell::StringCell(const std::string& value)
{
    this->value = value;
}

double StringCell::convertStringToNumber() const
{
    unsigned countOfPoints = 0;
    unsigned size = value.size();
    for (size_t i = 0; i < size; i++) {
        if (value[i] == '.') {
            countOfPoints++;
        }
        if (value[i] < '0' || value[i] > '9' || countOfPoints > 1) {
            return 0;
        }
    }
    return std::stod(value);
}
