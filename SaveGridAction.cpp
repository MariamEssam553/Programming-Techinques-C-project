#include "SaveGridAction.h"
#include <fstream>


SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp) 
{

}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter File Name: ");
	filename = pIn->GetString(pOut);
}

void SaveGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();

	ofstream sfile(filename, ios::out);
	sfile.close();
	sfile.open(filename, ios::app);
	if (sfile.is_open())
	{
		pGrid->SaveAll(sfile, 1);
		pGrid->SaveAll(sfile, 2);
		pGrid->SaveAll(sfile, 3);
		sfile.close();
	}
	pOut->ClearStatusBar();
}

SaveGridAction::~SaveGridAction() 
{

}