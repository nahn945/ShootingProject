#pragma once
#include <Siv3D.hpp>


struct EntityData
{
	int HP; // 敵の場合の体力
	int atk; // 与えるダメージ
	double siz; // 大きさ
	double spd; // 速さ
	Vec2 pos; // 出現位置
	double angle; // 発射角度
	double angularVelocity; // 角速度

	int moveID; // 移動パターンID
	double startTime; // 出現時間
	double endTime; // 撤退時間

	int atkID; // 攻撃パターンID
	double atkStartTime; // 開始時間
	double atkEndTime; // 終了時間

	double uniqueParam1;
	double uniqueParam2;
};
