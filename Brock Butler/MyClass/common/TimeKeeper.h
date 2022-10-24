#pragma once
#include <chrono> 

class TimeKeeper
{
public:
	TimeKeeper();
	~TimeKeeper();
	void Init();
	void TimeUpdate();
	const float& GetDelta(void);

	/// <summary>
	/// スロー再生の設定
	/// </summary>
	/// <param name="rate">どれだけスローにするか。10を渡すと10分の1の速度になる</param>
	/// <param name="time">スロー継続時間</param>
	void SetSlowRate(const float& rate, const float& time);

	const float& GetSlowRate(void)const;
	bool isSlow(void);
	void DebugDraw(void);
private:
	std::chrono::system_clock::time_point now_;
	std::chrono::system_clock::time_point old_;
	float deltaTime_;
	float slowRate_;
	float slowTime_;
};

