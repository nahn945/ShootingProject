# include "./Scene.h"

Game::Game(const InitData& init)
	: IScene{ init }
	, shootingArea{Scene::CenterF() - SHOOTING_AREA_SIZE / 2, SHOOTING_AREA_SIZE}
{
	player.setConfig(defaultConfig);
	Scene::SetBackground(ColorF{0.6, 0.8, 0.7});

	for (auto& e : jsonLoader.load(U"../Data/debug.json"))
	{
		entities.push_back(std::make_unique<Entity>(e));
	}

	startTime = Scene::Time();
}

void Game::update()
{
	player.update();

	// ================================
	// entityの配置関連
	double t = Scene::Time() - startTime;

	Print << t;

	for (auto& e : entities)
	{
		if (t >= e->getStartTime() && t <= e->getEndTime())
		{
			e->update();
		}
	}

	

	// 削除（forの外で一括）
	entities.remove_if([t](const std::unique_ptr<Entity>& e)
	{
		return t > e->getEndTime();
	});
	// ================================

	Print << entities.size();
}

void Game::draw() const
{
	shootingArea.draw(Palette::Black);
	player.draw();

	double t = Scene::Time() - startTime;

	for (auto& e : entities)
	{
		if (t >= e->getStartTime() && t <= e->getEndTime())
		{
			e->draw();
		}
	}
}
