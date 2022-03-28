#pragma once

#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h" 

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player
	Card* StationsOwned[5];   //pointer to the stations owned by the player
	int numOfStations;

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	
public:

	Player(Cell * pCell, int playerNum); 

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount

	//void SetCardArray(Card* GOBJ);
	//Card** GetCardArray();
	//int GetNumStations();

	int getcout();
	int getjustRolledDiceNum();
	void SetStepCount(int y);
	void setjustRolledDiceNum(int c);

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;		
	void ClearDrawing(Output* pOut) const;

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	
	void AppendPlayerInfo(string & playersInfo) const; 

	void setTurnCount(int c);
};

