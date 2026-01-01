# include "./JsonLoader.h"

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

		// ===== status / atkStatus =====
		LoadStatus(set[U"status"], data.status);
		LoadStatus(set[U"atkStatus"], data.atkStatus);

		// ===== 移動 =====
		data.moveID = set[U"moveID"].get<int>();
		data.startTime = set[U"startTime"].get<double>();
		data.endTime = set[U"endTime"].get<double>();

		// ===== 攻撃 =====
		data.atkID = set[U"atkID"].get<int>();
		data.atkStartTime = set[U"atkStartTime"].get<double>();
		data.atkEndTime = set[U"atkEndTime"].get<double>();

		// ===== 固有パラメータ =====
		data.uniqueParam1 = set[U"uniqueParam1"].get<double>();
		data.uniqueParam2 = set[U"uniqueParam2"].get<double>();

		results.push_back(data);
	}

	return results;
}


void JsonLoader::LoadStatus(const JSON& json, EntityStatus& status)
{
	status.HP = json[U"HP"].get<int>();
	status.atk = json[U"atk"].get<int>();
	status.siz = json[U"siz"].get<double>();
	status.spd = json[U"spd"].get<double>();

	status.pos.x = json[U"pos"][U"x"].get<double>();
	status.pos.y = json[U"pos"][U"y"].get<double>();

	status.angle = json[U"angle"].get<double>();
	status.angularVelocity = json[U"angularVelocity"].get<double>();
}
