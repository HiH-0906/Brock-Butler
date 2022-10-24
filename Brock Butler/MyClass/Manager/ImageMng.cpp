#include <DxLib.h>
#include "ImageMng.h"

const std::vector<int>& ImageManager::GetID(const std::string& key)
{
	return GetID(key, key);
}

const std::vector<int>& ImageManager::GetID(const std::string& key, const std::string& fileName)
{
	// ‚·‚Å‚É‚ ‚é‚©Áª¯¸
	if (imgMap_.find(key) == imgMap_.end())
	{
		// ì¬
		imgMap_[key].resize(1);
		imgMap_[key][0] = LoadGraph(fileName.c_str(),true);
	}
	return imgMap_[key];
}

const std::vector<int>& ImageManager::GetID(const std::string& key, const std::string& fileName, const Vector2Int& divSize, const Vector2Int& divCnt)
{
	// ‚·‚Å‚É‚ ‚é‚©Áª¯¸
	if (imgMap_.find(key) == imgMap_.end())
	{
		// ì¬
		imgMap_[key].resize(static_cast<size_t>(divCnt.x) * divCnt.y);
		LoadDivGraph(fileName.c_str(), divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &imgMap_[key][0]);
	}
	return imgMap_[key];
}

ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
}
