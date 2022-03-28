#include "PasteCardAction.h"

#include "PasteCardAction.h"
#include "Card.h"
#include "Input.h"
#include "Output.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

PasteCardAction :: ~PasteCardAction()
{

}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the Destination Cell:");
	CardPosition = pIn->GetCellClicked();
	Cell c(CardPosition); //c is from cell position
	c.SetGameObject(pGrid->GetCurrentCard(CardPosition));

	/*if (c.HasCard() == false)
	{
		PastedCard = pGrid->GetCurrentCard(CardPosition)->GetCardNumber();
	}*/

	if (c.HasCard() != NULL)
	{
		PastedCard = 0;
		return;
	}
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (PastedCard == 0)
	{
		pGrid->PrintErrorMessage("Operation Cancelled");
		return;
	}
	Card* pCard = new Card(CardPosition);
	pCard = pGrid->GetClipboard();
	pOut->DrawCell(CardPosition, pCard->GetCardNumber());
	pGrid->PrintErrorMessage("Done");
}