#include <DxLib.h>
#include <cassert>

#include "SceneManager.h"

#include "../common/DHUtility.h"
#include "../common/TimeKeeper.h"

#include "../Scene/BaseScene.h"
#include "../Scene/TitleScene.h"

#include "../../_debug/_DebugDispOut.h"
#include "../../_debug/_DebugConOut.h"


namespace
{
	constexpr int screenSizeX = 1920;
	constexpr int screenSizeY = 1080;
}

void SceneManager::Run(void)
{
	if (!SystemInit())
	{
		return;
	}

	GameInit();

	_dbgSetup(screenSizeX, screenSizeY, 255);

	while (!ProcessMessage() && isGameRun_ && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClsDrawScreen();
		_dbgStartDraw();
	
		timeKeeper_->TimeUpdate();

		scene_ = scene_->Update(std::move(scene_));

		scene_->DrawOwnScreen();
#ifdef _DEBUG
		if (CheckHitKey(KEY_INPUT_1))
		{
			SceneManager::GetInstance().GameEnd();
		}
#endif // _DEBUG
		SetDrawScreen(DX_SCREEN_BACK);

		scene_->Draw();
		_dbgAddDraw();

		ScreenFlip();
	}
	SetMouseDispFlag(true);
	DxLib_End();
}

const float& SceneManager::GetDelta(void)
{
	return timeKeeper_->GetDelta();
}

void SceneManager::GameEnd(void)
{
	isGameRun_ = false;
}


SceneManager::SceneManager()
{
	isGameRun_ = false;
}

SceneManager::~SceneManager() = default;

bool SceneManager::SystemInit(void)
{
	SetAlwaysRunFlag(true);
	SetOutApplicationLogValidFlag(false);
	SetGraphMode(screenSizeX, screenSizeY, 32);
	ChangeWindowMode(true);
	SetWindowText("1916035_Brock Butler");



	if (DxLib_Init() == -1)
	{
		assert(!"DxLibInité∏îs");
		return false;
	}

	timeKeeper_ = std::make_unique<TimeKeeper>();

    return true;
}

bool SceneManager::GameInit(void)
{
	isGameRun_ = true;

	scene_ = std::make_unique<TitleScene>();

	return true;
}

