#include "OpenGridAction.h"

#include "SaveGridAction.h"
#include "Grid.h"
#include"Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

#include <fstream>
OpenGridAction::OpenGridAction(ApplicationManager* pApp) :Action(pApp)
{

}
void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	fileName = pIn->GetSrting(pOut);
}
void OpenGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->ClearAll();//clears all gameobjects in the grid
	ReadActionParameters();
	ifstream file;
	file.open(fileName);
	int numOfLadders;
	file >> numOfLadders;
	for (int i = 0;i < numOfLadders;i++)
	{
		CellPosition temp(45);
		CellPosition temp2(56);
		Ladder* pLadder = new Ladder(temp, temp2);
		pLadder->Load(file);
		pGrid->AddObjectToCell(pLadder);
	}
	int numOfSnakes;
	file >> numOfSnakes;
	for (int i = 0;i < numOfSnakes;i++)
	{
		CellPosition temp(56);
		CellPosition temp2(45);
		Snake* pSnake = new Snake(temp, temp2);
		pSnake->Load(file);
		pGrid->AddObjectToCell(pSnake);
	}
	int numOfCards;
	file >> numOfCards;
	for (int i = 0;i < numOfCards;i++)
	{
		int Cardnum;
		file >> Cardnum;
		//pGrid->PrintErrorMessage("inte: " + to_string(Cardnum));
		Card* pCard;
		pCard = NULL;
		CellPosition temp(2);
		switch (Cardnum)
		{
		case 1:
			pCard = new CardOne(temp);
			break;
		case 2:
			pCard = new CardTwo(temp);
			break;
		case 3:
			pCard = new CardThree(temp);
			break;
		case 4:
			pCard = new CardFour(temp);
			break;
		case 5:
			pCard = new CardFive(temp);
			break;
		case 6:
			pCard = new CardSix(temp);
			break;
		case 7:
			pCard = new CardSeven(temp);
			break;
		case 8:
			pCard = new CardEight(temp);
			break;
		case 9:
			pCard = new CardNine(temp);
			break;
		case 10:
			pCard = new CardTen(temp);
			break;
		case 11:
			pCard = new CardEleven(temp);
			break;
		case 12:
			pCard = new CardTwelve(temp);
			break;
		}
		pCard->Load(file);
		pGrid->AddObjectToCell(pCard);
	}
	file.close();
}
OpenGridAction::~OpenGridAction()
{

}