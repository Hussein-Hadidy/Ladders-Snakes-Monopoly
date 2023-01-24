#include "CardEleven.h"
Player* CardEleven::owner = NULL;
bool CardEleven::firstTime = true;
bool CardEleven::isSaved = false;
bool CardEleven::isLoaded = false;//to load once
CardEleven::CardEleven(const CellPosition& pos) : Card9_11(pos)
{
	cardNumber = 11;
}
void CardEleven::Save(ofstream& Outfile, Type t)
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
void CardEleven::Load(ifstream& Infile)
{
	Card::Load(Infile);
	if (isLoaded)
	{
		return;
	}
	Infile >> cardPrice >> feesToPayByPlayers;
	isLoaded = true;
}
void CardEleven::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("New CardEleven, click to continue");
	if (firstTime == true)
	{
		Card9_11::ReadCardParameters(pGrid);
		firstTime = false;
	}
}
int CardEleven::GetcardPrice()
{
	return cardPrice;
}
void CardEleven::changeOwner(Player* ptr)
{
	owner = ptr;
}
void CardEleven::resetowner()
{
	owner = NULL;
}
CardEleven::~CardEleven()
{
}