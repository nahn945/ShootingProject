#pragma once
# include <Siv3D.hpp>

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
public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;
};
