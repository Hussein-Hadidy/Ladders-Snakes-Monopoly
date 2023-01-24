#include "Snake.h"
#include "Ladder.h"

int Snake::snakescount = 0;
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	type = SNAKE;
	this->endCellPos = endCellPos;
	snakescount++;
	///TODO: Do the needed validation
}
void Snake::Save(ofstream& Outfile, Type t)
{
	if (t == SNAKE)
		Outfile << position.GetCellNum() << " " << endCellPos.GetCellNum()<<endl;
}
void Snake::Load(ifstream& InFile)
{
	int x;
	InFile >> x;
	position = CellPosition::GetCellPositionFromNum(x);
	int y;
	InFile >> y;
	endCellPos = CellPosition::GetCellPositionFromNum(y);
}
int Snake::printsnakeCount()
{
	return snakescount;
}
void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	//This function already calls GetPointClicked at the end
	pGrid->PrintErrorMessage("You have reached a Snake, click to continue");
	// 2- Apply the Snake's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}
/*bool Ladder::IsOverlapping(GameObject* newObj) const
{
	Ladder* pr = dynamic_cast<Ladder*>(newObj);
		if (pr != NULL)
		{
			int vcellcurr = this->GetPosition().VCell();
			int hcellcurr = this->GetPosition().HCell();
			int vcellcurrend = this->GetEndPosition().VCell();
			int hcellcurrend = this->GetEndPosition().HCell();
			int vcellnew = pr->GetPosition().VCell();
			int hcellnew = pr->GetPosition().HCell();
			int vcellnewend = pr->GetEndPosition().VCell();
			int hcellnewend = pr->GetEndPosition().HCell();
			if (hcellcurr == hcellnew && ((vcellnew >= vcellcurr && vcellnew <= vcellcurrend) || (vcellnewend > vcellcurr && vcellnewend < vcellcurrend)))
			{

			}
		}

}
*/
CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}

