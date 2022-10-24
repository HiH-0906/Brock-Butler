#include <DxLib.h>
#include "TitleScene.h"

TitleScene::TitleScene()
{
	Init();
}

TitleScene::~TitleScene()
{
}

bool TitleScene::Init(void)
{
	return true;
}

std::unique_ptr<BaseScene> TitleScene::Update(std::unique_ptr<BaseScene> ownScene)
{
	return std::move(ownScene);
}

void TitleScene::DrawOwnScreen(void)
{
	int defscr = GetDrawScreen();

	SetDrawScreen(screenID_);
	ClearDrawScreen();
}

void TitleScene::DebugDraw(void)
{
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "TitleScene");
#endif // _DEBUG
}
