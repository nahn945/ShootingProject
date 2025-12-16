# include "./Scene.h"

Game::Game(const InitData& init)
	: IScene{ init }
{
	player.setConfig(defaultConfig);
	shootingInterval = 0.0;
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
	player.draw();
	for (auto& b : bullets)
	{
		b->draw();
	}
}
