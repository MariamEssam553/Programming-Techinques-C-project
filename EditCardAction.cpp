#include "EditCardAction.h"

EditCardAction::EditCardAction(ApplicationManager* pApp) :Action(pApp)
{

}

void EditCardAction::ReadActionParameters()
{

}

void EditCardAction::Execute()
{
	(pManager->GetGrid())->PrintErrorMessage("Click on the source to edit");
	CellPosition pos;
	pos = (pManager->GetGrid())->GetInput()->GetCellClicked();
	Cell cell(pos);
	//Card* CheckCard = cell.HasCard();

	//want to send the card in this cell to SetGameObject how to do it
	cell.SetGameObject((pManager->GetGrid())->GetCurrentCard(pos));
	//if (cell.SetGameObject(CheckCard) == false);
	if (cell.HasCard() != NULL)
	{
		//check card take parameters
		Card* CheckCard = cell.HasCard();
		int number = CheckCard->GetCardNumber();
		switch (number)
		{
		case 1:
			CheckCard->ReadCardParameters(pManager->GetGrid());
			break;
		case 2:
			CheckCard->ReadCardParameters(pManager->GetGrid());
			break;
		case 9:
			CheckCard->ReadCardParameters(pManager->GetGrid());
			break;
		case 10:
			CheckCard->ReadCardParameters(pManager->GetGrid());
			break;
		case 11:
			CheckCard->ReadCardParameters(pManager->GetGrid());
			break;
		case 12:
			CheckCard->ReadCardParameters(pManager->GetGrid());
			break;
		case 13:
			CheckCard->ReadCardParameters(pManager->GetGrid());
			break;
		case 14:
			CheckCard->ReadCardParameters(pManager->GetGrid());
			break;

		default:
			(pManager->GetGrid())->PrintErrorMessage("Operation Cancelled. Click to continue");
			return;
		}
	}
	else
	{
		(pManager->GetGrid())->PrintErrorMessage("Operation Cancelled. Click to continue");
		return;
	}
}

EditCardAction::~EditCardAction()
{

}