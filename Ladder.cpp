#include "Ladder.h"
#include "Player.h"
#include <fstream>

#include <iostream>
using namespace std;

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if (startCellPos.IsValidCell() == true)
	{
		position = startCellPos;
	}
	if (endCellPos.IsValidCell() == true)
	{
		this->endCellPos = endCellPos;
	}
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	pGrid->UpdatePlayerCell(pPlayer,endCellPos);
	pPlayer->SetStepCount(endCellPos.GetCellNum());
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

bool Ladder::IsOverLapping(GameObject* newObj) const // Added by Mariam
{
	GameObject* g = dynamic_cast<Ladder*>(newObj);
	if (g != NULL)
		return GameObject::IsOverLapping(newObj);
}

void Ladder::Save(ofstream& sfile, int i)
{
	if (i == 1)
	{
		sfile << this->GetPosition().GetCellNum() << " " << this->GetEndPosition().GetCellNum() << endl;
	}
	else
		return;
}

Ladder::~Ladder()
{
}
