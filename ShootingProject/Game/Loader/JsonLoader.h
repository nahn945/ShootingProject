#pragma once
# include "../Data/EntityData.h"

class JsonLoader
{
public:
	Array<EntityData> load(const FilePath& path);
	void LoadStatus(const JSON& json, EntityStatus& status);
};
