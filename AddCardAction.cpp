#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"

#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTeen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardForteen.h"


AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	
}

AddCardAction::~AddCardAction()
{

}

void AddCardAction::ReadActionParameters() 
{	
	int CardNb;
	(pManager->GetGrid())->PrintErrorMessage("Enter Card number:");
	CardNb = ((pManager->GetGrid())->GetInput())->GetInteger((pManager->GetGrid())->GetOutput());
	if (CardNb >= 1 && CardNb <= 14)
	{
		cardNumber = CardNb;
	}
	else
	{
		(pManager->GetGrid())->PrintErrorMessage("Invalid card number. Click to discard.");
		cardNumber = 0;
		return;
	}
	//Card::ReadCardParameters();
	
	(pManager->GetGrid())->PrintErrorMessage("Please click on card cell");
	cardPosition = ((pManager->GetGrid())->GetInput())->GetCellClicked();
	if (cardPosition.HCell() == -1 && cardPosition.VCell() == -1)
	{
		(pManager->GetGrid())->PrintErrorMessage("Invalid cell. Click to discart ");
		return;
	}
	((pManager->GetGrid())->GetOutput())->ClearStatusBar();
}

void AddCardAction::Execute() 
{
	ReadActionParameters();
	if (cardNumber == 0)
	{
		return;
	}
	else
	{
		Card* pCard = NULL; // will point to the card object type
		switch (cardNumber)
		{
		case 1:
			pCard = new CardOne(cardPosition);
			break;
		case 2:
			pCard = new CardTwo(cardPosition);
			break;
		case 3:
			pCard = new CardThree(cardPosition);
			break;
		case 4:
			pCard = new CardFour(cardPosition);
			break;
		case 5:
			pCard = new CardFive(cardPosition);
			break;
		case 6:
			pCard = new CardSix(cardPosition);
			break;
		case 7:
			pCard = new CardSeven(cardPosition);
			break;
		case 8:
			pCard = new CardEight(cardPosition);
			break;
		case 9:
			pCard = new CardNine(cardPosition);
			break;
		case 10:
			pCard = new CardTeen(cardPosition);
			break;
		case 11:
			pCard = new CardEleven(cardPosition);
			break;
		case 12:
			pCard = new CardTwelve(cardPosition);
			break;
		case 13:
			pCard = new CardThirteen(cardPosition);
			break;
		case 14:
			pCard = new CardForteen(cardPosition);
			break;
		}

		if (pCard)
		{
			bool CheckAdd;
			CheckAdd = (pManager->GetGrid())->AddObjectToCell(pCard);
			if (CheckAdd == false)
			{
				(pManager->GetGrid())->PrintErrorMessage("Cell already contain a GameObject. Click to discard");
				return;
			}

			pCard->SetCardNumber(cardNumber);
			((pManager->GetGrid())->GetOutput())->DrawCell(cardPosition, pCard->GetCardNumber());
			pCard->ReadCardParameters(pManager->GetGrid());
			(pManager->GetGrid())->PrintErrorMessage("done");

		}
	}
}
