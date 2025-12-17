# include "./Bullet.h"

Bullet::Bullet(Vec2 startPos, double startAngle, BulletOwner starOwner)
	: pos(startPos)
	, angle(ToRadians(startAngle))
	, dir(0, 0)
	, owner(starOwner)
{
	hitCircle.setCenter(pos);
	hitCircle.setR(SIZE);
}

void Bullet::update()
{
	

	isOutSide = pos.y < 0;

	dir = { Cos(angle), Sin(angle) };
	velocity = dir * speed;

	pos += velocity;

	hitCircle.setCenter(pos);
}

void Bullet::draw() const
{
	hitCircle.draw(Palette::Blue);
}
