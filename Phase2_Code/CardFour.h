#pragma once
#include"Card.h"

class CardFour : public Card
{

public:
	CardFour(const CellPosition& pos); // A Constructor takes card position
	void Save(ofstream& Outfile, Type t);
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount
	void Load(ifstream& inFile);
	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~CardFour(); // A Virtual Destructor
};

