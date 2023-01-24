#pragma once
#include "GameObject.h"
class Snake : public GameObject
{
	static int snakescount;
	static bool saved;
	CellPosition endCellPos; // here is the Snake's End Cell Position

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	//virtual bool IsOverlapping(GameObject*newObj) const;

	void Save(ofstream& Outfile, Type t);
	void Load(ifstream& InFile);

	static int printsnakeCount(); //static member function used to print only once in save grid action

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Snake(); // Virtual destructor


};

