#include "CardNine.h"


CardNine::CardNine(const CellPosition& pos) :Card(pos)
{
	cardNumber = 9;
}

int CardNine::GetCellToMove()
{
	return CellToMove;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("Enter Cell to move to: ");
	int CellNum = (pGrid->GetInput())->GetInteger(pGrid->GetOutput());
	if (CellNum >= 0 && CellNum < 100)
	{
		CellToMove = CellNum;
	}
	(pGrid->GetOutput())->ClearStatusBar();
	//pGrid->UpdatePlayerCell(CellToMove);
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	CellPosition poss = CellPosition::GetCellPositionFromNum(CellToMove);
	pGrid->UpdatePlayerCell(pPlayer, poss);
}

CardNine::~CardNine()
{

}
