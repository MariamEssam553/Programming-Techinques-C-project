#pragma once
#include"Card.h"
#include "RollDiceAction.h"

class CardEight :public Card
{
public:
	CardEight(const CellPosition& pos);
	//lazm nekteb condition of executing */if condition/*
	//of rolldice class 3ashan 
	//ne-prevent rolling of dice 
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardEight();
};