#include "Grid.h"

#include <fstream>

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"
#include "Snake.h"
//#include "CardOne.h"
//#include "CardTwo.h"
//#include "CardTeen.h"
//#include "CardNine.h"

//loop on grid count number of occurence of a card a card
//update interface el note ya3ny eh
//Get next ladder bt3ml eh w leeh mafesh snake
//Remove oject from cell it is needed??
//add object: any more needed validations
//card class in read parameters using pOut or pGrid 
//declaration of x &y of getpointclicked() where
//check card questions 

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}
	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}
	currPlayerNumber = 0; 
	Clipboard = NULL;
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}
void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}
void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);
	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	
	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}
Output * Grid::GetOutput() const
{
	return pOut;
}
void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}
Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}
void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}
bool Grid::GetEndGame() const
{
	return endGame;
}
void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}
bool Grid::CheckGameObjectLoopOnGrid(Card* GObj)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			Card* cardd = CellList[i][j]->HasCard();
			if (cardd != NULL)
			{
				if (cardd->GetCardNumber() == GObj->GetCardNumber())
				return true;
			}
		}
	}
	return false;
}
/*bool Grid::CheckOnStations(Card* card)
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Card** GO = PlayerList[i]->GetCardArray();
		int Y = PlayerList[i]->GetNumStations();
		for (int i = 0;i < Y;i++)
		{
			if (GO[i] == card)
			{
				return true;
			}
		}
	}
	return false;
}*/


// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}
Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if (CellList[i][j]->HasLadder() != NULL)
			{
				return CellList[i][j]->HasLadder();
			}
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake* Grid::GetNextSnake(const CellPosition& position)
{
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if (CellList[i][j]->HasSnake() != NULL)
			{
				return CellList[i][j]->HasSnake();
			}
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
Card* Grid::GetCurrentCard(const CellPosition& position)
{
	if (CellList[position.VCell()][position.HCell()]->HasCard() != NULL)
	{
		return CellList[position.VCell()][position.HCell()]->HasCard();
	}
	else
		return NULL;
}
bool Grid::IsOverLapping(GameObject* newObj)const
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			newObj->GameObject::IsOverLapping(CellList[i][j]->GetGameObject());
			return true;
		}
	}
}
// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}
		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}
		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::SaveAll(ofstream& sfile, int type)
{
	if (type == 1) {
		int lads = 0;
		for (int i = 0; i < NumVerticalCells - 1; i++)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				if (CellList[i][j]->HasLadder())
					lads++;
			}
		}
		sfile << lads << endl;
		for (int i = 0; i < NumVerticalCells - 1; i++)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				if (CellList[i][j]->HasLadder())
					for (int i = 0; i < lads; i++)
						CellList[i][j]->HasLadder()->Save(sfile, 1);
			}
		}
	}

	if (type == 2) {
		int snakes = 0;
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				if (CellList[i][j]->HasSnake())
					snakes++;
			}
		}
		sfile << snakes << endl;
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				if (CellList[i][j]->HasSnake())
					for (int i = 0; i < snakes; i++)
						CellList[i][j]->HasSnake()->Save(sfile, 2);
			}
		}
	}


	if (type == 3) {
		int cards = 0;
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				if (CellList[i][j]->HasCard())
					cards++;
			}
		}
	}
}
//		sfile << cards << endl;
//		for (int i = NumVerticalCells - 1; i >= 0; i--)
//		{
//			for (int j = 0; j < NumHorizontalCells; j++)
//			{
//				if (CellList[i][j]->HasLadder())
//					for (int i = 0; i < cards; i++)
//						CellList[i][j]->HasCards()->Save(sfile, 3);
//
//				bool check1 = true;
//				bool check2 = true;
//				bool check3 = true;
//				bool check4 = true;
//				bool check5 = true;
//				switch (cards)
//				{
//				case 1:
//					sfile << CardOne::getwalletAmount() << endl;
//					break;
//				case 2:
//					sfile << CardTwo::getwalletAmount() << endl;
//					break;
//				case 9:
//					sfile << CardNine::GetCellToMove() << endl;
//					break;
//				case 10:
//					if (check1 == true) {
//						sfile << CardTeen::getPrice() << " " << endl;
//					}
//				case 11:
//					if (check2 == true) {
//						sfile << CardEleven::getPrice() << " " << CardEleven::getFees() << endl;
//						check2 = false;
//					}
//					if (check3 == true) {
//						sfile << CardTwelve::getPrice() << " " << CardTwelve::getFees() << endl;
//						check3 = false;
//					}
//					if (check4 == true) {
//						sfile << CardThirteen::getPrice() << " " << CardThirteen::getFees() << endl;
//						check4 = false;
//					}
//					if (check5 == true) {
//						sfile << Cardfourteen::getPrice() << " " << CardFourteen::getFees() << endl;
//						check5 = false;
//					}
//				default:
//					outputfile << endl;
//					}
//				}
//			}
//		}
//	}
//}


Grid::~Grid()
{
	delete pIn;
	delete pOut;
	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}
	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}