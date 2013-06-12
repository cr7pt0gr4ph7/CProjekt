/*
 * @file	Block.cpp
 *
 * @date	22.05.2013
 * @author	Superuser
 * @brief	Block.cpp
 */

#include "Block.h"

Block::Block() :
		occupied (true)
{
	// TODO Auto-generated constructor stub

}

Block::Block(const bool _occupied) :
		occupied (_occupied)
{
	// TODO Auto-generated constructor stub
}

Block::~Block()
{
	// TODO Auto-generated destructor stub
}

bool Block::isOccupied(void) {
	return occupied;
}
