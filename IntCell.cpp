#include "IntCell.h"
#include <iostream>
#include <fstream>
#include <sstream>

double IntCell::getValue() const
{
    return value;
}

void IntCell::saveInFile(std::ofstream& ofs) const
{
    ofs << value;
}

void IntCell::print() const
{
    std::cout << value;
}

unsigned IntCell::getLenght() const
{
    std::stringstream ss;
    ss << value;
    std::string numberString = ss.str();
    int length = numberString.length();
    return length;
}

IntCell::IntCell(const int value)
{
    this->value = value;
}
