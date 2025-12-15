#pragma once
# include <Siv3D.hpp>

struct Config
{
	Input Left;
	Input Right;
	Input Up;
	Input Down;
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
public:
	Player();
	void update();
	void draw() const;

	void movePos();

	inline void setConfig(Config config_) { playerConfig = config_; }
	inline Vec2 getPos() { return pos; }
	inline Circle getHitCircle() { return hitCircle; }
};
