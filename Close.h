#pragma once
#include <vector>
#include <cstring>
#include <iostream>
#include "Command.h"

class Close : public Command {
public:
	void execute(Table& table, const char* buffer) override;
};