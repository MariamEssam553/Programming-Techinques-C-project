#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}

CardFour::~CardFour(void)
{

}

void CardFour::ReadCardParameters(Grid* pGrid)
{
	//Card::ReadCardParameters(pGrid);
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Snake* Snake;
	Snake= pGrid->GetNextSnake(position);
	if (Snake != NULL)
	{
		Snake->Apply(pGrid, pPlayer);
	}
	else
		return;
}