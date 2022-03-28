#include "Snake.h"
#include <fstream>

Snake::Snake(const CellPosition& startCellPos, const CellPosition& SnakeEndPos) : GameObject(startCellPos)
{
	if (startCellPos.IsValidCell() == true)
	{
		position = startCellPos;
	}
	if (SnakeEndPos.IsValidCell() == true)
	{
		this->SnakeEndPos = SnakeEndPos;
	}
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, SnakeEndPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->UpdatePlayerCell(pPlayer, SnakeEndPos);
	pPlayer->SetStepCount(SnakeEndPos.GetCellNum());
}

CellPosition Snake::GetEndPosition() const
{
	return SnakeEndPos;
}

bool Snake::IsOverLapping(GameObject* newObj) const // Added by Mariam
{
	GameObject* g = dynamic_cast<Snake*>(newObj);
	if (g != NULL)
		return GameObject::IsOverLapping(newObj);
}

void Snake::Save(ofstream& sfile, int i)
{
	if (i == 2)
	{
		sfile << this->GetPosition().GetCellNum() << " " << this->GetEndPosition().GetCellNum() << endl;
	}
	else
		return;
}

Snake::~Snake()
{

}