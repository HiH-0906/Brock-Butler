#pragma once
#include <memory>

class BaseScene;

class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager s_Instance_;
		return s_Instance_;
	}
	void Run(void);

	/// <summary>
	/// 呼び出しでゲーム終了
	/// </summary>
	void GameEnd(void);


private:
	SceneManager();
	~SceneManager();

	bool SystemInit(void);
	bool GameInit(void);

	bool isGameRun_;

	std::unique_ptr<BaseScene> scene_;
};

