#pragma once
#include <utility>
#include <map>
#include <string>
#include <memory>
#include <vector>
#include "../common/Vector2.h"

using ImgMap = std::map<std::string, std::vector<int>>;

#define lpImageMng (ImageManager::GetInstance())
#define IMAGE_ID(KEY) (ImageManager::GetInstance().GetID(KEY))

class ImageManager
{
public:
	static ImageManager& GetInstance(void)
	{
		static ImageManager s_Instance;
		return s_Instance;
	};
	const std::vector<int>& GetID(const std::string& key);										// ?Q?[?????????p
	const std::vector<int>& GetID(const std::string& key, const std::string& fileName);			// ?ꖇ?G?p
	const std::vector<int>& GetID(const std::string& key, const std::string& fileName,			// ?????p
		const Vector2Int& divSize, const Vector2Int& divCnt);

private:
	ImgMap imgMap_;

	ImageManager();
	~ImageManager();
};

