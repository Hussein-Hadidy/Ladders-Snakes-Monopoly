#pragma once
#include "Card9_11.h"

class CardNine : public Card9_11
{
	static Player* owner;
	static bool firstTime;
	static bool isSaved;
	static bool isLoaded;
	public:
	CardNine(const CellPosition& pos); // A Constructor takes card position
	void Save(ofstream& Outfile, Type t);
	void Load(ifstream& Infile);
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card9_11
	void Apply(Grid* pGrid, Player* pPlayer);
	virtual int GetcardPrice();
	virtual void changeOwner(Player* ptr);
	static void resetowner(); //static member function that reset owner to NULL
	virtual ~CardNine(); // A Virtual Destructor
};

