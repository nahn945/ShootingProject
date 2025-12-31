#include "./JsonLoader.h"

// パスは.exeの実行ディレクトリ基準
Array<EntityData> JsonLoader::load(const FilePath& path)
{
	JSON json = JSON::Load(path);
	if (!json)
	{
		throw Error{ U"Failed to load json: " + path };
	}

	Array<EntityData> results;

	for (const auto& set : json[U"entities"].arrayView())
	{
		EntityData data;

		data.isInvincible = set[U"isInvincible"].get<bool>();
		data.HP = set[U"HP"].get<int>();
		data.atk = set[U"atk"].get<int>();
		data.siz = set[U"siz"].get<double>();
		data.spd = set[U"spd"].get<double>();

		data.pos.x = set[U"pos"][U"x"].get<double>();
		data.pos.y = set[U"pos"][U"y"].get<double>();

		data.angle = set[U"angle"].get<double>();
		data.angularVelocity = set[U"angularVelocity"].get<double>();

		data.ID = set[U"ID"].get<int>();
		data.startTime = set[U"startTime"].get<double>();
		data.endTime = set[U"endTime"].get<double>();

		results.push_back(data);
	}

	return results;
}
