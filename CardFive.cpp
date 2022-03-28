#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) :Card(pos)
{
	cardNumber = 5;
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	int y = pPlayer->getjustRolledDiceNum();
	pPlayer->Move(pGrid, y);

	//Ladder* Ladder = (pPlayer->GetPointerOnCell())->HasLadder();
	//if (Ladder != NULL)
	//{
	//	pPlayer->Move(pGrid, pPlayer->getjustRolledDiceNum());
	//	return;
	//}

	//Snake* Snak = (pPlayer->GetPointerOnCell())->HasSnake();
	//if (Snak != NULL)
	//{
	//	pPlayer->Move(pGrid, pPlayer->getjustRolledDiceNum());
	//	return;
	//}

}

void CardFive::ReadCardParameters(Grid* pGrid)
{
	//Card::ReadCardParameters(pGrid);
}


CardFive::~CardFive(void)
{
}
