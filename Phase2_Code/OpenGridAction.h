#pragma once
#include "Action.h"
class OpenGridAction : public Action
{
	string fileName;
public:
	OpenGridAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~OpenGridAction();
};

