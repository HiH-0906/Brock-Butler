#include <DxLib.h>
#include "CrossOver.h"

CrossOver::CrossOver(std::unique_ptr<BaseScene> beforScene, std::unique_ptr<BaseScene> afterScene, const double& limitTime) :
	TransitionScene(std::move(beforScene), std::move(afterScene)), limitTime_(limitTime)
{
}

CrossOver::~CrossOver()
{
}

bool CrossOver::UpdateTransition(const float& delta)
{
	count_ += delta;
	return (count_ > limitTime_);
}

void CrossOver::DrawOwnScreen()
{
	SetDrawScreen(screenID_);
	int alpha = static_cast<int>(EIGHTBITS_NUM_F * count_ / limitTime_);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, EIGHTBITS_NUM - alpha);
	beforScene_->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	afterScene_->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);
}
