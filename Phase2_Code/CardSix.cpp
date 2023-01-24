#include "CardSix.h"
#include "CellPosition.h"
#include"Ladder.h"
#include"Snake.h"
CardSix::CardSix(const CellPosition& pos) : Card(pos)// Sets Card Number
{
	cardNumber = 6;
}
void CardSix::Save(ofstream& Outfile, Type t)
{
	if (t == CARD)
	{
		Card::Save(Outfile, t);
		Outfile << FinalPos.GetCellNum() << endl;
	}
}
void CardSix::Load(ifstream& inFile)
{
	Card::Load(inFile);
	int finalpos;
	inFile >> finalpos;
	FinalPos = CellPosition::GetCellPositionFromNum(finalpos);

}
void CardSix::ReadCardParameters(Grid* pGrid) // Reads the parameters of CardSix which is: FinalPos
{

	pGrid->GetOutput()->PrintMessage("Click on Cell to move to");
	CellPosition CPtemp = pGrid->GetInput()->GetCellClicked();//Gets Cell to Move to from User
	//int Inttemp = CellPosition::GetCellNumFromPosition(CPtemp);// Converts the Cellpostion to the CellNumber and stores it Temp for Cell Number to be Validated
	while (!CPtemp.IsValidCell())// Checks That its a Valid Cell
	{
		pGrid->GetOutput()->PrintMessage("Invalid CellNumber Please click on a valid Cell ");
		CPtemp = pGrid->GetInput()->GetCellClicked();
	}

	FinalPos = CPtemp;
	pGrid->GetOutput()->ClearStatusBar();
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)//Moves Current Player to a specific cell
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->Moveapply(pGrid, FinalPos);

}
CardSix::~CardSix()
{

}