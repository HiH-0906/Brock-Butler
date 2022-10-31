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
	/// �n���ꂽ���W�ɊY������}�X�ڂɂǂ�Block��ݒu�ł��邩��Ԃ�
	/// </summary>
	/// <param name="mPos">���W</param>
	/// <returns>true:�ݒu�ł��� felse:�ݒu�ł��Ȃ� or �͈͊O</returns>
	virtual bool CheckPutBlock(const Vector2Int& mPos) = 0;

	/// <summary>
	/// �w�肵�����W�Ƀu���b�N��ݒu����
	/// </summary>
	/// <param name="mPos">���W</param>
	/// <param name="type">�u������Block��Type</param>
	/// <returns>true:�ݒu����</returns>
	virtual bool PutBlock(const Vector2Int& mPos,BLOCK_TYPE type) = 0;

	const int BlockSize_X = 32;
	const int BlockSize_Y = 32;
private:

protected:
	/// <summary>
	/// �n���ꂽ���W���e�t�B�[���h�̃}�X�ڂ֕ϊ�����
	/// </summary>
	/// <param name="mPos">���W</param>
	/// <returns>�}�X��</returns>
	virtual Vector2Int Pos2Grid(const Vector2Int& mPos) = 0;

	/// <summary>
	/// �n���ꂽgrid���L���͈͓������ׂ�
	/// </summary>
	/// <param name="grid">�}�X��</param>
	/// <returns>true:�L��</returns>
	virtual bool CheckGrid(const Vector2Int& grid) = 0;
	
	Vector2Int pos_;
	Vector2Int size_;
	int screenID_;
	std::string blockImageKey_;

	std::vector<std::vector<BLOCK_TYPE>> blockData_;
};

