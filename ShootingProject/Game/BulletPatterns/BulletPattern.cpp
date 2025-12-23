# include "./BulletPattern.h"

BulletPattern::BulletPattern(PatternName patternName)
{
	switch (patternName)
	{
	case PatternName::SINGLE:
		break;
	default:
		break;
	}
}

void BulletPattern::patternSingle()
{
	double time = Scene::Time();

	// 有効時間外なら何もしない
	if (time < startTime || time > endTime)
		return;

	// 時間経過による回転を反映
	double angle = baseAngle
		+ rotateSpeed * (time - startTime);

	// 発射方向
	Vec2 dir{ Cos(angle), Sin(angle) };
}
