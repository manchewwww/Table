#include "Close.h"

void Close::execute(Table& table, const char* buffer)
{
	if (!table.isOpenTable()) {
		throw std::invalid_argument("Table is not open and other function is forbidden.");
	}
	table.free();
	std::cout << "Table is closed successfully." << std::endl;
}
