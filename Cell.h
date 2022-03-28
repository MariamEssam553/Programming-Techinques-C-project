#pragma once 

#include "UI_Info.h"
#include "CellPosition.h"

// Class forward declarations (their #include is in the .cpp file)
class Grid;
class Output;
class GameObject;
class Ladder;
class Snake;
class Card;
class Player;

class Cell
{
	const CellPosition position;
	GameObject * pGameObject;  // if no GameObject in this Cell, pGameObject should be NULL

public:

	Cell(const CellPosition & pos); 
	Cell(int v, int h);

	// ======= Setters and Getters Functions ======= 

	CellPosition GetCellPosition() const; 
	bool SetGameObject(GameObject * pGObj);	
	GameObject * GetGameObject() const;
	Ladder * HasLadder() const;	
	Snake * HasSnake() const;
	Card * HasCard() const;
	
	// ======= Drawing Functions ======= 

	void DrawCellOrCard(Output* pOut) const;
	void DrawLadderOrSnake(Output* pOut) const;	
};

