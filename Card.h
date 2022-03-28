#pragma once

#include "GameObject.h"
#include "Player.h"
# include <cstring>


class Card : public GameObject
{
protected:
	int cardNumber;

public:
	Card(const CellPosition & pos); 
	void SetCardNumber(int cnum);   
	int GetCardNumber();            

	void Draw(Output* pOut) const;
	virtual void ReadCardParameters(Grid * pGrid); 
	virtual void Apply(Grid* pGrid, Player* pPlayer);  
	virtual void Save(ofstream& sfile, int i);
	virtual ~Card(); 
};

