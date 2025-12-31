# include "./Entity.h"

Entity::Entity(EntityData data_)
	: data(data_)
{
	hitCircle.setCenter(data.pos);
	hitCircle.setR(data.siz);
}

void Entity::update()
{
	hitCircle.setCenter(data.pos);
}

void Entity::draw() const
{
	hitCircle.draw(Palette::Green);
}
