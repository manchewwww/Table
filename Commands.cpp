#include "Commands.h"
#include <iostream>
#include <fstream>
#include <sstream>

Commands::Commands()
{
	command = nullptr;
}
void Commands::run()
{
	Table table;
	while (true) {
		char cmd[1024];
		char filePath[1024];
		std::cout << "Enter command: ";
		std::cin.getline(cmd, 1024);
		if (strcmp(cmd, "exit") == 0) {
			std::cout << "Exiting from program...";
			break;
		}
		try
		{
			command = commandFactory(cmd, filePath);
			command->execute(table, filePath);
			delete command;
			command = nullptr;
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
			if (command != nullptr) {
				delete command;
				command = nullptr;
			}
		}

	}
}
