#include "SaveAs.h"
#include <iostream>
#include <fstream>
#include <sstream>

void SaveAs::execute(Table& table, const char* buffer)
{
	char fileName[1024];
	if (!table.isOpenTable()) {
		throw std::invalid_argument("Table is not open and other function is forbidden.");
	}
	std::cout << "Enter file path: ";
	std::cin.getline(fileName, 1024);
	Save obj;
	obj.execute(table, fileName);
}
