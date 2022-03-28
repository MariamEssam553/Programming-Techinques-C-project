#include "NewGame.h"
#include "Player.h"
#include "Grid.h"
#include "Action.h"

NewGame::NewGame(ApplicationManager* pAM) : Action(pAM)
{

}

void NewGame::ReadActionParameters()
{
	
}

void NewGame::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	if (pGrid->GetEndGame())
	{
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			Player* pPlayer = pGrid->GetCurrentPlayer();

			CellPosition Cell(1);
			pGrid->UpdatePlayerCell(pPlayer, Cell);

			pPlayer->setTurnCount(0);
			pPlayer->SetWallet(100);

			pGrid->AdvanceCurrentPlayer();
		}
		//pGrid->setCurrentPlayerNumber(0);
	}
}

NewGame::~NewGame()
{

}