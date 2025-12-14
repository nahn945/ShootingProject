# include "./Scene.h"

Game::Game(const InitData& init)
	: IScene{ init }
{

}

void Game::update()
{
	Print << U"This is the Game scene";
}

void Game::draw() const
{

}
