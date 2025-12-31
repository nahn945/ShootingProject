#pragma once
# include "../Data/EntityData.h"

class JsonLoader
{
public:
	Array<EntityData> load(const FilePath& path);
};
