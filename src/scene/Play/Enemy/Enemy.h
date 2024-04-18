#pragma once
#include"DxLib.h"
#include"iostream"

#define ENEMY_MAX_NUM (3)

class Enemy
{
private:
	int x[ENEMY_MAX_NUM], y[ENEMY_MAX_NUM], h, w, handle;
	bool IsUse;
public:
	void InitEnemy();
	void Stepenemy();
	void DrawEnemy();
};
extern Enemy enemy;