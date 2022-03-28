#pragma once
#include "Card.h"

class CardForteen :public Card
{
	double price;
	double fees;
	Player* Owner;
public:
	CardForteen(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardForteen();
};