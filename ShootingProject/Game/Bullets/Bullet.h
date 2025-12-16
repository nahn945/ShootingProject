#pragma once

class Bullet
{
private:
	Vec2 pos;
	double speed = 30;
	const double SIZE = 10;
	Circle hitCircle;
	bool isOutSide = false;

public:
	Bullet(Vec2 startPos);
	void update();
	void draw() const;

	inline Vec2 getPos() const { return pos; }
	inline bool getIsOutSide() const { return isOutSide; }
};
