#pragma once
#include <string>
#include <vector>

#include "../../common/Vector2.h"


enum class BLOCK_TYPE
{
	NON,
	RED,
	BLUE,
	SPECIAL_RED,
	SPECIAL_BLUE,
	STONE,
};

class BattleField
{
public:
	BattleField(const Vector2Int& pos);
	virtual ~BattleField();

	virtual bool Init(void) = 0;

	virtual void Draw(void);
	virtual void DrawOwnScreen(void) = 0;
	virtual void DebugDraw(void) = 0;

	/// <summary>
	/// 渡された座標に該当するマス目にどのBlockを設置できるかを返す
	/// </summary>
	/// <param name="mPos">座標</param>
	/// <returns>true:設置できる felse:設置できない or 範囲外</returns>
	virtual bool CheckPutBlock(const Vector2Int& mPos) = 0;

	/// <summary>
	/// 指定した座標にブロックを設置する
	/// </summary>
	/// <param name="mPos">座標</param>
	/// <param name="type">置きたいBlockのType</param>
	/// <returns>true:設置完了</returns>
	virtual bool PutBlock(const Vector2Int& mPos,BLOCK_TYPE type) = 0;

	const int BlockSize_X = 32;
	const int BlockSize_Y = 32;
private:

protected:
	/// <summary>
	/// 渡された座標を各フィールドのマス目へ変換する
	/// </summary>
	/// <param name="mPos">座標</param>
	/// <returns>マス目</returns>
	virtual Vector2Int Pos2Grid(const Vector2Int& mPos) = 0;

	/// <summary>
	/// 渡されたgridが有効範囲内か調べる
	/// </summary>
	/// <param name="grid">マス目</param>
	/// <returns>true:有効</returns>
	virtual bool CheckGrid(const Vector2Int& grid) = 0;
	
	Vector2Int pos_;
	Vector2Int size_;
	int screenID_;
	std::string blockImageKey_;

	std::vector<std::vector<BLOCK_TYPE>> blockData_;
};

