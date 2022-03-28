#pragma once

#include "UI_Info.h"
#include "DEFS.h"

#include "Input.h"
#include "Output.h"
#include "CellPosition.h"

// forward declarations (the includes are in the cpp)
class Cell;
class GameObject;
class Ladder;
class Snake;
class Card;
class Player;

class Grid
{
	Output * pOut; 
	Input * pIn;     
	Cell * CellList[NumVerticalCells][NumHorizontalCells];  
	Player* PlayerList[MaxPlayerCount]; 
	int currPlayerNumber;   // The player number that has the turn to play 
							// currPlayerNumber is: from 0 to MaxPlayerCount - 1

	Card * Clipboard;	   // This is used in copy/cut/paste card (should be set in copy/cut and got in paste)
	bool endGame;	       // A boolean indicating if the Game is ended or not (a player reaches the end cell of the grid or not)

public:

	Grid(Input * pIn, Output * pOut);

	// ========= Adding or Removing GameObjects to Cells =========

	bool AddObjectToCell(GameObject * pNewObject);	
	void RemoveObjectFromCell(const CellPosition & pos); 
	void UpdatePlayerCell(Player * player, const CellPosition & newPosition); 

	// ========= Setters and Getters Functions =========

	Input * GetInput() const;	
	Output * GetOutput() const; 
	void SetClipboard(Card * card);  // A setter to be used in copy/cut (in order NOT to break class responsibilities)
	Card * GetClipboard() const;	 // A getter to be used in paste (in order NOT to break class responsibilities)
	void SetEndGame(bool endGame);	 
	bool GetEndGame() const;		 
	void AdvanceCurrentPlayer(); 

	bool CheckGameObjectLoopOnGrid(Card*);
	//bool CheckOnStations(Card* card);

	// ========= Other Getters =========
	
	Player * GetCurrentPlayer() const;	// Gets a Pointer to the Current Player	                                    
	Ladder * GetNextLadder(const CellPosition & position);  // Gets a Pointer to the first Ladder after the passed "position"
	Snake* GetNextSnake(const CellPosition& position);
	Card* GetCurrentCard(const CellPosition& position);
	bool IsOverLapping(GameObject* newObj) const;
	// ========= User Interface Functions =========

	void UpdateInterface() const;
	void PrintErrorMessage(string msg); 
	void SaveAll(ofstream& sfile, int type);
	~Grid(); 
};

