#pragma once
#include "Card.h"
#include "Snake.h"

class CardFour : public Card
{
public:
	CardFour(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardFour();
};