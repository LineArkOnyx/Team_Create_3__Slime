#include "Play.h"

Play::Play()
{
	
}
Play::~Play()
{

}
void Play::InitPlay()
{
	player.InitPlayer();
	TimeLimit = 60 * 20;//タイムリミットをリセット
}
void Play::StepPlay()
{
	TimeLimit--;
	player.StepPlayer();

	if (player.GetPlayerAttack()) {
		DrawCircle(player.GetPlayerPosX(), player.GetPlayerPosY(), 100, GetColor(255, 255, 0), 1, 1);
		ClickCount++;
	}
	
	DrawFormatString(0, 60, GetColor(255, 127, 255), "SCORE : %d", Score);
	DrawFormatString(0, 80, GetColor(255, 127, 255), "TIME : %d", TimeLimit);
	DrawFormatString(0, 100, GetColor(255, 127, 255), "CLICK : %d", ClickCount);
	if (TimeLimit < 0) {
		sceneID = SCENE_INIT_RESULT;
	}
}
void Play::DrawPlay()
{
	player.DrawPlayer();
}
void Play::FinPlay()
{
	player.FinPlayer();
}

void Play::EnemyHitHammer()
{
	/*Collision::IsHitRect()*/
}