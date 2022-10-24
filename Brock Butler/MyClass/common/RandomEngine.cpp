#include "RandomEngine.h"

RandomEngine::RandomEngine()
{
	engine = std::make_unique<std::mt19937>(rd());
}

RandomEngine& RandomEngine::Instance()
{
	static RandomEngine instance;
	return instance;
}


int RandomEngine::RandomInt_(int min, int max)
{
	std::uniform_int_distribution<int> dist(min,max);
	return dist(*engine);
}


float RandomEngine::RandomFloat_(float min, float max)
{
	std::uniform_real_distribution<float> dist(min, max);
	return dist(*engine);
}

double RandomEngine::RandomDouble_(double min, double max)
{
	std::uniform_real_distribution<double> dist(min, max);
	return dist(*engine);
}

double RandomEngine::RandomDouble(double min, double max)
{
	return Instance().RandomDouble_(min, max);
}

float RandomEngine::RandomFloat(float min, float max)
{
	return Instance().RandomFloat_(min,max);
}

int RandomEngine::RandomInt(int min, int max)
{
	return Instance().RandomInt_(min,max);
}
