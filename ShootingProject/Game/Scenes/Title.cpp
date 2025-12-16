# include "./Scene.h"

Title::Title(const InitData& init)
	: IScene{ init }
{

}

void Title::update()
{
	Print << U"This is the Title Scene";

	if (KeyEnter.down()) changeScene(U"Game");
}

void Title::draw() const
{

}
