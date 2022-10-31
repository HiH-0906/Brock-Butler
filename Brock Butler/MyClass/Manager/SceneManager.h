#pragma once
#include <memory>

class TimeKeeper;
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

	const float& GetDelta(void);

	/// <summary>
	/// ŒÄ‚Ño‚µ‚ÅƒQ[ƒ€I—¹
	/// </summary>
	void GameEnd(void);


private:
	SceneManager();
	~SceneManager();

	bool SystemInit(void);
	bool GameInit(void);

	bool isGameRun_;

	std::unique_ptr<TimeKeeper> timeKeeper_;
	std::unique_ptr<BaseScene> scene_;
};

