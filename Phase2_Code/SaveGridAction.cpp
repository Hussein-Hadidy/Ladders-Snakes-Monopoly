#include "SaveGridAction.h"
#include "Grid.h"
#include"Ladder.h"
#include "Snake.h"
#include <fstream>
SaveGridAction::SaveGridAction(ApplicationManager* pApp) :Action(pApp)
{

}
void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	fileName = pIn->GetSrting(pOut);
}
void SaveGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	ofstream myfile;
	myfile.open(fileName);
	myfile << Ladder::printladderCount() << endl;
	pGrid->SaveAll(myfile, LADDER);
	myfile << Snake::printsnakeCount() << endl;
	pGrid->SaveAll(myfile, SNAKE);
	pGrid->SaveAll(myfile, CARD);
	myfile.close();
}
SaveGridAction::~SaveGridAction()
{

}