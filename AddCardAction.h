#pragma once

#include "Action.h"
#include "Card.h"

class AddCardAction : public Action
{
	// [Action Parameters]
	int cardNumber;            // 1- the card number
	CellPosition cardPosition; // 2- cell position of the card
	
public:
	AddCardAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); 
	virtual void Execute(); 
	virtual ~AddCardAction(); 
};

