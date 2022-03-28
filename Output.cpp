#include "Output.h"
#include "Input.h"
#include <iostream>
using namespace std;
 
Output::Output()
{
	// Initialize user interface parameters
	UI.InterfaceMode = MODE_DESIGN;

	// Widths and Heights

	UI.StatusBarHeight = 60;
	UI.ToolBarHeight = 55;
	UI.MenuItemWidth = 55;

	UI.width = 1210; // make it divisible by NumHorizontalCells 
	UI.height = 610; 
	UI.wx = 5;
	UI.wy = 5;

	UI.CellWidth = UI.width / NumHorizontalCells; //(110)
	UI.CellHeight = (UI.height -  UI.ToolBarHeight - UI.StatusBarHeight) / NumVerticalCells;
	//(55)

	// Pen Colors of messages of status bar and players' info
	UI.MsgColor = DARKRED;
	UI.PlayerInfoColor = DARKSLATEBLUE;

	// Background Colors of toolbar and statusbar 
	UI.ToolBarColor = WHITE;
	UI.StatusBarColor = LIGHTGRAY; 

	// Line Colors of the borders of each cell
	UI.GridLineColor = WHITE;

	// Cell Color if Empty & Cell Number Font & Color
	UI.CellColor_NoCard = LIGHTSLATEBLUE;
	UI.CellNumFont = 13;
	UI.CellNumColor = UI.GridLineColor;

	// Cell Color if Has Card & CARD Number Font & Color
	UI.CellColor_HasCard = SALMON;
	UI.CardNumFont = 35;
	UI.CardNumColor = WHITE;

	// Ladder Line Width and Color
	UI.LadderlineWidth = 6;
	UI.LadderColor = DARKSLATEBLUE;

	// The X and Y Offsets of the Space BEFORE Drawing the Ladder (offset from the start X and Y of the Cell)
	UI.LadderXOffset = (UI.CellWidth  - 2 * UI.LadderlineWidth) / 5;
	UI.LadderYOffset = UI.CellHeight / 2;

	// Snake Line Width and Color
	UI.SnakelineWidth = 6;
	UI.SnakeColor = FIREBRICK;

	// Colors of the 4 Players
	UI.PlayerColors[0] = GOLD;
	UI.PlayerColors[1] = DARKSLATEBLUE;
	UI.PlayerColors[2] = KHAKI;
	UI.PlayerColors[3] = CHOCOLATE;

	// Create the output window
	pWind = CreateWind(UI.width + 15, UI.height, UI.wx, UI.wy); 

	// Change the title
	pWind->ChangeTitle("Snakes & Ladders");

	// Create the toolbar, grid area and status bar
	CreateDesignModeToolBar();
	ClearGridArea();
	ClearStatusBar();

}
 
window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	// The Window Object is created inside the Ouput class
	window* pW = new window(w, h, x, y);
	return pW;
}
 
Input* Output::CreateInput() const
{
	// The Input Object is created inside the Output class
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Some Utility Functions										//
//======================================================================================//
int Output::GetCellStartX(const CellPosition & cellPos) const
{
	int x;
	x = cellPos.HCell();
	return x * UI.CellWidth;
}

int Output::GetCellStartY(const CellPosition & cellPos) const
{
	int x;
	x = cellPos.VCell();
	return UI.ToolBarHeight + (x * UI.CellHeight);
}

void Output::DrawCardNumber(const CellPosition & cellPos, int cardNum) const
{
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);
	pWind->SetPen(UI.CardNumColor);
	pWind->SetFont(UI.CardNumFont, BOLD | ITALICIZED , BY_NAME, "Arial");
	int w=0, h=0;
	pWind->GetIntegerSize(w, h, cardNum);
	int x = cellStartX + UI.CellWidth - UI.LadderXOffset - w - 5; 
	int y = cellStartY + (UI.CellHeight - h) / 2;
	pWind->DrawInteger(x, y, cardNum);
}

void Output::ClearToolBar() const
{
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//
void Output::ClearStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}

void Output::ClearGridArea() const
{
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			CellPosition cellPos(i, j);
			DrawCell(cellPos); // Initially NO Cards in the cell
		}
	}
}

