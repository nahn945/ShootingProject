#pragma once
# include "../Bullets/Bullet.h"

class Enemy
{
private:
	int HP;
	Vec2 pos;
	const int HIT_SIZE = 10;
	Circle hitCircle;

	bool isDead = false;
public:
	Enemy(Vec2 startPos);
	void update();
	void draw() const;

	inline void damage(int value) { HP -= value; }
	bool getIsDead() const { return isDead; }
	Circle getHitCircle() const { return hitCircle; }
};
