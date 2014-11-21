/****************************************
* Student Name:		Rina Fridland
* Exercise Name:
* File description:
****************************************/

#include "Block.h"

Block::Block(int x, int y): Coordinates(x, y) {}

Block::~Block() {
}

bool Block::isAt(Coordinates coords) {
}
/*************************************************************************
* Function name:	isHit          *
* The Input:        x and y - the coordinates of the hit      *
* The output:       boolean - is this block hit or not        *
* The Function operation:         checks whether the block was hit  *
*************************************************************************/
//bool Block::isHit(int x, int y)
//{
//	if((this->x == x) && (this->y == y))
//	{
//		delete this;
//		return true;
//	}
//	return false;
//}

//void Block::draw(Board board)
//{
//}
