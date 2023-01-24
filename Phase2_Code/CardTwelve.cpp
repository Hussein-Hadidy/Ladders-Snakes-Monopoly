#include "CardTwelve.h"
CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos)
{
	cardNumber = 12;
}
void CardTwelve::Save(ofstream& Outfile, Type t)
{
	if (t == CARD)
	{
		Card::Save(Outfile, t);
		Outfile << endl;
	}
}
void CardTwelve::Load(ifstream& inFile)
{
	Card::Load(inFile);
}
void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	Player *poorest=pGrid->GetPoorest();
	Card9_11* ownedcity=pPlayer->changeOwnerships(poorest,pGrid);
	if (ownedcity != NULL)
	{
		ownedcity->changeOwner(poorest);
	}
}
CardTwelve::~CardTwelve()
{

}