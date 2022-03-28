#pragma once
#include "Card.h"

class CardEleven :public Card
{
	double price;
	double fees;
	Player* Owner;
public:
	CardEleven(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardEleven();
};