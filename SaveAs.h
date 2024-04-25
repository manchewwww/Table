#pragma once
#include "Save.h"

class SaveAs : public Command {
public:
	void execute(Table& table, const char* buffer) override;
};