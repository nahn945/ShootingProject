#pragma once

enum class PatternName
{
	SINGLE
};

class BulletPattern
{
	// 時間系
	double startTime;
	double endTime;

	// 生成系
	int amount;
	double radius;

	// 方向系
	double baseAngle;
	double gapAngle;
	double rotateSpeed;

public:
	BulletPattern(PatternName patternName);
	void patternSingle();
};
