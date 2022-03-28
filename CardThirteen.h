#pragma once
#include "Card.h"

class CardThirteen :public Card
{
	double price;
	double fees;
	Player* Owner;
public:
	CardThirteen(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardThirteen();
};