#pragma once
# include "../Bullets/Bullet.h"

class BulletPattern
{
public:
	virtual ~BulletPattern() = default;
	virtual void update(Bullet& b, double dt) = 0;
};

class SinglePattern : public BulletPattern
{
public:
	void update(Bullet& b, double dt) override;
};
