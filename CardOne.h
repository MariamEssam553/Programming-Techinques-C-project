#pragma once

#include "Card.h"

class CardOne :	public Card
{
	int walletAmount; 

public:

	CardOne(const CellPosition & pos); 
	int CardOne::getwalletAmount();
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	virtual ~CardOne(); 
};

