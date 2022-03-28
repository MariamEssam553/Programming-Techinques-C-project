#pragma once
#include "Card.h"

class CardTwelve :public Card
{
	double price;
	double fees;
	Player* Owner;
public:
	CardTwelve(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardTwelve();
};