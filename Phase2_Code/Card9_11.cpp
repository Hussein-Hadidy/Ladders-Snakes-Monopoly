#include "Card9_11.h" 
int Card9_11::cardPrice = 0;
int Card9_11::feesToPayByPlayers = 0;
Card9_11::Card9_11(const CellPosition& pos) : Card(pos)
{
}
void Card9_11::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Enter card price: ");
	cardPrice = pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter fees to be paid by players");
	feesToPayByPlayers = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void Card9_11::Apply(Grid* pGrid, Player* pPlayer,Player*&owner)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	int currplayerwallet = pPlayer->GetWallet();
	if (owner == NULL)
	{
		pGrid->PrintErrorMessage("Do you want to buy this city, if yes enter 1, if no enter 0?, click to continue");
		int checkbuy = pIn->GetInteger(pOut);
		while (checkbuy != 1 && checkbuy != 0)
		{
			pGrid->PrintErrorMessage("Please enter a valid entry (0 or 1), click to continue");
			checkbuy = pIn->GetInteger(pOut);
		}
		if (checkbuy == 0)
			return;
		else if (currplayerwallet >= cardPrice)
		{
			owner = pPlayer;
			pPlayer->AddCity(this);
			pPlayer->SetWallet(currplayerwallet - cardPrice);
			return;
		}
		else
		{
			pGrid->PrintErrorMessage("You do not have enough money to buy this city, click to continue");
			return;
		}
	}
	else
	{
		//Check that it is not your owned city
		if (owner == pPlayer)
		{
			pGrid->PrintErrorMessage("This is your owned city, click to continue");
			return;
		}
		pGrid->PrintErrorMessage("You landed on an owned city, fees will be deducted, click to continue");
		//Fees transfer from 1 player to the other
		if (currplayerwallet >= feesToPayByPlayers)
		{
			int ownerplayerwallet = owner->GetWallet();
			currplayerwallet -= feesToPayByPlayers;
			pPlayer->SetWallet(currplayerwallet);
			ownerplayerwallet += feesToPayByPlayers;
			owner->SetWallet(ownerplayerwallet);
		}
		else //paying whatever he can and set the wallet to 0
		{
			int ownerplayerwallet = owner->GetWallet();
			pPlayer->SetWallet(0);
			owner->SetWallet(ownerplayerwallet + currplayerwallet);
		}
	}
}

Card9_11::~Card9_11()
{

}
