#pragma once
# include <Siv3D.hpp>
# include "../Player/Player.h"

#define SHOOTING_INTERVAL 0.5

using App = SceneManager<String>;

// タイトルシーン
class Title : public App::Scene
{
public:
	Title(const InitData& init);
	void update() override;
	void draw() const override;
};

// ゲームシーン
class Game : public App::Scene
{
private:
	Config defaultConfig =
	{
		KeyLeft,
		KeyRight,
		KeyUp,
		KeyDown,
		KeyZ
	};

	Player player;
	Array<std::unique_ptr<Bullet>> bullets;
	double shootingInterval;

public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;
};
