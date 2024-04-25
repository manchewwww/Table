#include "DoubleCell.h"
#include <iostream>
#include <fstream>
#include <sstream>

double DoubleCell::getValue() const
{
    return value;
}

void DoubleCell::saveInFile(std::ofstream& ofs) const
{
    ofs << value;
}

void DoubleCell::print() const
{
    std::cout << value;
}

unsigned DoubleCell::getLenght() const
{
    std::stringstream ss;
    ss << value;
    std::string numberString = ss.str();
    int length = numberString.length();
    return length;
}

DoubleCell::DoubleCell(const double value)
{
    this->value = value;
}
