#include <DxLib.h>
#include "FadeInOut.h"

FadeInOut::FadeInOut(std::unique_ptr<BaseScene> beforScene, std::unique_ptr<BaseScene> afterScene, const double& limitTime):
	TransitionScene(std::move(beforScene), std::move(afterScene)), limitTime_(limitTime)
{
}

FadeInOut::~FadeInOut()
{
}

bool FadeInOut::UpdateTransition(const float& delta)
{
	count_ += delta;
	return (count_ > limitTime_);
}

void FadeInOut::DrawOwnScreen()
{
	SetDrawScreen(screenID_);
	ClearDrawScreen();
	int alpha = static_cast<int>(EIGHTBITS_NUM_F * count_ / (limitTime_ / 2.0));
	if (limitTime_ / 2.0 > count_)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, EIGHTBITS_NUM - alpha);
		beforScene_->Draw();
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha - EIGHTBITS_NUM);
		afterScene_->Draw();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);
}
