#include <DxLib.h>

#include "GameScene.h"

#include "../Game/Field/SquareField.h"

#include "../Game/Card/CardData.h"

#include "../../_debug/_DebugConOut.h"


// デバック用
namespace
{
	constexpr int FIELD_OFFSET_X = 336;
	constexpr int FIELD_OFFSET_Y = 124;

	bool hitROld = false;
	bool hitRNow = false;
	int dir = 0;
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

	Vector2Int cardPos = { 32,0 };
	Vector2Int cardSize = { 32 * 6,0 };

	cardData_.emplace_back( std::make_unique<CardData>(CARD_ID::TEST, cardPos));
	cardPos += cardSize;
	cardData_.emplace_back(std::make_unique<CardData>(CARD_ID::TEST2, cardPos));
	cardPos += cardSize;
	cardData_.emplace_back(std::make_unique<CardData>(CARD_ID::TEST3, cardPos));

	nowCard_ = 0;

	mPos_ = {};

	return true;
}

std::unique_ptr<BaseScene> GameScene::Update(std::unique_ptr<BaseScene> ownScene)
{
	hitROld = hitRNow;
	hitRNow = CheckHitKey(KEY_INPUT_R);
	if (!hitROld && hitRNow)
	{
		dir++;
		cardData_[nowCard_]->SetDir(dir % 4);
	}
	// ブロック置けるか確認用
	int mx = 0;
	int my = 0;

	GetMousePoint(&mx, &my);

	mPos_ = { mx - 16,my - 16 };

	int mInput = GetMouseInput();

	if (mInput & MOUSE_INPUT_LEFT)
	{
		if (PutBlock(mPos_,BLOCK_TYPE::RED,true))
		{
			TRACE("置ける\n");
			PutBlock(mPos_, BLOCK_TYPE::RED, false);
		}
	}

	if (mInput & MOUSE_INPUT_RIGHT)
	{
		if (PutBlock(mPos_, BLOCK_TYPE::BLUE, true))
		{
			TRACE("置ける\n");
			PutBlock(mPos_, BLOCK_TYPE::BLUE, false);
		}
	}

	if (CheckHitKey(KEY_INPUT_1))
	{
		nowCard_ = 0;
	}
	if (CheckHitKey(KEY_INPUT_2))
	{
		nowCard_ = 1;
	}
	if (CheckHitKey(KEY_INPUT_3))
	{
		nowCard_ = 2;
	}

	return std::move(ownScene);
}

bool GameScene::PutBlock(const Vector2Int& mpos, const BLOCK_TYPE& type, bool isCheck)
{
	auto CheckPutCardDataBlock = [&](const Vector2Int& pos)->bool{
		if (isCheck)
		{
			return battleField_->CheckPutBlock(pos);
		}
		else
		{
			return battleField_->PutBlock(pos,type);
		}
	};



	const auto& bData = cardData_[nowCard_]->GetBlockData();
	const auto dataNumMax = cardData_[nowCard_]->GetBlockDataNum();
	const auto blockSize = Vector2Int{ battleField_->BlockSize_X,battleField_->BlockSize_Y };

	auto dataNum = Vector2Int{ -dataNumMax.x / 2,-dataNumMax.y / 2 };

	Vector2Int cardDataPos = blockSize * dataNum;
	Vector2Int dataPos = mpos + cardDataPos;

	bool checkbool = false;

	for (int x = 0; x < dataNumMax.x; x++)
	{
		for (int y = 0; y < dataNumMax.y; y++)
		{
			if (!cardData_[nowCard_]->CheckData(Vector2Int{x,y}))
			{
				dataNum.y++;
				continue;
			}
			cardDataPos = blockSize * dataNum;
			dataPos = mpos + cardDataPos;
			if (!CheckPutCardDataBlock(dataPos))
			{
				return false;
			}
			dataNum.y++;
		}
		dataNum.x++;
		dataNum.y = -dataNumMax.y / 2;
	}

	return true;
}

void GameScene::DrawOwnScreen(void)
{
	battleField_->DrawOwnScreen();
	int defscr = GetDrawScreen();

	SetDrawScreen(screenID_);
	ClearDrawScreen();


	battleField_->Draw();

	for (const auto& card : cardData_)
	{
		card->Draw();
	}
		

	const auto& bData = cardData_[nowCard_]->GetBlockData();
	const auto dataNumMax = cardData_[nowCard_]->GetBlockDataNum();
	const auto blockSize = Vector2Int{ battleField_->BlockSize_X,battleField_->BlockSize_Y };

	auto dataNum = Vector2Int{ -dataNumMax.x / 2,-dataNumMax.y / 2 };

	Vector2Int cardDataPos = blockSize * dataNum;
	Vector2Int dataPos = mPos_ + cardDataPos;

	bool checkbool = false;

	for (int x = 0; x < dataNumMax.x; x++)
	{
		for (int y = 0; y < dataNumMax.y; y++)
		{
			if (!cardData_[nowCard_]->CheckData(Vector2Int{ x,y }))
			{
				dataNum.y++;
				continue;
			}
			cardDataPos = blockSize * dataNum;
			dataPos = mPos_ + cardDataPos;
			DrawBox(dataPos.x, dataPos.y, dataPos.x + blockSize.x, dataPos.y + blockSize.y, 0x888888, true);
			dataNum.y++;
		}
		dataNum.x++;
		dataNum.y = -dataNumMax.y / 2;
	}

	SetDrawScreen(defscr);
}

void GameScene::DebugDraw(void)
{
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "GameScene");
#endif // _DEBUG
}
