#include <DxLib.h>

#include "GameScene.h"

#include "../Game/Field/SquareField.h"

// デバック用
namespace
{
	constexpr int FIELD_OFFSET_X = 336;
	constexpr int FIELD_OFFSET_Y = 124;
}

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
}

bool GameScene::Init(void)
{
	int scrx = 0;
	int scry = 0;

	GetDrawScreenSize(&scrx, &scry);

	battleField_ = std::make_unique<SquareField>(Vector2Int{ scrx / 2 + FIELD_OFFSET_X, FIELD_OFFSET_Y });
	return true;
}

std::unique_ptr<BaseScene> GameScene::Update(std::unique_ptr<BaseScene> ownScene)
{
	// ブロック置けるか確認用
	int mx = 0;
	int my = 0;

	GetMousePoint(&mx, &my);

	int mInput = GetMouseInput();

	if (mInput & MOUSE_INPUT_LEFT)
	{
		battleField_->PutBlock(Vector2Int{ mx,my }, BLOCK_TYPE::RED);
	}

	if (mInput & MOUSE_INPUT_RIGHT)
	{
		battleField_->PutBlock(Vector2Int{ mx,my }, BLOCK_TYPE::BLUE);
	}


	return std::move(ownScene);
}

void GameScene::DrawOwnScreen(void)
{
	battleField_->DrawOwnScreen();
	int defscr = GetDrawScreen();

	SetDrawScreen(screenID_);
	ClearDrawScreen();


	battleField_->Draw();

	SetDrawScreen(defscr);
}

void GameScene::DebugDraw(void)
{
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "GameScene");
#endif // _DEBUG
}
