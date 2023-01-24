#pragma once
#include "Card.h"
class CardSix : public Card
{

	CellPosition FinalPos;

public:
	CardSix(const CellPosition& pos);
	void Save(ofstream& Outfile, Type t);
	void Load(ifstream& inFile);
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSix which is: FinalPos
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardSix();
};

