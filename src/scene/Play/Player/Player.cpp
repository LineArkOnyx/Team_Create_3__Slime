#include "Player.h"
#include "../../../Common.h"

Player player;
Player::Player()
{
	PlayerPosH = 8, PlayerPosW = 8;//HとWを初期化^\^
	PlayerPosX = PlayerPosY = 0;	//プレイヤーの座標
	PlayerIdleHndl = PlayerAttackHndl = 0;	//プレイヤーの画像ハンドル
	CurrentClickFlg = NextClickFlg = 0;//左クリックされているかを感知する
}
Player::~Player()
{

}
void Player::InitPlayer()
{
	PlayerPosX = SCREEN_SIZE_X / 2; 
	PlayerPosY = SCREEN_SIZE_Y / 2;//プレイヤーの初期座標セット
	SetMousePoint(PlayerPosX, PlayerPosY);//プレイヤーに伴って
	PlayerIdleHndl = LoadGraph(""); //プレイヤーの画像読み込み <-- 後で
	PlayerAttackHndl = LoadGraph("");
}
void Player::StepPlayer()
{

	CurrentClickFlg = NextClickFlg;	//カレントを更新

	GetMousePoint(&PlayerPosX, &PlayerPosY);//マウスポインタの位置にプレイヤー配置

	NextClickFlg = GetMouseInput() & MOUSE_INPUT_LEFT;//左クリックを検知

	if (NextClickFlg != 0 && CurrentClickFlg == 0){	// 今フレームで押されているかつ前フレームで押されていない
		AttackFlg = true;	//叩く
	}
	else {	//当てはまらない(押されてない、または押し続けている場合)
		AttackFlg = false;	//叩かない
	}
}
void Player::DrawPlayer()
{
	if (NextClickFlg != 0) {	//押され続けている場合
		DrawGraph(PlayerPosX, PlayerPosY, PlayerAttackHndl, true);	//攻撃中の画像表示
	}
	else {
		DrawGraph(PlayerPosX, PlayerPosY, PlayerIdleHndl, true);	//待機画像表示
	}
	DrawFormatString(0, 0, GetColor(255, 255, 0), "X : %d Y : %d\nclick C: %d N: %d\nATK : %d",PlayerPosX,PlayerPosY,CurrentClickFlg,NextClickFlg, AttackFlg);
}
void Player::FinPlayer()
{
	DeleteGraph(PlayerAttackHndl);
	DeleteGraph(PlayerIdleHndl);
}

bool Player::GetPlayerAttack()	//叩くフラグを取得
{
	return AttackFlg;
}
int Player::GetPlayerPosX()	//座標取得
{
	return PlayerPosX;
}
int Player::GetPlayerPosY()	//座標取得
{
	return PlayerPosY;
}
int Player::GetPlayerPosH()
{
	return PlayerPosH;
}
int Player::GetPlayerPosW()
{
	return PlayerPosW;
}