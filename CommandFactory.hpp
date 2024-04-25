#pragma once
#include "OpenFile.h"
#include "EditCell.h"
#include "SaveAs.h"
#include "Save.h"
#include "Print.h"
#include "Close.h"

static Command* commandFactory(const char* cmd, char* filePath) {
	if (strcmp(cmd, "open") == 0) {
		std::cout << "Enter file path: ";
		std::cin.getline(filePath, 1024);
		return new OpenFile();
	}
	else if (strcmp(cmd, "save") == 0) {
		return new Save();
	}
	else if (strcmp(cmd, "save as") == 0) {
		return new SaveAs();
	}
	else if (strcmp(cmd, "print") == 0) {
		return new Print();
	}
	else if (strcmp(cmd, "edit") == 0) {
		return new EditCell();
	}
	else if (strcmp(cmd, "close") == 0) {
		return new Close();
	}
	else {
		throw std::invalid_argument("Invalid command. ");
	}
}
