#include <algorithm>
#include "DHUtility.h"

Vector3 DHUtility::VECToVec3_(const VECTOR& vec)
{
	return Vector3({ vec.x,vec.y,vec.z });
}

VECTOR DHUtility::Vec3ToVEC_(const Vector3& vec)
{
	return VECTOR({ vec.x,vec.y,vec.z });
}

float DHUtility::Rad2Deg_(float rad)
{
	return rad * (180.0f / DX_PI_F);
}

float DHUtility::Deg2Rad_(float deg)
{
	return deg * (DX_PI_F / 180.0f);
}

float DHUtility::DirNearAroundRad_(float from, float to)
{
    float ret = 1.0f;
    float diff = to - from;

    if (diff >= 0.0f)
    {
        // 比較元よりも時計回りに位置する
        if (diff > DX_PI_F)
        {
            // でも、180度以上離れているので、反時計回りの方が近い
            ret = -1.0f;
        }
        else
        {
            // 時計回り
            ret = 1.0f;
        }
    }
    else
    {
        // 比較元よりも反時計回りに位置する
        if (diff < -DX_PI_F)
        {
            // でも、180度以上離れているので、時計回りの方が近い
            ret = 1.0f;
        }
        else
        {
            // 反時計回り
            ret = -1.0f;
        }
    }
    return ret;
}

float DHUtility::DirNearAroundDeg_(float from, float to)
{
    float ret = 1.0f;
    float diff = to - from;

    if (diff >= 0.0f)
    {
        // 比較元よりも時計回りに位置する
        if (diff > 180.0f)
        {
            // でも、180度以上離れているので、反時計回りの方が近い
            ret = -1.0f;
        }
        else
        {
            // 時計回り
            ret = 1.0f;
        }
    }
    else
    {
        // 比較元よりも反時計回りに位置する
        if (diff < -180.0f)
        {
            // でも、180度以上離れているので、時計回りの方が近い
            ret = 1.0f;
        }
        else
        {
            // 反時計回り
            ret = -1.0f;
        }

    }
    return ret;
}

double DHUtility::DegIn360_(double deg)
{
    deg = fmod(deg, 360.0);
    if (deg < 0.0)
    {
        deg += 360.0;
    }
    return deg;
}

double DHUtility::RadIn2PI_(double rad)
{
    rad = fmod(rad, DX_TWO_PI);
    if (rad < 0.0)
    {
        rad += DX_TWO_PI;
    }
    return rad;
}

float DHUtility::DegIn360_(float deg)
{
    deg = fmodf(deg, 360.0f);
    if (deg < 0.0f)
    {
        deg += 360.0f;
    }
    return deg;
}

float DHUtility::RadIn2PI_(float rad)
{
    rad = fmodf(rad, DX_TWO_PI_F);
    if (rad < 0.0f)
    {
        rad += DX_TWO_PI_F;
    }
    return rad;
}

int DHUtility::Clamp_(int value, int min, int max)
{
    return std::max(std::min(value, max), min);
}

float DHUtility::Clamp_(float value, float min, float max)
{
    return std::max(std::min(value, max), min);
}

DHUtility& DHUtility::Instance(void)
{
    static DHUtility instance;
    return instance;
}

Vector3 DHUtility::VECToVec3(const VECTOR& vec)
{
    return Instance().VECToVec3_(vec);
}

VECTOR DHUtility::Vec3ToVEC(const Vector3& vec)
{
    return Instance().Vec3ToVEC_(vec);
}

float DHUtility::Rad2Deg(float rad)
{
    return Instance().Rad2Deg_(rad);
}

float DHUtility::Deg2Rad(float deg)
{
    return Instance().Deg2Rad_(deg);
}

float DHUtility::DirNearAroundRad(float from, float to)
{
    return Instance().DirNearAroundRad_(from,to);
}

float DHUtility::DirNearAroundDeg(float from, float to)
{
    return Instance().DirNearAroundDeg_(from, to);
}

double DHUtility::DegIn360(double deg)
{
    return Instance().DegIn360_(deg);
}

double DHUtility::RadIn2PI(double rad)
{
    return Instance().RadIn2PI_(rad);
}

float DHUtility::DegIn360(float deg)
{
    return Instance().DegIn360_(deg);
}

float DHUtility::RadIn2PI(float rad)
{
    return Instance().RadIn2PI_(rad);
}

int DHUtility::Clamp(int value, int min, int max)
{
    return Instance().Clamp_(value, min, max);
}

float DHUtility::Clamp(float value, float min, float max)
{
    return Instance().Clamp_(value, min, max);
}

DHUtility::DHUtility()
{
}
