#include "Card9_11.h"
#include "CardNine.h"
Player* CardNine::owner = NULL;
bool CardNine::firstTime = true;
bool CardNine::isSaved = false;//to save once
bool CardNine::isLoaded = false;//to load once
CardNine::CardNine(const CellPosition& pos) : Card9_11(pos)
{
	cardNumber = 9;
}
void CardNine::Save(ofstream& Outfile, Type t)
{
	if (t == CARD)
	{
		Card::Save(Outfile, t);
		if (isSaved)
		{
			Outfile << endl;
			return;
		}
		Outfile << cardPrice << " " << feesToPayByPlayers << endl;
		isSaved = true;
	}
}
void CardNine::Load(ifstream& Infile)
{
	Card::Load(Infile);
	if (isLoaded)
	{
		return;
	}
	Infile >> cardPrice >> feesToPayByPlayers;
	isLoaded = true;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("New CardNine, click to continue");
	if (firstTime == true)
	{
		Card9_11::ReadCardParameters(pGrid);
		firstTime = false;
	}
}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card9_11::Apply(pGrid, pPlayer, owner);
}
int CardNine::GetcardPrice()
{
	return cardPrice;
}
void CardNine::changeOwner(Player* ptr)
{
	owner = ptr;
}
void CardNine::resetowner()
{
	owner = NULL;
}
CardNine::~CardNine()
{
}
