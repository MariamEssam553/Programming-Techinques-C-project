#include "InputDiceValue.h"
#include "Grid.h"
#include "CardEight.h"

#include "Input.h"
#include "Output.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) :Action(pApp) 
{

}
InputDiceValue::~InputDiceValue() 
{

}

void InputDiceValue::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please Enter Dice Value from 1 to 6: ");
	DiceValue = pIn->GetInteger(pOut);
	if (DiceValue < 0 || DiceValue > 6)
	{
		DiceValue = 0;
		return;
	}
	pOut->ClearStatusBar();
}

void InputDiceValue::Execute() 
{
	ReadActionParameters();
	if (DiceValue == 0)
	{
		pManager->GetGrid()->PrintErrorMessage("Invalid dice value, Operation Cancelled. Click to continue ");
		return;
	}

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
		else
		{
			(pManager->GetGrid()->GetCurrentPlayer())->Move(pManager->GetGrid(), DiceValue);
			pManager->GetGrid()->AdvanceCurrentPlayer();
			return;
		}
	}
}
