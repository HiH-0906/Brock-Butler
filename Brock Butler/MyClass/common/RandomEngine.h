#pragma once
#include <random>
#include <memory>

class RandomEngine
{
private:
	std::random_device rd;
	std::unique_ptr<std::mt19937> engine;

	// 生成禁止
	RandomEngine();

	// コピー、代入禁止
	RandomEngine(const RandomEngine&) = delete;
	void operator=(const RandomEngine&) = delete;
	int RandomInt_(int min, int max);
	float RandomFloat_(float min, float max);
	double RandomDouble_(double min, double max);
	static RandomEngine& Instance();

public:
	static double RandomDouble(double min, double max);
	static float RandomFloat(float min, float max);
	static int RandomInt(int min, int max);
};