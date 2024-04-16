#include"Enemy.h"
#include"iostream"
#include"DxLib.h"
#include"../../Collision/Collision.h"
#include"../Play/Player/Player.h"
#include"../Play/Play.h"
#include"../../Common.h"
Enemy enemy;
void Enemy::InitEnemy()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		x[i] = GetRand(SCREEN_SIZE_X - 64);
		y[i] = GetRand(SCREEN_SIZE_Y - 64);
	}
	h = 64;
	w = 64;

	IsUse = false;
}
void Enemy::Stepenemy()
{
	Enemy_Hit_Hanmmer();
}
void Enemy::DrawEnemy()
{
	
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		DrawRotaGraph(x[0], y[0], 1.0, 0.0, handle, true);
	}
}
void Enemy::Enemy_Hit_Hanmmer()
{
	
	DrawBox(player.GetPlayerPosX(), player.GetPlayerPosY(), player.GetPlayerPosX() + player.GetPlayerPosH(), player.GetPlayerPosY() + player.GetPlayerPosW(), GetColor(255, 255, 255), true);
	for (int i = 0; i < ENEMY_MAX_NUM; i++) {
		DrawBox(x[i], y[i], x[i] + h, y[i] + w, GetColor(255, 255, 255), true);
		if (Collision::IsHitRect(x[i], y[i], h, w, player.GetPlayerPosX(), player.GetPlayerPosY(), player.GetPlayerPosH(), player.GetPlayerPosW()) && player.GetPlayerAttack())
		{
			DrawFormatString(100, 100, GetColor(255, 255, 255), "ƒqƒbƒg");
			x[i] = GetRand(SCREEN_SIZE_X - 64);
			y[i] = GetRand(SCREEN_SIZE_Y - 64);
			Score++;
		}
	}
}