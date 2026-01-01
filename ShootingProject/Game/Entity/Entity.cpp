# include "./Entity.h"

Entity::Entity(EntityData data_)
	: data(data_)
	, tmpCenter(data_.status.pos)
{
	data.status.angle = ToRadians(data_.status.angle);
	hitCircle.setCenter(data.status.pos);
	hitCircle.setR(data.status.siz);
}

Entity::Entity(EntityStatus status_, int ID)
{
	data.status = status_;
	data.moveID = ID;
	data.atkID = 0;
	data.startTime = 0;
	data.endTime = 999;

	tmpCenter = status_.pos;

	data.status.angle = ToRadians(status_.angle);
	hitCircle.setCenter(status_.pos);
	hitCircle.setR(status_.siz);
}


void Entity::update()
{
	callMovePattern(data.moveID);
	hitCircle.setCenter(data.status.pos);
}

void Entity::draw() const
{
	hitCircle.draw(Palette::Green);
}

Array<std::unique_ptr<Entity>> Entity::callAttackPattern(int ID)
{

	switch (ID)
	{
	case 0:
		// 何もしない
		return {};

	case 1:
		// 直進弾単発
		return attackSingle();

	case 2:
		// 回転弾任意個数
		return attackCircle();

	case 3:
		return attackRotation();

	case 4:
		return attackNWay();

	default:
		return {};
	}
}

Array<std::unique_ptr<Entity>> Entity::attackSingle()
{
	Array<std::unique_ptr<Entity>> bullets;

	EntityStatus status = data.atkStatus;
	status.pos = data.status.pos;

	bullets.push_back(
		std::make_unique<Entity>(status, 1)
	);

	return bullets;
}



// atkStatusのHPが発射個数と見る
Array<std::unique_ptr<Entity>> Entity::attackCircle()
{
	Array<std::unique_ptr<Entity>> bullets;

	const int count = data.atkStatus.HP;
	const Vec2 centerPos = data.status.pos;
	const double baseAngle = data.atkStatus.angle;

	for (int i = 0; i < count; i++)
	{
		EntityStatus status = data.atkStatus;

		status.pos = centerPos;
		status.angle = ToDegrees(baseAngle + (Math::TwoPi * i / count));

		bullets.push_back(
			std::make_unique<Entity>(status, 1)
		);
	}

	return bullets;
}



Array<std::unique_ptr<Entity>> Entity::attackRotation()
{
	Array<std::unique_ptr<Entity>> bullets;

	const double baseAngle = data.atkStatus.angle;

	// 回転用に基準角を進める
	data.atkStatus.angle += data.atkStatus.angularVelocity * Scene::DeltaTime();

	const int count = data.atkStatus.HP;
	const Vec2 centerPos = data.status.pos;
	

	// attackCircleの処理の一部変更
	Array<std::unique_ptr<Entity>> bulletsTmp;

	for (int i = 0; i < count; i++)
	{
		EntityStatus status = data.atkStatus;

		status.pos = centerPos;
		status.angle = ToDegrees(baseAngle + (Math::TwoPi * i / count));

		bulletsTmp.push_back(
			std::make_unique<Entity>(status, 1)
		);
	}

	for (auto& b : bulletsTmp)
	{
		bullets.push_back(std::move(b));
	}

	return bullets;
}

Array<std::unique_ptr<Entity>> Entity::attackNWay()
{
	Array<std::unique_ptr<Entity>> bullets;

	const int count = data.atkStatus.HP;
	if (count <= 0)
	{
		return bullets;
	}

	const Vec2 centerPos = data.status.pos;

	const double baseAngle = data.atkStatus.angle;      // ラジアン
	const double interval = ToRadians(15.0);            // 15度間隔

	// 扇形の開始角
	const double startAngle =
		baseAngle - interval * (count - 1) * 0.5;

	for (int i = 0; i < count; i++)
	{
		EntityStatus status = data.atkStatus;

		status.pos = centerPos;
		status.angle = ToDegrees(startAngle + interval * i);

		bullets.push_back(
			std::make_unique<Entity>(status, 1) // 直進弾
		);
	}

	return bullets;
}


void Entity::callMovePattern(int ID)
{
	switch (ID)
	{
	case 0:
		// 何もしない
		break;

	case 1:
		// 直進
		patternSingle();
		break;

	case 2:
		// 指定の座標中心に回転
		patternCircle();
		break;

	case 3:
		// 指定の座標中心に弧を描く
		patternArc();
		break;

	default:
		break;
	}
}

void Entity::patternSingle()
{
	Vec2 dir{ Cos(data.status.angle), Sin(data.status.angle) };

	data.status.pos += dir * data.status.spd * Scene::DeltaTime();
}

// uniqueParam1 = radius
void Entity::patternCircle()
{
	// 角度を進める
	data.status.angle += data.status.angularVelocity * Scene::DeltaTime();

	// 円運動
	data.status.pos.x = tmpCenter.x + Cos(data.status.angle) * data.uniqueParam1;
	data.status.pos.y = tmpCenter.y + Sin(data.status.angle) * data.uniqueParam1;
}

// uniqueParam1 = radius
// uniqueParam2 = arcStart/arcEnd
void Entity::patternArc()
{
	double arcStart = ToRadians(data.uniqueParam2);
	double arcEnd = ToRadians(180 - data.uniqueParam2);

	// 角度更新
	data.status.angle += data.status.angularVelocity * Scene::DeltaTime();

	// 端に到達したら反転
	if (data.status.angle >= arcEnd)
	{
		data.status.angle = arcEnd;
		data.status.angularVelocity *= -1;
	}
	else if (data.status.angle <= arcStart)
	{
		data.status.angle = arcStart;
		data.status.angularVelocity *= -1;
	}

	// 弧運動
	data.status.pos.x = tmpCenter.x + Cos(data.status.angle) * data.uniqueParam1;
	data.status.pos.y = tmpCenter.y + Sin(data.status.angle) * data.uniqueParam1;
}
