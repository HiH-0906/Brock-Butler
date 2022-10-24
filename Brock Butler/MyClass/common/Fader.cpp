#include <DxLib.h>
#include "Fader.h"

Fader::FADE_STATE Fader::GetState(void)
{
	return state_;
}

bool Fader::IsEnd(void)
{
	return isEnd_;
}

void Fader::SetFade(FADE_STATE state)
{
	state_ = state;
	if (state_ != FADE_STATE::NONE)
	{
		isPreEnd_ = false;
		isEnd_ = false;
	}
}

void Fader::Init(void)
{
	state_ = FADE_STATE::NONE;
	alpha_ = 0;
	isPreEnd_ = true;
	isEnd_ = true;
}

void Fader::Update(void)
{

	if (isEnd_)
	{
		return;
	}

	switch (state_)
	{
	case FADE_STATE::NONE:
		return;

	case FADE_STATE::FADE_OUT:
		alpha_ += SPEED_ALPHA;
		if (alpha_ > 255)
		{
			// �t�F�[�h�I��
			alpha_ = 255;
			if (isPreEnd_)
			{
				// 1�t���[����(Draw��)�ɏI���Ƃ���
				isEnd_ = true;
			}
			isPreEnd_ = true;
		}

		break;

	case FADE_STATE::FADE_IN:
		alpha_ -= SPEED_ALPHA;
		if (alpha_ < 0)
		{
			// �t�F�[�h�I��
			alpha_ = 0;
			if (isPreEnd_)
			{
				// 1�t���[����(Draw��)�ɏI���Ƃ���
				isEnd_ = true;
			}
			isPreEnd_ = true;
		}
		break;

	default:
		return;
	}

}

void Fader::Draw(void)
{

	switch (state_)
	{
	case FADE_STATE::NONE:
		return;
	case FADE_STATE::FADE_OUT:
	case FADE_STATE::FADE_IN:
		int x, y;
		GetDrawScreenSize(&x, &y);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha_);
		DrawBox(0, 0, x, y, 0x000000, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	}

}
