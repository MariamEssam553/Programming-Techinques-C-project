#pragma once
#include "Action.h"

class DeleteGameObject :public Action
{

	CellPosition cellposition;

public:

	DeleteGameObject(ApplicationManager* pAM);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~DeleteGameObject();
};