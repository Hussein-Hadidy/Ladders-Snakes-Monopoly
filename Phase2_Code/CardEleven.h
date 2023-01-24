#pragma once
#include "Card9_11.h"
class CardEleven : public Card9_11
{
	static Player* owner;
	static bool firstTime;
	static bool isSaved;
	static bool isLoaded;
public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position
	void Save(ofstream& Outfile, Type t);
	void Load(ifstream& Infile);
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card9_11
	virtual int GetcardPrice();
	virtual void changeOwner(Player* ptr);
	static void resetowner(); //static member function that reset owner to NULL
	virtual ~CardEleven(); // A Virtual Destructor
};







