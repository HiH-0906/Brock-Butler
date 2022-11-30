#include <DxLib.h>
#include <cassert>
#include <map>

#include "SquareField.h"

#include "../../../_debug/_DebugConOut.h"

namespace
{
	constexpr int GRID_SIZE_X = 9;
	constexpr int GRID_SIZE_Y = 26;
}

// debug用
namespace
{
	std::map<BLOCK_TYPE, unsigned int> TmpBlockCol = {
		{BLOCK_TYPE::NON,0xbbbbbb},
		{BLOCK_TYPE::BLUE,0x6666ff},
		{BLOCK_TYPE::RED,0xff6666},
		{BLOCK_TYPE::SPECIAL_BLUE,0x0000ff},
		{BLOCK_TYPE::SPECIAL_RED,0xff0000},
		{BLOCK_TYPE::STONE,0x222222},
	};
}

SquareField::SquareField(const Vector2Int& pos):
	BattleField(pos)
{
	Init();
}

SquareField::~SquareField()
{
}

bool SquareField::Init(void)
{
	gridSize_ = { GRID_SIZE_X ,GRID_SIZE_Y };
	
	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		std::vector<BLOCK_TYPE> tmp = {};
		for (int y = 0; y < GRID_SIZE_Y; y++)
		{
			tmp.emplace_back(BLOCK_TYPE::NON);
		}
		blockData_.emplace_back(tmp);
	}

	blockData_[4][GRID_SIZE_Y - 3] = BLOCK_TYPE::SPECIAL_RED;
	blockData_[4][3] = BLOCK_TYPE::SPECIAL_BLUE;

	screenID_ = MakeScreen(BlockSize_X * GRID_SIZE_X, BlockSize_Y * GRID_SIZE_Y, true);

	return true;
}


void SquareField::DrawOwnScreen(void)
{
	int defscr = GetDrawScreen();

	SetDrawScreen(screenID_);
	ClearDrawScreen();

	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		for (int y = 0; y < GRID_SIZE_Y; y++)
		{
			int tmpx = BlockSize_X * x;
			int tmpy = BlockSize_Y * y;
			DrawBox(tmpx, tmpy, tmpx + BlockSize_X, tmpy + BlockSize_Y, TmpBlockCol[blockData_[x][y]], true);
			DrawBox(tmpx, tmpy, tmpx + BlockSize_X, tmpy + BlockSize_Y, 0x000000, false);
		}
	}

	SetDrawScreen(defscr);
}

void SquareField::DebugDraw(void)
{
}

bool SquareField::CheckPutBlock(const Vector2Int& mPos)
{
	Vector2Int grid = Pos2Grid(mPos);

	if (!CheckGrid(grid))
	{
		// エリア範囲外
		return false;
	}

	// BLOCK_TYPE::NONなら設置できる
	return blockData_[grid.x][grid.y] == BLOCK_TYPE::NON;
}

bool SquareField::PutBlock(const Vector2Int& mPos, BLOCK_TYPE type)
{
	if (!CheckPutBlock(mPos))
	{
		TRACE("置けない\n");
		return false;
	}

	Vector2Int grid = Pos2Grid(mPos);

	if (!CheckGrid(grid))
	{
		// エリア範囲外
		assert(!"エリア範囲外");
		return false;
	}

	blockData_[grid.x][grid.y] = type;

	return true;
}

Vector2Int SquareField::Pos2Grid(const Vector2Int& mPos)
{
	
	Vector2Int pos = mPos - pos_;
	if (pos.x < 0 || pos.y < 0)
	{
		return Vector2Int{ -1,-1 };
	}
	Vector2Int grid = pos / Vector2Int{ BlockSize_X,BlockSize_Y };

	return grid;
}

bool SquareField::CheckGrid(const Vector2Int& grid)
{
	if (grid.x < 0 || grid.x >= GRID_SIZE_X || grid.y < 0 || grid.y >= GRID_SIZE_Y)
	{
		// エリア範囲外
		TRACE("エリア範囲外\n");
		return false;
	}
	return true;
}

BLOCK_TYPE SquareField::CheckWinner()
{
	int red = 0;
	int blue = 0;
	for (int x = 0; x < GRID_SIZE_X; x++)
	{
		for (int y = 0; y < GRID_SIZE_Y; y++)
		{
			if (blockData_[x][y] == BLOCK_TYPE::RED)
			{
				red++;
			}
			else if (blockData_[x][y] == BLOCK_TYPE::BLUE)
			{
				blue++;
			}
			else
			{

			}
		}
	}
	if (red > blue)
	{
		return BLOCK_TYPE::RED;
	}
	else if (red < blue)
	{
		return BLOCK_TYPE::BLUE;
	}
	else
	{
		return BLOCK_TYPE::NON;
	}
}
