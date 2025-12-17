#pragma once

class Enemy
{
private:
	int HP;
	Vec2 pos;
	const int HIT_SIZE = 10;
	Circle hitCircle;

	bool isDead = false;

	int attackIndex = 0;
	double shootingInterval = 0.0; // １弾幕発射後の経過時間
	double maxInterval = 1.0; // 経過時間がいつの時に弾幕を発射するか
public:
	Enemy(Vec2 startPos);
	void update();
	void draw() const;

	inline void damage(int value) { HP -= value; }
	inline void resetShootingInterval() { shootingInterval = 0.0; }
	inline void setMaxInterval(double x) { maxInterval = x; }

	inline double getMaxInterval() const { return maxInterval; }
	inline double getShootingInterval() const { return shootingInterval; }
	inline bool getIsDead() const { return isDead; }
	inline Circle getHitCircle() const { return hitCircle; }
	inline int getAttackIndex() const { return attackIndex; }
	inline Vec2 getPos() const { return pos; }
};
