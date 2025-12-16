#pragma once
# include <Siv3D.hpp>
# include "../Player/Player.h"

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
		KeyDown
	};

	Player player;
public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;
};
