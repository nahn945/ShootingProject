# include "./Scene.h"

Game::Game(const InitData& init)
	: IScene{ init }
	, shootingArea{Scene::CenterF() - SHOOTING_AREA_SIZE / 2, SHOOTING_AREA_SIZE}
{
	player.setConfig(defaultConfig);
	Scene::SetBackground(ColorF{0.6, 0.8, 0.7});

	// デバッグ用の敵
	enemies.push_back(std::make_unique<Enemy>(Vec2{ Scene::CenterF().x, Scene::CenterF().y - 200 }));
}

void Game::update()
{
	
	if (player.getIsShooting() && player.getShootingInterval() > player.getMaxInterval())
	{
		bullets.push_back(std::make_unique<Bullet>(player.getPos(), -90, BulletOwner::PLAYER));
		player.resetShootingInterval();
	}

	for (auto& e : enemies)
	{
		e->update();
		if (e->getShootingInterval() > e->getMaxInterval())
		{
			// bulletAddedTemporarily
			bullets.push_back(std::make_unique<Bullet>(e->getPos(), 90, BulletOwner::ENEMY));
			if (e->getMaxInterval() != 100)
			{
				e->setMaxInterval(100);
			}
			e->resetShootingInterval();
		}
	}

	for (auto& b : bullets)
	{
		b->update();
	}

	// 敵と弾、弾とプレイヤーの接触判定
	for (auto& b : bullets)
	{
		if (!b->getIsActive())
			continue;

		for (auto& e : enemies)
		{
			if (e->getIsDead())
				continue;

			if (e->getHitCircle().intersects(b->getHitCircle()) && b->getOwner() == BulletOwner::PLAYER)
			{
				e->damage(b->getAttackPow());

				if (!b->getIsPierce())
				{
					b->setIsActiveFalse();
					break;
				}
			}

		}

		if (b->getHitCircle().intersects(player.getHitCircle()) && b->getOwner() == BulletOwner::ENEMY)
		{
			player.damage(b->getAttackPow());

			Print << player.getHP();

			if (!b->getIsPierce())
			{
				b->setIsActiveFalse();
				break;
			}
		}
	}


	bullets.remove_if([](const std::unique_ptr<Bullet>& b)
	{
		return b->getIsOutSide() || !b->getIsActive();
	});

	enemies.remove_if([](const std::unique_ptr<Enemy>& e)
	{
		return e->getIsDead();
	});

	player.update();

	//Print << bullets.size();
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
