#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); 
}

bool CellPosition::SetVCell(int v) 
{
	if (v >= 0 && v < NumVerticalCells)
	{
		vCell = v;
		return true;
	}
	else
		return false;
}

bool CellPosition::SetHCell(int h) 
{
	if (h >= 0 && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}
	else
		return false;
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	if (vCell >= 0 && vCell < NumVerticalCells && hCell >= 0 && hCell < NumHorizontalCells)
	{
		return true;
	}
	else
		return false;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); 
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	int x;
	x = cellPosition.VCell();
	int y;
	y = cellPosition.HCell();
	int cellnum1;
	if (x >= 0 && x < NumVerticalCells)
	{
		if (y >= 0 && y < NumHorizontalCells)
		{
			cellnum1 = ((NumVerticalCells - 1 - x) * NumHorizontalCells) + (y + 1);
			return cellnum1;
		}
		else
			return 0;
	}
	else
		return 0;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	if (cellNum >= 0 && cellNum <= NumHorizontalCells * NumVerticalCells)
	{
		CellPosition position;
		int x;
		if (cellNum % NumHorizontalCells == 0)
		{
			x = NumVerticalCells - (cellNum / NumHorizontalCells);
		}
		else
		{
			x = NumVerticalCells - 1 - (cellNum / NumHorizontalCells);
		}
		int y;
		if (cellNum % NumHorizontalCells == 0)
			y = NumHorizontalCells - 1;
		else
		{
			y = (cellNum % NumHorizontalCells) - 1;
		}
		position.SetVCell(x);
		position.SetHCell(y);
		return position;
	}
	else 
		return 0;
}

void CellPosition::AddCellNum (int addedNum)
{
	CellPosition p1;
	p1.SetHCell(hCell);
	p1.SetVCell(vCell);

	int cellNb;
	cellNb = GetCellNumFromPosition(p1);
	cellNb = cellNb + addedNum;
	p1 = GetCellPositionFromNum(cellNb);
	hCell = p1.HCell();
	vCell = p1.VCell();
}