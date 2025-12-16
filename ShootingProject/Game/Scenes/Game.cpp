# include "./Scene.h"

Game::Game(const InitData& init)
	: IScene{ init }
{
	player.setConfig(defaultConfig);
}

void Game::update()
{
	//Print << U"This is the Game scene";
	player.update();
}

void Game::draw() const
{
	player.draw();
}
