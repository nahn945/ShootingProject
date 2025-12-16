#pragma once

class Bullet
{
private:
	Vec2 pos;
	double speed = 30;
	const double SIZE = 10;
	int attackPow = 1; // 攻撃力
	Circle hitCircle;
	bool isOutSide = false;
	bool isActive = true;
	bool isPierce = false; // 貫通弾かどうか

public:
	Bullet(Vec2 startPos);
	void update();
	void draw() const;

	inline void setIsActiveFalse() { isActive = false; }

	inline int getAttackPow() const { return attackPow; }
	inline bool getIsPierce() const { return isPierce; }
	inline Vec2 getPos() const { return pos; }
	inline bool getIsActive() const { return isActive; }
	inline Circle getHitCircle() const { return hitCircle; }
	inline bool getIsOutSide() const { return isOutSide; }
};
