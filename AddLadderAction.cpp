#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	flag = 0;
}

AddLadderAction::~AddLadderAction()
{

}

void AddLadderAction::ReadActionParameters() 
{	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	if (startPos.IsValidCell() == false) //operator overloading in cellPosition ?
	{
		//ActionType Exit;
		pGrid->PrintErrorMessage("Invalid. Check ladder specification");
		flag = 1;
		return;
	}

	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	if (endPos.IsValidCell() == false) //operator overloading in cellPosition ?
	{
		//ActionType Exit;
		pGrid->PrintErrorMessage("Invalid. Check ladder specification");
		flag = 1;
		return;
	}

	if (endPos.GetCellNum() < startPos.GetCellNum())
	{
		pGrid->PrintErrorMessage("end cell cannot be smaller than start cell");
		flag = 1;
		return;
	}
	else if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("end cell and start cell are not in the same column");
		flag = 1;
		return;
	}
	else if (endPos.VCell() == 0)
	{
		pGrid->PrintErrorMessage("End cell cannot be a start of another ladder or snake");
		flag = 1;
		return;
	}
	/*GameObject* L = new Ladder(startPos, endPos);
	if (L->IsOverLapping(L))
	{
		pGrid->PrintErrorMessage("Two ladders cannot overlap");
		flag = 1;
		return;
	}*/
	pOut->ClearStatusBar();
}

void AddLadderAction::Execute() 
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (flag != 0)
	{
		pGrid->PrintErrorMessage("Operation Cancelled ");
		return;
	}
	else
	{
		Ladder* pLadder = new Ladder(startPos, endPos);
		bool added = pGrid->AddObjectToCell(pLadder);
		if (!added)
		{
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
	}
}