void Output::CreateDesignModeToolBar() const
{
	UI.InterfaceMode = MODE_DESIGN;
	ClearToolBar(); 
	string MenuItemImages[DESIGN_ITM_COUNT];
	MenuItemImages[ITM_ADD_SNAKE] = "images\\Menu_Snake.jpg";
	MenuItemImages[ITM_ADD_LADDER] = "images\\Menu_Ladder.jpg";
	MenuItemImages[ITM_ADD_CARD] = "images\\Menu_Card.jpg";	
	MenuItemImages[ITM_COPY_CARD] = "images\\Copy_Card.jpg";
	MenuItemImages[ITM_CUT_CARD] = "images\\Cut_Card.jpeg";
	MenuItemImages[ITM_PAST_CARD] = "images\\Past_Card.jpeg";
	MenuItemImages[ITM_EDIT_CARD] = "images\\Edit_Card.jpeg";
	MenuItemImages[ITM_DELETE_GAME_OBJECT] = "images\\Delete_Game_Object.jpeg";
	MenuItemImages[ITM_SAVE_GRID] = "images\\Save_Grid.jpeg";
	MenuItemImages[ITM_OPEN_GRID] = "images\\Open_Grid.jpeg";
	MenuItemImages[ITM_SWITCH_TO_PLAY_MODE] = "images\\Menu_SwitchToGame.jpg";
	//MenuItemImages[ITM_GAME_OVER]= "images\\Menu_Killer.jpg";
	//MenuItemImages[ITM_PUT_OBSTACLE] = "images\\Menu_Obstacle.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu_Exit.jpg";

	for(int i=0; i < DESIGN_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
}

void Output::CreatePlayModeToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	ClearToolBar(); 
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_ROLL_DICE] = "images\\Menu_Dice.jpg";
	MenuItemImages[ITM_DICE_VALUE] = "images\\Input_Dice_Value.jpg";
	MenuItemImages[ITM_NEW_GAME] = "images\\New_Game.jpg";
	MenuItemImages[ITM_SWITCH_TO_DESIGN_MODE] = "images\\Menu_SwitchToGrid.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\Menu_Exit.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT ; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}

void Output::PrintMessage(string msg) const	
{
	ClearStatusBar();	
	pWind->SetPen(UI.MsgColor);
	pWind->SetFont(18, BOLD , BY_NAME, "Verdana");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.3), msg);
}

void Output::PrintPlayersInfo(string info)
{
	CreatePlayModeToolBar();
	pWind->SetPen(UI.PlayerInfoColor); 
	pWind->SetFont(20, BOLD , BY_NAME, "Verdana");   
	int w=0, h=0;
	pWind->GetStringSize(w, h, info);
	int x = UI.width - w - 20; 
	int y = (UI.ToolBarHeight - h) / 2; 
	pWind->DrawString(x, y, info);
}

//======================================================================================//
//			         			Game Drawing Functions   								//
//======================================================================================//
void Output::DrawCell(const CellPosition & cellPos, int cardNum) const
{
	int cellNum = cellPos.GetCellNum();
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	//1- Draw the cell itself (Filled Rectangle)
	pWind->SetPen(UI.GridLineColor, 1);
	if (cardNum == -1) // no card
		pWind->SetBrush(UI.CellColor_NoCard);
	else
		pWind->SetBrush(UI.CellColor_HasCard);
	pWind->DrawRectangle(cellStartX, cellStartY, cellStartX + UI.CellWidth, cellStartY + UI.CellHeight);
	//2- Draw the CELL number (the small number at the bottom right of the cell)
	pWind->SetPen(UI.CellNumColor);
	pWind->SetFont(UI.CellNumFont, BOLD , BY_NAME, "Verdana");   
	int w=0, h=0;
	pWind->GetIntegerSize(w, h, UI.CellNumFont);
	int x = cellStartX + (UI.CellWidth - w - 1);   
	int y = cellStartY + (UI.CellHeight - h - 1);  
	pWind->DrawInteger(x, y, cellPos.GetCellNum());
	//3- Draw card number 
	if (cardNum != -1) 
		DrawCardNumber(cellPos, cardNum);
}

