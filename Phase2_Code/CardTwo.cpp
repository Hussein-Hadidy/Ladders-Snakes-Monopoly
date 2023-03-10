#include"CardTwo.h"
#include"Card.h"
#include"Ladder.h"
#include "CellPosition.h"
CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	//no parameters here
}
void CardTwo::Save(ofstream& Outfile, Type t)
{
	if (t == CARD)
	{
		Card::Save(Outfile, t);
		Outfile << endl;
	}
}
void CardTwo::Load(ifstream& inFile)
{
	Card::Load(inFile);
}
 void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
 {
	 Card::Apply(pGrid, pPlayer);
	bool checkmove= pPlayer->Move_apply(pGrid);
	if (!checkmove)
	{
		pGrid->PrintErrorMessage("No ladder ahead to move to, click to continue");
	}
 }
 CardTwo::~CardTwo()
 {}
