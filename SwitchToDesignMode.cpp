#include "SwitchtoDesignMode.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

SwitchtoDesignMode::SwitchtoDesignMode(ApplicationManager* pApp) :Action(pApp) 
{

}

void SwitchtoDesignMode::ReadActionParameters()
{

}

void SwitchtoDesignMode::Execute() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->ClearStatusBar();
	pOut->CreateDesignModeToolBar();
}

SwitchtoDesignMode::~SwitchtoDesignMode()
{

}