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
	/// �X���[�Đ��̐ݒ�
	/// </summary>
	/// <param name="rate">�ǂꂾ���X���[�ɂ��邩�B10��n����10����1�̑��x�ɂȂ�</param>
	/// <param name="time">�X���[�p������</param>
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

