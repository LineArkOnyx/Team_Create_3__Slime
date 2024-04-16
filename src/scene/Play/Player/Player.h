#pragma once
#include "DxLib.h"

class Player 
{
public:
	Player();
	~Player();
	void InitPlayer();
	void StepPlayer();
	void DrawPlayer();
	void FinPlayer();
	bool GetPlayerAttack();	//叩くフラグを取得
	int GetPlayerPosX();	//座標取得
	int GetPlayerPosY();	//座標取得
	int GetPlayerPosH();	//座標取得
	int GetPlayerPosW();	//座標取得

private:
	int PlayerPosH, PlayerPosW;	//プレイヤーの座標^\^
	int PlayerPosX,PlayerPosY;	//プレイヤーの座標
	int PlayerIdleHndl;	//プレイヤーの画像ハンドル(待機)
	int PlayerAttackHndl;	//プレイヤーの画像ハンドル(攻撃)
	int CurrentClickFlg, NextClickFlg;	//左クリックされているかを感知する
	bool AttackFlg;	//モグラを叩くフラグ

};

extern Player player;