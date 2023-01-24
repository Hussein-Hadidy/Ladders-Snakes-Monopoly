#pragma once
#include"Card.h"
class CardThree: public Card
{

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount
	void Save(ofstream& Outfile, Type t);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	void Load(ifstream& inFile);
	virtual ~CardThree(); // A Virtual Destructor
};

