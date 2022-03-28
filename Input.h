#ifndef INPUT_H
#define INPUT_H

#include "DEFS.h"
#include "UI_Info.h" 
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CellPosition.h"

// forward declarations (their includes are in the cpp)
class Output;  

class Input		// The application manager & grid (phase 2) should have a pointer to this class
{
private:
	window *pWind;	// Pointer to the Graphics Windo
public:

	// ========== General Functions ==========
	Input(window *pW); 
	void GetPointClicked(int &x, int &y) const;
	string GetString(Output* pO) const;  
	int GetInteger(Output* pO) const;   
	
	// ========== Game Functions ==========
	ActionType GetUserAction() const;
	CellPosition GetCellClicked() const; 
};

#endif