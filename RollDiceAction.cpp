#include "RollDiceAction.h"
#include "Grid.h"
#include "Player.h"
#include "CardEight.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{

}

void RollDiceAction::ReadActionParameters()
{
	
}

void RollDiceAction::Execute()
{
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pManager->GetGrid()->GetEndGame() == true)
	{
		
	}
	else
	{
		CardEight* Card8 = dynamic_cast<CardEight*>(pManager->GetGrid()->GetCurrentPlayer()->GetCell()->HasCard());
		if (Card8 != NULL)
		{
			int diceNumber2 = 0;
			(pManager->GetGrid()->GetCurrentPlayer())->Move(pManager->GetGrid(), diceNumber2);
			pManager->GetGrid()->AdvanceCurrentPlayer();
			return;
		}

		srand((int)time(NULL)); 
		int diceNumber = 1 + rand() % 6; 
		(pManager->GetGrid()->GetCurrentPlayer())->Move(pManager->GetGrid(), diceNumber);
		pManager->GetGrid()->AdvanceCurrentPlayer();
	}
}

RollDiceAction::~RollDiceAction()
{

}
