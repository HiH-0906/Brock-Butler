#pragma once
#include <DxLib.h>
#include "Vector3.h"

class DHUtility
{
public:
	// VECTOR ←→Vector3変換
	static Vector3 VECToVec3(const VECTOR& vec);
	static VECTOR Vec3ToVEC(const Vector3& vec);
	// ラジアン(rad)から度(deg)
	static float Rad2Deg(float rad);

	// 度(deg)からラジアン(rad)
	static float Deg2Rad(float deg);

	// 回転が少ない方の回転向きを取得する(時計回り:1、反時計回り:-1)
	static float DirNearAroundRad(float from, float to);

	// 回転が少ない方の回転向きを取得する(時計回り:1、反時計回り:-1)
	static float DirNearAroundDeg(float from, float to);

	// 0～360度の範囲に収める
	static double DegIn360(double deg);

	// 0(0)～2π(360度)の範囲に収める
	static double RadIn2PI(double rad);

	// 0～360度の範囲に収める
	static float DegIn360(float deg);

	// 0(0)～2π(360度)の範囲に収める
	static float RadIn2PI(float rad);

	static int Clamp(int value, int min = 0, int max = 1);
	static float Clamp(float value, float min = 0.0f, float max = 1.0f);
private:
	DHUtility();
	DHUtility(const DHUtility&) = delete;
	void operator=(const DHUtility&) = delete;

	static DHUtility& Instance(void);
	// VECTOR ←→Vector3変換
	Vector3 VECToVec3_(const VECTOR& vec);
	VECTOR Vec3ToVEC_(const Vector3& vec);
	// ラジアン(rad)から度(deg)
	float Rad2Deg_(float rad);

	// 度(deg)からラジアン(rad)
	float Deg2Rad_(float deg);

	// 回転が少ない方の回転向きを取得する(時計回り:1、反時計回り:-1)
	float DirNearAroundRad_(float from, float to);

	// 回転が少ない方の回転向きを取得する(時計回り:1、反時計回り:-1)
	float DirNearAroundDeg_(float from, float to);

	// 0～360度の範囲に収める
	double DegIn360_(double deg);

	// 0(0)～2π(360度)の範囲に収める
	double RadIn2PI_(double rad);

	// 0～360度の範囲に収める
	float DegIn360_(float deg);

	// 0(0)～2π(360度)の範囲に収める
	float RadIn2PI_(float rad);
	
	int Clamp_(int value, int min, int max);
	float Clamp_(float value, float min, float max);
};

