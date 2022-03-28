#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	//Card::ReadCardParameters(pGrid);
	//pGrid->GetInput();
	//pGrid->GetOutput();
	pGrid->PrintErrorMessage("New CardOne : Enter its wallet amount ...");
	int wallet = (pGrid->GetInput())->GetInteger(pGrid->GetOutput());
	walletAmount = wallet;
	(pGrid->GetOutput())->ClearStatusBar();
}

int CardOne::getwalletAmount()
{
	return walletAmount;
}

void Save(ofstream& sfile, int i)
{

}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);
}
