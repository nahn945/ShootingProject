# include "./Bullet.h"

Bullet::Bullet(Vec2 startPos)
	: pos(startPos)
{
	hitCircle.setCenter(pos);
	hitCircle.setR(SIZE);
}

void Bullet::update()
{
	pos.y -= speed;

	isOutSide = pos.y < 0;

	hitCircle.setCenter(pos);
}

void Bullet::draw() const
{
	hitCircle.draw(Palette::Blue);
}
