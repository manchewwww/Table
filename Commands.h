#pragma once
#include "CommandFactory.hpp"
#include "Command.h"


class Commands {
public:
	Commands();
	void run();
private:
	Command* command;
};

