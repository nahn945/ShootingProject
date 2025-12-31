# include "./Entity.h"

Entity::Entity(EntityData data_)
	: data(data_)
	, tmpCenter(data_.pos)
{
	data.angle = ToRadians(data_.angle);
	hitCircle.setCenter(data.pos);
	hitCircle.setR(data.siz);
}

void Entity::update()
{
	callMovePattern(data.moveID);
	hitCircle.setCenter(data.pos);
}

void Entity::draw() const
{
	hitCircle.draw(Palette::Green);
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
	Vec2 dir{ Cos(data.angle), Sin(data.angle) };

	data.pos += dir * data.spd * Scene::DeltaTime();
}

// uniqueParam1 = radius
void Entity::patternCircle()
{
	// 角度を進める
	data.angle += data.angularVelocity * Scene::DeltaTime();

	// 円運動
	data.pos.x = tmpCenter.x + Cos(data.angle) * data.uniqueParam1;
	data.pos.y = tmpCenter.y + Sin(data.angle) * data.uniqueParam1;
}

// uniqueParam1 = radius
// uniqueParam2 = arcStart/arcEnd
void Entity::patternArc()
{
	double arcStart = ToRadians(data.uniqueParam2);
	double arcEnd = ToRadians(180 - data.uniqueParam2);

	// 角度更新
	data.angle += data.angularVelocity * Scene::DeltaTime();

	// 端に到達したら反転
	if (data.angle >= arcEnd)
	{
		data.angle = arcEnd;
		data.angularVelocity *= -1;
	}
	else if (data.angle <= arcStart)
	{
		data.angle = arcStart;
		data.angularVelocity *= -1;
	}

	// 弧運動
	data.pos.x = tmpCenter.x + Cos(data.angle) * data.uniqueParam1;
	data.pos.y = tmpCenter.y + Sin(data.angle) * data.uniqueParam1;
}
