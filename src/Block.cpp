/*
 * @file	Block.cpp
 *
 * @date	22.05.2013
 * @author	Superuser
 * @brief	Block.cpp
 */

#include "..\inc\Block.h"

Block::Block() :
		rendered (true)
{
	// TODO Auto-generated constructor stub

}

Block::Block(const bool _rendered) :
		rendered (_rendered)
{
	// TODO Auto-generated constructor stub
}

Block::~Block()
{
	// TODO Auto-generated destructor stub
}

bool Block::isRendered(void) {
	return rendered;
}
