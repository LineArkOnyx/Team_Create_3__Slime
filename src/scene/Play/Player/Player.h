#pragma once
#include "DxLib.h"
#include "../../../Input/Input.h"
#include "../../../Common.h"

class Player 
{
private:
	int PlayerPosX, PlayerPosY;		// 座標
	int PlayerWidth, PlayerHeight;	//プレイヤーのサイズ
	int PlayerImgHndl;				// 画像ハンドル
	int PlayerJumpPower;			// ジャンプ力
	bool PlayerJumpFlg;				// ジャンプの可否(接地フラグ)

public:
	Player();
	~Player();
	void InitPlayer();
	void StepPlayer();
	void DrawPlayer();
	void FinPlayer();
	
	void SetJumpFlg(bool JumpFlg);	//主にマップチップとの当たり判定で接地したときに使う
	
	int GetPosX();		//プレイヤーのX座標
	int GetPosY();		//プレイヤーのY座標
	int GetWidth();		//プレイヤーの横幅
	int GetHeight();	//プレイヤーの高さ
};

extern Player player;