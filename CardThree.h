#pragma once
#include "Card.h"
#include "Ladder.h"

class CardThree : public Card
{
public:
	CardThree(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardThree();
};