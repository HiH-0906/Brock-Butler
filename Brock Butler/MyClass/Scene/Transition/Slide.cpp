#include <Dxlib.h>
#include "Slide.h"
#include "../../Manager/SceneManager.h"
#include "../../common/Vector2.h"

Slide::Slide(std::unique_ptr<BaseScene> beforScene, std::unique_ptr<BaseScene> afterScene, const double& limitTime):
	TransitionScene(std::move(beforScene), std::move(afterScene)), limitTime_(limitTime)
{
	Init();
}

Slide::~Slide()
{
	DeleteGraph(beforScreen_);
	DeleteGraph(afterScreen_);
}

bool Slide::Init(void)
{
	int x = 0;
	int y = 0;
	GetDrawScreenSize(&x,&y);
	const auto& scrSize = Vector2Int{x,y};
	beforScreen_ = MakeScreen(scrSize.x, scrSize.y, true);
	SetDrawScreen(beforScreen_);
	beforScene_->Draw();
	afterScreen_ = MakeScreen(scrSize.x, scrSize.y, true);
	SetDrawScreen(afterScreen_);
	afterScene_->Draw();
	return true;
}

bool Slide::UpdateTransition(const float& delta)
{
	count_ += delta;
	return (count_ > limitTime_);
}

void Slide::DrawOwnScreen(void)
{
	int x = 0;
	int y = 0;
	GetDrawScreenSize(&x, &y);
	SetDrawScreen(screenID_);
	ClsDrawScreen();
	const int& scrX = x;
	int moveX = static_cast<int>((scrX) * (count_ / limitTime_));
	DrawGraph(-moveX, 0, beforScreen_, true);
	DrawGraph(scrX - moveX, 0, afterScreen_, true);
}
