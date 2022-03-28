#pragma once
#include "Action.h"

class SwitchtoDesignMode :public Action
{

public:

	SwitchtoDesignMode(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~SwitchtoDesignMode();
};