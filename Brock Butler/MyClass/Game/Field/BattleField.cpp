#include <DxLib.h>

#include "BattleField.h"

BattleField::BattleField(const Vector2Int& pos):pos_(pos)
{
	screenID_ = -1;
	size_ = { -1,-1 };
}

BattleField::~BattleField()
{
}

void BattleField::Draw(void)
{
	DrawGraph(pos_.x, pos_.y, screenID_, true);

#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_P))
	{
		DebugDraw();
	}
#endif // _DEBUG
}
