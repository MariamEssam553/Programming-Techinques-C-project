#include "CardEight.h"
#include "ApplicationManager.h"


CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
	cardNumber = 8;
}

void CardEight::ReadCardParameters(Grid* pGrid)
{

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	//we make function of rolling dice false 
	//so we prevent player from rolling dice
	//*******************************************//
	//(pManager->GetGrid()->GetCurrentPlayer())->Move(pManager->GetGrid(), diceNumber2);
	//pManager->GetGrid()->AdvanceCurrentPlayer();
	pPlayer->setjustRolledDiceNum(0);
	pPlayer->Move(pGrid, pPlayer->getjustRolledDiceNum());

	/*ApplicationManager* Pmanager;
	pGrid->PrintErrorMessage("you are denied from playing this turn. Click to continue ");
	Action* pAct;
	pAct = new RollDiceAction(Pmanager);
	pAct->Execute();
	delete pAct;
	pAct = NULL;*/
}

CardEight::~CardEight(void)
{
}