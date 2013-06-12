/*
 * @file	Block.h
 *
 * @date	22.05.2013
 * @author	Superuser
 * @brief	Block.h
 */

#ifndef BLOCK_H_
#define BLOCK_H_

class Block
{
	public:
		Block();
		Block(const bool _occupied);
		bool isOccupied();
		virtual ~Block();
	private:
		bool occupied;
};

#endif /* BLOCK_H_ */
