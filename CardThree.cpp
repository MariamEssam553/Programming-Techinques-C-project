#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3;
}

CardThree::~CardThree(void)
{

}

void CardThree::ReadCardParameters(Grid* pGrid)
{
	//Card::ReadCardParameters(pGrid);
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Ladder* Lad = pGrid->GetNextLadder(position);
	if (Lad != NULL)
	{
		Lad->Apply(pGrid, pPlayer);
	}
	else
		return;
}