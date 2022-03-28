#include "Card.h"
#include <fstream>

// ========= Setters and Getters Functions =========

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}
void Card::SetCardNumber(int cnum)
{
	cardNumber = (cnum > 0 && cnum < 15) ? cnum : 1; 
}
int Card::GetCardNumber()
{
	return cardNumber;
}

// ========= Virtual Functions =========

void Card::Draw(Output* pOut) const
{
	pOut->DrawCell(position, cardNumber);
}

void Card::ReadCardParameters(Grid * pGrid)
{
	int CardNb;
	pGrid->PrintErrorMessage("Enter Card number:");
	CardNb = (pGrid->GetInput())->GetInteger(pGrid->GetOutput());
	if (CardNb >= 1 && CardNb <= 14)
	{
		cardNumber = CardNb;
	}
	else
	{
		pGrid->PrintErrorMessage("Invalid card number. Click to discard.");
		return;
	}
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& sfile, int i)
{
	if (i == 3)
	{
		sfile << this->GetCardNumber() << endl;
	}
	else
		return;
}

Card::~Card()
{

}
