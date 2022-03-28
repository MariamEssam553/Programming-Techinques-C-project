#include "CopyCardAction.h"
#include "Card.h"
#include "Input.h"
#include "Output.h"


CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp) 
{

}

CopyCardAction::~CopyCardAction() 
{

}

void CopyCardAction::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the Source Cell:");
	cardPosition = pIn->GetCellClicked();
	Cell c(cardPosition); 
	c.SetGameObject(pGrid->GetCurrentCard(cardPosition));

	if (c.HasCard()) 
	{
		CopiedCard = pGrid->GetCurrentCard(cardPosition)->GetCardNumber();
	}
	else
	{
		CopiedCard = 0;
		return;
	}

	pOut->ClearStatusBar();
}

void CopyCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (CopiedCard == 0)
	{
		pGrid->PrintErrorMessage("Operation Cancelled");
		return;
	}
	pGrid->SetClipboard(pGrid->GetCurrentCard(cardPosition));
}
