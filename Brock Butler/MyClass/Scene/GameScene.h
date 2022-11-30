#pragma once
#include <memory>
#include <vector>

#include "BaseScene.h"

#include "../Game/Card/BLOCK_TYPE.h"

#include "../common/Vector2.h"


class BattleField;
class CardData;

class GameScene :
    public BaseScene
{
public:
	GameScene();
	~GameScene();
private:
	virtual bool Init(void);
	virtual std::unique_ptr<BaseScene> Update(std::unique_ptr<BaseScene> ownScene);

	bool PutBlock(const Vector2Int& mpos, const BLOCK_TYPE& type,bool isCheck);

	virtual void DrawOwnScreen(void);
	virtual void DebugDraw(void);

	std::unique_ptr<BattleField> battleField_;

	std::vector< std::unique_ptr<CardData>> cardData_;
	int nowCard_;

	Vector2Int mPos_;
};

