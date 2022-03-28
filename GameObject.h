#pragma once

#include "Grid.h"

class GameObject
{
protected:

	CellPosition position; 

public:

	GameObject(const CellPosition & pos); 
	CellPosition GetPosition() const;     

	// ============ Virtual Functions ============

	virtual void Draw(Output* pOut) const = 0;	
	virtual void Apply(Grid* pGrid, Player* pPlayer) = 0;  

	// The following functions are examples of what should be supported by the GameObject class
	// They should be overridden by each inherited class

	// Decide the parameters that you should pass to each function	
	
	//virtual void Save(ofstream& OutFile) = 0;	// Saves the GameObject parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	// Loads and Reads the GameObject parameters from the file
	
	virtual bool IsOverLapping(GameObject* newObj) const;
	virtual ~GameObject();
};

