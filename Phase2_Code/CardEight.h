#pragma once
#include "Card.h"
class CardEight :public Card
{
	int Fees;
public:
	CardEight(const CellPosition& pos);
	void Save(ofstream& Outfile, Type t);
	virtual void ReadCardParameters(Grid* pGrid); 
	void Load(ifstream& inFile);
	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~CardEight(); 
};

