#pragma once
#include "Card.h"

class CardNine :public Card
{
	int CellToMove;

public:
	CardNine(const CellPosition& pos);
	int GetCellToMove();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardNine();
};