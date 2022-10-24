#include <DxLib.h>
#include "TransitionScene.h"
#include "../../Manager/SceneManager.h"

TransitionScene::TransitionScene(std::unique_ptr<BaseScene> beforScene, std::unique_ptr<BaseScene> afterScene)
{
	beforScene_ = std::move(beforScene);
	afterScene_ = std::move(afterScene);
	afterScene_->DrawOwnScreen();
	count_ = 0.0;
	Init();
}

TransitionScene::~TransitionScene()
{
}

bool TransitionScene::Init(void)
{
	return true;
}

std::unique_ptr<BaseScene> TransitionScene::Update(std::unique_ptr<BaseScene> ownScene)
{
	if (UpdateTransition(0.0f))
	{
		return std::move(afterScene_);
	}
	return ownScene;
}

void TransitionScene::DebugDraw(void)
{
#ifdef _DEBUG

#endif // DEBUG

}
