#include "DeleteGameObject.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

DeleteGameObject::DeleteGameObject(ApplicationManager* pAM): Action(pAM)
{

}

void DeleteGameObject::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Deleting Game Object,Click on the desired cell...");
	cellposition = pIn->GetCellClicked();
}

void DeleteGameObject::Execute()
{
	int x, y;
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveObjectFromCell(cellposition);
	pGrid->GetOutput()->PrintMessage("Object Deleted. Click to continue");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();
}

DeleteGameObject::~DeleteGameObject(void)
{

}