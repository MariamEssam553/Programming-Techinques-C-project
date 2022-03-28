#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2; 
}

CardTwo::~CardTwo(void)
{

}

int CardTwo::getwalletAmount()
{
	return walletAmount;
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	//Card::ReadCardParameters(pGrid);
	pGrid->GetInput();
	pGrid->GetOutput();
	pGrid->PrintErrorMessage("New CardTwo : Enter its wallet amount ...");
	int wallet = (pGrid->GetInput())->GetInteger(pGrid->GetOutput());
	walletAmount = wallet;
	(pGrid->GetOutput())->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);
}