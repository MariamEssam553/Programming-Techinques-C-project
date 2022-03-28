#include "CardSix.h"


CardSix::CardSix(const CellPosition& pos) :Card(pos)
{
	cardNumber = 6;
}

void CardSix::ReadCardParameters(Grid* pGrid)
{

}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	int oldcellnum;
	oldcellnum = CellPosition::GetCellNumFromPosition((pPlayer->GetCell())->GetCellPosition());
	int newcellnum = oldcellnum - pPlayer->getjustRolledDiceNum();
	CellPosition pos = CellPosition::GetCellPositionFromNum(newcellnum);
	pGrid->UpdatePlayerCell(pPlayer, pos);
}

CardSix::~CardSix()
{

}