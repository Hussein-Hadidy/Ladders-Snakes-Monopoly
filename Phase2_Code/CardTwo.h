#pragma once
#include"Card.h"
#include"Grid.h"
class CardTwo:public Card
{

public:
	CardTwo(const CellPosition& pos); 
	void Load(ifstream& inFile);
	virtual void Apply(Grid* pGrid, Player* pPlayer);  
	virtual void ReadCardParameters(Grid* pGrid);
	void Save(ofstream& Outfile, Type t);
	virtual ~CardTwo(); 
};

