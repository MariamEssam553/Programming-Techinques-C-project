#pragma once
#include "Action.h"
#include "Grid.h"
#include "Card.h"

class EditCardAction :public Action
{
public:
	EditCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~EditCardAction();
};

