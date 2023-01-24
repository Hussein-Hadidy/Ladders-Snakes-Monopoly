#include "CardFour.h"
CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number 
}
void CardFour::Save(ofstream& Outfile, Type t)
{
	if (t == CARD)
	{
		Card::Save(Outfile, t);
		Outfile << endl;
	}
}
void CardFour::Load(ifstream& inFile)
{
	Card::Load(inFile);
}
void CardFour ::ReadCardParameters(Grid* pGrid)
{
	//no parameters here
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetFreeze(1);
	pGrid->PrintErrorMessage("You have been frozen for 1 turn! , click to continue");
}
CardFour::~CardFour()
{}
