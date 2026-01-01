#pragma once
# include "../Data/EntityData.h"

class Entity
{
	EntityData data;
	Vec2 tmpCenter;
	double tmpAngle;
	Circle hitCircle;
	double previousAtk = 0;
public:
	Entity(EntityData data_);
	Entity(EntityStatus status_, int ID);

	void update();
	void draw() const;

	inline double getStartTime() const { return data.startTime; }
	inline double getEndTime() const { return data.endTime; }

	inline double getAtkStartTime() const { return data.atkStartTime; }
	inline double getAtkEndTime() const { return data.atkEndTime; }
	inline int getAtkID() const { return data.atkID; }
	inline double getPreATK() const { return previousAtk; }

	inline void setPreATK(double t) { previousAtk = t; }

	Array<std::unique_ptr<Entity>> callAttackPattern(int ID);
	Array<std::unique_ptr<Entity>> attackSingle();
	Array<std::unique_ptr<Entity>> attackCircle();
	Array<std::unique_ptr<Entity>> attackRotation();
	Array<std::unique_ptr<Entity>> attackNWay();
	void callMovePattern(int ID);
	void patternSingle();
	void patternCircle();
	void patternArc();
};
