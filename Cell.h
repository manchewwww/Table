#pragma once
#include <fstream>

class Cell {
public:
	virtual double getValue() const = 0;
	virtual void saveInFile(std::ofstream& ofs) const = 0;
	virtual void print() const = 0;
	virtual unsigned getLenght() const = 0;

	virtual ~Cell() = default;
private:

private:

};