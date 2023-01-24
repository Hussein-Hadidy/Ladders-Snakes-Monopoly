#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"
AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// Read the startPos parameter
	//Check if start cell is valid
	pOut->PrintMessage("New snake: Click on its Start Cell ...");

	startPos.SetVCell(-1);
	endPos.SetVCell(0);
	CellPosition temp1 = pIn->GetCellClicked();
	bool checkValid = temp1.IsValidCell();
	int V = temp1.VCell();
	if ((checkValid == false))
	{
		pGrid->PrintErrorMessage("You clicked on an invalid start cell, click another cell");
		pOut->ClearStatusBar();
		return;
	}
	if (temp1.GetCellNum() == NumHorizontalCells * NumVerticalCells || temp1.GetCellNum() == 1)
	{
		pGrid->PrintErrorMessage("Invalid!! No Objects allowed in first or final cells,click to continue");
		pOut->ClearStatusBar();
		return;
	}
	if (V == NumVerticalCells - 1)
	{
		pGrid->PrintErrorMessage("Invalid!! Start Cell Of Snake Cannot be in first Row,click to continue");
		pOut->ClearStatusBar();
		return;
	}
	else
	{
		startPos = temp1;

	}

	// Read the endPos parameter
	//check if endcell is valid
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	CellPosition temp2 = pIn->GetCellClicked();
	bool checkvalid2 = temp2.IsValidCell();
	if ((checkvalid2 == false))
	{
		pGrid->PrintErrorMessage("Invalid!! You clicked on an invalid end cell, click to continue"); // no exectuion of addladderaction
		pOut->ClearStatusBar();
		return;
	}
	if (temp2.VCell() == temp1.VCell())
	{
		pGrid->PrintErrorMessage("Invalid!! End cell and Start Cell cannot be in the same row, click to continue"); // no exectuion of addladderaction
		pOut->ClearStatusBar();
		return;
	}
	if (temp1.HCell() != temp2.HCell())
	{
		pGrid->PrintErrorMessage("Invalid!! Start and End Cells must be in the column, click to continue"); // no exectuion of addladderaction
		pOut->ClearStatusBar();
		return;
	}
	if ((CellPosition::GetCellNumFromPosition(temp2) > CellPosition::GetCellNumFromPosition(temp1)))
	{
		pGrid->PrintErrorMessage("Invalid!! End Cell must be smaller than start cell, click to continue"); // no exectuion of addladderaction
		pOut->ClearStatusBar();
		return;
	}
	if (temp2.GetCellNum() == 1)
	{
		pGrid->PrintErrorMessage("Invalid!! No Objects Allowed in First Cell, click to continue"); // no exectuion of addladderaction
		pOut->ClearStatusBar();
		return;
	}
	else
	{
		endPos = temp2;
	}

	///TODO: Make the needed validations on the read parameters

	pOut->ClearStatusBar();

	// Clear messages
}

void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if (startPos.VCell() != -1 && endPos.VCell() != 0)
	{
		// Create a Ladder object with the parameters read from the user
		Snake* pSnake = new Snake(startPos, endPos);

		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction
		//delete pSnake;

	}
	else return;
}
