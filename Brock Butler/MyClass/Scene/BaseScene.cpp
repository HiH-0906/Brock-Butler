#include <DxLib.h>
#include "BaseScene.h"
#include "../Manager/SceneManager.h"

BaseScene::BaseScene()
{
	int x, y;
	GetDrawScreenSize(&x, &y);
	screenID_ = MakeScreen(x, y, true);
}

BaseScene::~BaseScene()
{
	DeleteGraph(screenID_);
}

void BaseScene::Draw(void)
{
	DrawGraph(0, 0, screenID_, true);

#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_P))
	{
		DebugDraw();
	}
#endif // _DEBUG
}
