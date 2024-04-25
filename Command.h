#pragma once
#include "Table.h"
#include "SomeFunc.hpp"
#include "CellFactory.hpp"

class Command {
public:
	virtual void execute(Table& table, const char* buffer) = 0;
private:

};