#pragma once
#include <Siv3D.hpp>


struct EntityData
{
	bool isInvincible; // 倒せるか trueで無敵
	int HP; // 敵の場合の体力
	int atk; // 与えるダメージ
	double siz; // 大きさ
	double spd; // 速さ
	Vec2 pos; // 出現位置
	double angle; // 発射角度
	double angularVelocity; // 角速度

	int ID; // 移動パターンID
	double startTime; // 出現時間
	double endTime; // 撤退時間
};
