#pragma once
#include <DxLib.h>
#include "Vector3.h"

class DHUtility
{
public:
	// VECTOR ����Vector3�ϊ�
	static Vector3 VECToVec3(const VECTOR& vec);
	static VECTOR Vec3ToVEC(const Vector3& vec);
	// ���W�A��(rad)����x(deg)
	static float Rad2Deg(float rad);

	// �x(deg)���烉�W�A��(rad)
	static float Deg2Rad(float deg);

	// ��]�����Ȃ����̉�]�������擾����(���v���:1�A�����v���:-1)
	static float DirNearAroundRad(float from, float to);

	// ��]�����Ȃ����̉�]�������擾����(���v���:1�A�����v���:-1)
	static float DirNearAroundDeg(float from, float to);

	// 0�`360�x�͈̔͂Ɏ��߂�
	static double DegIn360(double deg);

	// 0(0)�`2��(360�x)�͈̔͂Ɏ��߂�
	static double RadIn2PI(double rad);

	// 0�`360�x�͈̔͂Ɏ��߂�
	static float DegIn360(float deg);

	// 0(0)�`2��(360�x)�͈̔͂Ɏ��߂�
	static float RadIn2PI(float rad);

	static int Clamp(int value, int min = 0, int max = 1);
	static float Clamp(float value, float min = 0.0f, float max = 1.0f);
private:
	DHUtility();
	DHUtility(const DHUtility&) = delete;
	void operator=(const DHUtility&) = delete;

	static DHUtility& Instance(void);
	// VECTOR ����Vector3�ϊ�
	Vector3 VECToVec3_(const VECTOR& vec);
	VECTOR Vec3ToVEC_(const Vector3& vec);
	// ���W�A��(rad)����x(deg)
	float Rad2Deg_(float rad);

	// �x(deg)���烉�W�A��(rad)
	float Deg2Rad_(float deg);

	// ��]�����Ȃ����̉�]�������擾����(���v���:1�A�����v���:-1)
	float DirNearAroundRad_(float from, float to);

	// ��]�����Ȃ����̉�]�������擾����(���v���:1�A�����v���:-1)
	float DirNearAroundDeg_(float from, float to);

	// 0�`360�x�͈̔͂Ɏ��߂�
	double DegIn360_(double deg);

	// 0(0)�`2��(360�x)�͈̔͂Ɏ��߂�
	double RadIn2PI_(double rad);

	// 0�`360�x�͈̔͂Ɏ��߂�
	float DegIn360_(float deg);

	// 0(0)�`2��(360�x)�͈̔͂Ɏ��߂�
	float RadIn2PI_(float rad);
	
	int Clamp_(int value, int min, int max);
	float Clamp_(float value, float min, float max);
};

