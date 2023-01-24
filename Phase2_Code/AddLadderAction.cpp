#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{

}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// Read the startPos parameter
	//Check if start cell is valid
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");

	startPos.SetVCell(0);
	endPos.SetVCell(-1);
	CellPosition temp1 = pIn->GetCellClicked();
	bool checkValid = temp1.IsValidCell();
	int V = temp1.VCell();
	if ((checkValid == false))
	{
		pGrid->PrintErrorMessage("You clicked on an invalid start cell, click another cell");
		pOut->ClearStatusBar();
		return;
	}
	if (temp1.GetCellNum() == 1)
	{
		pGrid->PrintErrorMessage("Invalid!! No Objects allowed in first Cell");
		pOut->ClearStatusBar();
		return;
	}
	if (V == 0)
	{
		pGrid->PrintErrorMessage("Invalid!! Start Cell Of Ladder Cannot be in Last Row,click another cell");
		pOut->ClearStatusBar();
		return;
	}
	else
	{
		startPos = temp1;

	}

	// Read the endPos parameter
	//check if endcell is valid
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
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
	if ((CellPosition::GetCellNumFromPosition(temp2) < CellPosition::GetCellNumFromPosition(temp1)))
	{
		pGrid->PrintErrorMessage("Invalid!! End Cell must be larger than start cell, click to continue"); // no exectuion of addladderaction
		pOut->ClearStatusBar();
		return;
	}
	if (temp2.GetCellNum() == NumHorizontalCells * NumVerticalCells)
	{
		pGrid->PrintErrorMessage("Invalid!! No Objects Allowed in Final Cell, click to continue"); // no exectuion of addladderaction
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



void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if (startPos.VCell() != 0 && endPos.VCell() != -1)
	{
		Ladder* pLadder = new Ladder(startPos, endPos);

		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pLadder);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
		//delete pLadder;
	}

	//for (int i = 0; i < NumVerticalCells - 1; i++)
	//{
		//pGrid->Cellist[i][startPos.HCell()]
		//bool x = Ladder::IsOverlapping();
	//}
	// Create a Ladder object with the parameters read from the user
	else
		return;
}