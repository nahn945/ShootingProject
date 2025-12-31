#pragma once
# include "../Data/EntityData.h"

class Entity
{
	EntityData data;
	Circle hitCircle;
public:
	Entity(EntityData data_);
	void update();
	void draw() const;

	inline double getStartTime() const { return data.startTime; }
	inline double getEndTime() const { return data.endTime; }
};
