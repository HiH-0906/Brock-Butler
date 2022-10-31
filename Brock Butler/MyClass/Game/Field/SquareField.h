#pragma once
#include "BattleField.h"


class SquareField :
    public BattleField
{
public:
	SquareField(const Vector2Int& pos);
	virtual~SquareField();
private:
	bool Init(void)override;

	void DrawOwnScreen(void)override;
	void DebugDraw(void)override;

	bool CheckPutBlock(const Vector2Int& mPos)override;

	bool PutBlock(const Vector2Int& mPos, BLOCK_TYPE type)override;

	Vector2Int Pos2Grid(const Vector2Int& mPos)override;

	bool CheckGrid(const Vector2Int& grid)override;

	Vector2Int gridSize_;
};

