#pragma once
#include <memory>

#include "BaseScene.h"


class BattleField;

class GameScene :
    public BaseScene
{
public:
	GameScene();
	~GameScene();
private:
	virtual bool Init(void);
	virtual std::unique_ptr<BaseScene> Update(std::unique_ptr<BaseScene> ownScene);

	virtual void DrawOwnScreen(void);
	virtual void DebugDraw(void);

	std::unique_ptr<BattleField> battleField_;
};

