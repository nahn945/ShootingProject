#pragma once
# include <Siv3D.hpp>
# include "../Bullets/Bullet.h"

struct Config
{
	Input Left;
	Input Right;
	Input Up;
	Input Down;
	Input Attack;
};

class Player
{
private:
	
	Config playerConfig;

	/*
	* ====================
	* 移動関連
	* ====================
	*/

	Vec2 pos;
	Vec2 velocity; // 移動処理内で逐次変更される
	double speed = 10; // 処理内で変更されない(定数ではない)

	/* 
	* ====================
	* 当たり判定関連
	* ====================
	*/
	const int HIT_SIZE = 10;
	Circle hitCircle;

	/*
	* ====================
	* 攻撃関連
	* ====================
	*/
	bool isShooting;

public:
	Player();
	void update();
	void draw() const;

	void movePos();

	inline void setConfig(Config config_) { playerConfig = config_; }

	inline Vec2 getPos() const { return pos; }
	inline Circle getHitCircle() const { return hitCircle; }
	inline bool getIsShooting() const { return isShooting; }
};
