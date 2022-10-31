#include <DxLib.h>

#include "TitleScene.h"

#include "GameScene.h"
#include "Transition/FadeInOut.h"

#include "../Manager/ImageMng.h"

namespace
{
	int tmp = 0;
}

TitleScene::TitleScene()
{
	Init();
}

TitleScene::~TitleScene()
{
}

bool TitleScene::Init(void)
{
	ImageManager::GetInstance().GetID("Title", "Resources/Image/Title/TmpTitle.png");
	ImageManager::GetInstance().GetID("SPACE", "Resources/Image/Title/TmpSpace.png");
	  
	tmp = 0;

	return true;
}

std::unique_ptr<BaseScene> TitleScene::Update(std::unique_ptr<BaseScene> ownScene)
{
	tmp++;
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::make_unique<FadeInOut>(std::move(ownScene), std::make_unique<GameScene>());
	}
	return std::move(ownScene);
}

void TitleScene::DrawOwnScreen(void)
{
	int defscr = GetDrawScreen();

	SetDrawScreen(screenID_);
	ClearDrawScreen();

	DrawRotaGraph(960, 340, 2.0f, 0.0f, ImageManager::GetInstance().GetID("Title")[0], true);

	if ((tmp / 30) % 2 == 0)
	{
		DrawRotaGraph(960, 840, 1.0f, 0.0f, ImageManager::GetInstance().GetID("SPACE")[0], true);
	}


	SetDrawScreen(defscr);
}

void TitleScene::DebugDraw(void)
{
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "TitleScene");
#endif // _DEBUG
}
