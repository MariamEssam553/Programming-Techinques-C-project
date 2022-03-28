#pragma once
#include "Player.h"

class Snake :public GameObject
{
	CellPosition SnakeEndPos;
public:
	
	Snake(const CellPosition& startCellPos, const CellPosition& SnakeEndPos);
	virtual void Draw(Output* pOut) const; 
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	CellPosition GetEndPosition() const;
	virtual bool IsOverLapping(GameObject* newObj) const;
	void Save(ofstream& sfile, int i);
	virtual ~Snake();
};