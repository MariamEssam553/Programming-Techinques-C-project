#pragma once

#include "GameObject.h"

class Ladder :	public GameObject 
{
	CellPosition endCellPos; 

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos);
	virtual void Draw(Output* pOut) const; 
	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	CellPosition GetEndPosition() const; 
	virtual bool IsOverLapping(GameObject* newObj) const;
	void Save(ofstream& sfile, int i);
	virtual ~Ladder(); 
};

