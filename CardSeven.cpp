#include "CardSeven.h"


CardSeven::CardSeven(const CellPosition& pos) :Card(pos)
{
	cardNumber = 7;
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	//pGrid->setCurrentPlayerNumber((pGrid->GetCurrentPlayer) - 1);
	//pGrid->;
	//pPlayer->
	//ApplicationManager* ap;

	ApplicationManager* Pmanager;
	pGrid->PrintErrorMessage("you won another RollDice. Click to continue ");
	Action* pAct;
	pAct = new RollDiceAction(Pmanager);
	pAct->Execute();
	delete pAct;
	pAct = NULL;
}

CardSeven::~CardSeven()
{

}
