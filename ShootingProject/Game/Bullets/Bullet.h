#pragma once

class Bullet
{
private:
	Vec2 pos;
	double speed;
	const double SIZE = 10;

public:
	Bullet(Vec2 startPos);
	void update();
	void draw() const;
};
