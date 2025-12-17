#pragma once

enum class BulletOwner
{
	PLAYER,
	ENEMY
};

class Bullet
{
private:
	BulletOwner owner;
	Vec2 pos;
	double speed = 30;
	double angle = 0;
	Vec2 dir; // 単位ベクトル
	Vec2 velocity; //移動ベクトル
	const double SIZE = 10;
	int attackPow = 1; // 攻撃力
	Circle hitCircle;
	bool isOutSide = false;
	bool isActive = true;
	bool isPierce = false; // 貫通弾かどうか

public:
	Bullet(Vec2 startPos, double startAngle, BulletOwner startOwner);
	void update();
	void draw() const;

	inline void setIsActiveFalse() { isActive = false; }
	inline void setAngle(double value) { angle = value; }

	inline BulletOwner getOwner() const { return owner; }
	inline int getAttackPow() const { return attackPow; }
	inline bool getIsPierce() const { return isPierce; }
	inline Vec2 getPos() const { return pos; }
	inline bool getIsActive() const { return isActive; }
	inline Circle getHitCircle() const { return hitCircle; }
	inline bool getIsOutSide() const { return isOutSide; }
};
