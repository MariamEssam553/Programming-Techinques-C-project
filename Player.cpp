#include "Player.h"
#include "GameObject.h"
#include "CardEight.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	numOfStations = 0;
	
	// Make all the needed initialization or validations
}


// ====== Setters and Getters ======


void Player::SetCell(Cell * cell)
{
	pCell = cell;
}
Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}
int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

/*void Player::SetCardArray(Card* GOBJ)
{
	StationsOwned[numOfStations] = GOBJ;
	numOfStations++;
}
Card** Player::GetCardArray()
{
	return StationsOwned;
}
int Player::GetNumStations()
{
	return numOfStations;
}*/

int Player::getjustRolledDiceNum()
{
	return justRolledDiceNum;
}
int Player::getcout()
{
	return stepCount;
}
void Player::SetStepCount(int y)
{
	if (y >= 0 && y < 100)
		stepCount = y;
	else
		return;
}
void Player::setjustRolledDiceNum(int c)
{
	justRolledDiceNum = c;
}


// ====== Drawing Functions ======


void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{
	turnCount++;
	if (turnCount == 3)
	{
		justRolledDiceNum = diceNumber;
		wallet += 10 * justRolledDiceNum;
		turnCount = 0;
		return;
	}

	CardEight* card8 = dynamic_cast<CardEight*>(pCell->GetGameObject());
	if (card8 != NULL)
	{
		card8->Apply(pGrid, this);
		return;
	}

	justRolledDiceNum = diceNumber;
	stepCount += diceNumber;
	
	int newNb = CellPosition::GetCellNumFromPosition(pCell->GetCellPosition()) + diceNumber;
	CellPosition POS = CellPosition::GetCellPositionFromNum(newNb);
	//(pCell->GetCellPosition()).AddCellNum(diceNumber);
	//pGrid->UpdatePlayerCell(this, pCell->GetCellPosition());
	pGrid->UpdatePlayerCell(this, POS);

	pCell->GetGameObject();
	Ladder* Lad = dynamic_cast<Ladder*>(pCell->GetGameObject());
	if (Lad != NULL)
	{
		pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ");
		Lad->Apply(pGrid, this);
	}
	Snake* Snak = dynamic_cast<Snake*>(pCell->GetGameObject());
	if (Snak != NULL)
	{
		pGrid->PrintErrorMessage("You have reached a snake. Click to continue ");
		Snak->Apply(pGrid, this);
	}
	Card* card = dynamic_cast<Card*>(pCell->GetGameObject());
	if (card != NULL)
	{
		card->Apply(pGrid, this);
	}
	int num = CellPosition::GetCellNumFromPosition(pCell->GetCellPosition());
	if (num == 99)
	{
		pGrid->SetEndGame(true);
	}
	return;
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

void Player::setTurnCount(int c)
{
	c = 0;
	turnCount = c;
}