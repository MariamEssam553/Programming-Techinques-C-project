#pragma once
#include "Card.h"

class CardTeen :public Card
{
	double price;
	double fees;
	Player* Owner;
public:
	CardTeen(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardTeen();
};
