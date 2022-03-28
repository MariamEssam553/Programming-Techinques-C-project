#pragma once
#include "Action.h"

class PasteCardAction :public Action
{
	CellPosition CardPosition;
	int CardNumber;
	int PastedCard;
public:
	PasteCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~PasteCardAction();
};