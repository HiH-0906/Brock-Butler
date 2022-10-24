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
	/// �Ăяo���ŃQ�[���I��
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

