#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"


CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the Source Cell:");
	CardPosition = pIn->GetCellClicked();
	Cell c(CardPosition); //c is from cell position
	c.SetGameObject(pGrid->GetCurrentCard(CardPosition));

	if (c.HasCard()) 
	{
		Card cp(CardPosition);
		CutCard = pGrid->GetCurrentCard(CardPosition)->GetCardNumber();
	}
	else
	{
		CutCard = 0;
		return;
	}
	pOut->ClearStatusBar();
}

void CutCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (CutCard == 0)
	{
		pGrid->PrintErrorMessage("Operation Cancelled");
		return;
	}
	pGrid->SetClipboard(pGrid->GetCurrentCard(CardPosition));
	pOut->DrawCell(CardPosition, -1);

}

CutCardAction :: ~CutCardAction()
{

}