# include "./Scene.h"

Game::Game(const InitData& init)
	: IScene{ init }
	, shootingArea{Scene::CenterF() - SHOOTING_AREA_SIZE / 2, SHOOTING_AREA_SIZE}
{
	player.setConfig(defaultConfig);
	shootingInterval = 0.0;
	Scene::SetBackground(ColorF{0.6, 0.8, 0.7});

	// デバッグ用の敵
	enemies.push_back(std::make_unique<Enemy>(Vec2{ Scene::CenterF().x, Scene::CenterF().y - 200 }));
}

void Game::update()
{
	//Print << U"This is the Game scene";
	
	if (player.getIsShooting() && shootingInterval > SHOOTING_INTERVAL)
	{
		bullets.push_back(std::make_unique<Bullet>(player.getPos()));
		shootingInterval = 0.0;
	}

	for (auto& b : bullets)
	{
		b->update();
	}

	for (auto& e : enemies)
	{
		e->update();
	}

	bullets.remove_if([](const std::unique_ptr<Bullet>& b)
	{
		return b->getIsOutSide();
	});

	player.update();

	shootingInterval += 0.1;

	Print << bullets.size();
}

void Game::draw() const
{
	shootingArea.draw(Palette::Black);
	player.draw();
	for (auto& b : bullets)
	{
		b->draw();
	}

	for (auto& e: enemies)
	{
		e->draw();
	}
}