void Output::DrawPlayer(const CellPosition & cellPos, int playerNum, color playerColor) const
{
	if (!(playerNum >= 0 && playerNum < MaxPlayerCount))
		return;
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);
	int radius = UI.CellWidth / 14; 
	int ySpace = UI.CellHeight / 6;
	int y = cellStartY + ySpace + radius + 2;
	if (playerNum == 2 || playerNum == 3)
		y += radius + 2 + radius; 
	int x = cellStartX + UI.LadderXOffset + radius + 4; 
	if (playerNum == 1 || playerNum == 3)
		x += radius + 2 + radius; 
	pWind->SetBrush(playerColor);
	pWind->SetPen(playerColor);
	pWind->DrawCircle(x, y, radius, FILLED);
}

void Output::DrawLadder(const CellPosition & fromCell, const CellPosition & toCell) const
{
	if (fromCell.GetCellNum() > toCell.GetCellNum())
		return;
	int x = fromCell.HCell(); //must be smaller
	int y = toCell.HCell();
	int nb = y - x;
	if (nb % NumHorizontalCells != 0)
		return;
	int cellStartX = GetCellStartX(fromCell);
	int fromStartY = GetCellStartY(fromCell);
	int toStartY = GetCellStartY(toCell); //same X (vertical)

	//1- Draw the First Vertical Line  
	int x12 = cellStartX + UI.LadderXOffset; 
	int y1 = fromStartY + UI.LadderYOffset;
	int y2 = toStartY + UI.CellHeight - UI.LadderYOffset;
	pWind->SetPen(UI.LadderColor, UI.LadderlineWidth);
	pWind->DrawLine(x12, y1, x12, y2);
	//2- Draw the Second Vertical Line  
	int x34 = cellStartX + UI.CellWidth - UI.LadderXOffset; 
	pWind->SetPen(UI.LadderColor, UI.LadderlineWidth);
	pWind->DrawLine(x34, y1, x34, y2);
	//3- Draw the Cross Horizontal Lines
	int HHH;
	HHH = fromStartY - toStartY;
	int R = HHH / UI.CellHeight;
	pWind->SetPen(UI.LadderColor, UI.LadderlineWidth);
	pWind->SetBrush(UI.LadderColor);
	for (int i = 0;i < R ;i++)
	{
		int OP = fromStartY - (i * UI.CellHeight);
		pWind->DrawLine(x12, OP, x34, OP);
	}	
}

void Output::DrawSnake(const CellPosition & fromCell, const CellPosition & toCell) const
{
	if (fromCell.GetCellNum() < toCell.GetCellNum())
	{
		PrintMessage("End cell cannot be smaller than start cell");
		return;
	}
	int x = fromCell.HCell(); //must be bigger
	int y = toCell.HCell();
	int nb = x - y;
	if (nb % NumHorizontalCells != 0)
	{
		PrintMessage("End cell and start cell are not in the same column");
		return;
	}
	int cellStartX = GetCellStartX(fromCell); // same for fromCell and toCell (vertical)
	int fromStartY = GetCellStartY(fromCell);
	int toStartY = GetCellStartY(toCell);

	//1- Draw Line representing the Snake Body
	int x12 = cellStartX + UI.LadderXOffset/2; 
	int y1 = fromStartY + UI.CellHeight/2;
	int y2 = toStartY + UI.CellHeight/2;
	pWind->SetPen(UI.SnakeColor, UI.SnakelineWidth);
	pWind->DrawLine(x12, y1, x12, y2);
	//2- Draw Polygon with Diamond Shape representing the Snake Head
	pWind->SetPen(UI.SnakeColor, UI.SnakelineWidth);
	pWind->SetBrush(UI.SnakeColor);
	int yChange = UI.CellHeight / 4; 
	int xChange = UI.CellWidth / 14; 
	/*int Xarr[4] = { x12,x12 ,x12 - xChange / 2,x12 + xChange / 2 };
	int Yarr[4] = { y1,y1 + yChange,yChange / 2,yChange / 2 };*/
	int Xarr[4] = { x12 ,x12 - xChange,x12,x12 + xChange };
	int Yarr[4] = { y1 + yChange, y1,y1 - yChange ,y1 };
	//int Yarr[4] = { y1, y1 - yChange,y1 - 2 * yChange ,y1 - yChange };
	pWind->DrawPolygon(Xarr, Yarr, 4);
}

Output::~Output()
{
	delete pWind;
}

