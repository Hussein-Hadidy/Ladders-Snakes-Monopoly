#pragma once
#include "Card.h"
#include"Grid.h"
class CardSeven : public Card
{

public:
	CardSeven(const CellPosition& pos);
	void Save(ofstream& Outfile, Type t);
	void Load(ifstream& inFile);
	virtual void ReadCardParameters(Grid* pGrid); // No parameters
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardSeven();
};

