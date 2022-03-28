#pragma once
#include "Action.h"

class CopyCardAction :public Action
{
	CellPosition cardPosition; // 2- cell position of the card
	int CopiedCard;

public:
	CopyCardAction(ApplicationManager* pApp); 
	virtual void ReadActionParameters();
	virtual void Execute(); 
	virtual ~CopyCardAction(); 
};