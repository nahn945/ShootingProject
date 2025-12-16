# include "./Player.h"

Player::Player()
	: pos(Scene::CenterF())
	, isShooting(false)
{
	hitCircle.setCenter(pos);
	hitCircle.setR(HIT_SIZE);
}

void Player::update()
{
	velocity = Vec2{ 0,0 };
	movePos();
	hitCircle.setCenter(pos);

}

void Player::draw() const
{
	hitCircle.draw(Palette::Red);
}

void Player::movePos()
{
	Vec2 unit = { 0,0 };
	if (playerConfig.Left.pressed()) unit.x = -1;
	if (playerConfig.Right.pressed()) unit.x = 1;
	if (playerConfig.Up.pressed()) unit.y = -1;
	if (playerConfig.Down.pressed()) unit.y = 1;

	if (unit.lengthSq() > 0)
	{
		velocity = unit.normalized();
	}
	else
	{
		velocity = Vec2{ 0,0 };
	}
	pos += velocity * speed;
	isShooting = playerConfig.Attack.pressed();
}
