#include "SwitchToPlayMode.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) :Action(pApp) 
{

}

void SwitchToPlayMode::ReadActionParameters() 
{

}

void SwitchToPlayMode::Execute() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->CreatePlayModeToolBar();
	pOut->PrintMessage("Let's Play! Click on New Game.");
}

SwitchToPlayMode::~SwitchToPlayMode() 
{

}