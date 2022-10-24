#include <DxLib.h>
#include "TimeKeeper.h"
#include "../../_debug/_DebugDispOut.h"


namespace
{
	constexpr float DELTA_TIME_TOLERANCE = 0.1f;
}

TimeKeeper::TimeKeeper()
{
	deltaTime_ = 0;
	slowRate_ = 0.0f;
	slowTime_ = 0.0f;
}


TimeKeeper::~TimeKeeper() = default;

void TimeKeeper::Init()
{
	deltaTime_ = 0;
	now_ = std::chrono::system_clock().now();
	slowRate_ = 1.0f;
	slowTime_ = 0.0f;
}

void TimeKeeper::TimeUpdate()
{
	old_ = now_;
	now_ = std::chrono::system_clock().now();
	
	deltaTime_ = static_cast<float>(std::chrono::duration_cast<std::chrono::microseconds>(now_ - old_).count() / 1000000.0);

	slowTime_ -= deltaTime_;
	
	if (slowTime_ <= 0.0f)
	{
		slowRate_ = 1.0f;
		slowTime_ = 0.0f;
	}

	slowRate_ = slowRate_ < 1.0f ? 1.0f : slowRate_;
	deltaTime_ /= slowRate_;

	// ‰æ–ÊŠO‚¨‚³‚í‚è‘Îô
	deltaTime_ = deltaTime_ <= DELTA_TIME_TOLERANCE ? deltaTime_ : 0.0f;
}

const float& TimeKeeper::GetDelta(void)
{
	return deltaTime_;
}

void TimeKeeper::SetSlowRate(const float& rate, const float& time)
{
	if (slowTime_ != 0.0f)
	{
		return;
	}
	slowRate_ = rate;
	slowTime_ = time;
}

const float& TimeKeeper::GetSlowRate(void) const
{
	return slowRate_;
}

bool TimeKeeper::isSlow(void)
{
	return slowRate_ != 1.0f;
}

void TimeKeeper::DebugDraw(void)
{
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "DeltaTime:%f", deltaTime_);
	DrawFormatString(0, 16, 0xffffff, "slowTime_:%f", slowTime_);
	DrawFormatString(0,32,0xffffff,"DrawCall:%d",GetDrawCallCount());
#endif	//_DEBUG
}
