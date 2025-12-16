# include "./Enemy.h"

Enemy::Enemy(Vec2 startPos)
	: HP(10)
	, pos(startPos)
{
	hitCircle.setCenter(pos);
	hitCircle.setR(HIT_SIZE);
}

void Enemy::update()
{
	isDead = HP <= 0;
}

void Enemy::draw() const
{
	hitCircle.draw(Palette::Orange);
}
