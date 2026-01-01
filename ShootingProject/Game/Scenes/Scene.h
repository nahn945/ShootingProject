#pragma once
# include <Siv3D.hpp>
# include "../Player/Player.h"
# include "../Entity/Entity.h"
# include "../Loader/JsonLoader.h"

constexpr Vec2 SHOOTING_AREA_SIZE = {640, 896}; // 上下UI:32px 左右UI:320px

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
	double startTime;
	Config defaultConfig =
	{
		KeyLeft,
		KeyRight,
		KeyUp,
		KeyDown,
		KeyZ
	};

	Player player;

	JsonLoader jsonLoader;
	Array<std::unique_ptr<Entity>> entities;

	RectF shootingArea;

public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;
};
