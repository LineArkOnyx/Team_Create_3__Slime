#include "Player.h"
#include"../../../Collision/Collision.h"
#include"../../../Map/Map.h"
#define PLAYER_SPEED  (5);
#define PLAYER_GRAVITY_LIMIT	(10)
#define PLAYER_GRAVITY  (1);
#define PLAYER_JUNP		(28)
Player player;
Player::Player()
{
	PlayerPosX = 0;
	PlayerPosY = 0;
	PlayerNextPosX = 400;
	PlayerNextPosY = 0;
	PlayerWidth = 32;
	PlayerHeight = 32;
	PlayerImgHndl = -1;
	PlayerJumpPower = 0;
	Player_Gravity_Speed = 0;
	PlayerJumpFlg = true;
}
Player::~Player()
{

}
void Player::InitPlayer()
{
	PlayerImgHndl = LoadGraph("");
}
void Player::MovePlayer()
{
	//ジャンプ
	if (PlayerJumpFlg == true&&IsKeyPush(KEY_INPUT_W) || IsKeyPush(KEY_INPUT_SPACE))
	{
		Player_Gravity_Speed -= PLAYER_JUNP;
	}
	if (IsKeyRelease(KEY_INPUT_W) || IsKeyRelease(KEY_INPUT_SPACE))
	{
		PlayerJumpFlg = false;
	}
	if (IsKeyKeep(KEY_INPUT_A))
	{
		PlayerNextPosX -= PLAYER_SPEED;
	}
	if (IsKeyKeep(KEY_INPUT_D))
	{
		PlayerNextPosX += PLAYER_SPEED;
	}
}
void Player::GravityPlayer()
{
	Player_Gravity_Speed += PLAYER_GRAVITY;
	if (Player_Gravity_Speed >= PLAYER_GRAVITY_LIMIT)	//重力の上限を決める
	{
		PlayerNextPosY += PLAYER_GRAVITY_LIMIT;
		Player_Gravity_Speed = PLAYER_GRAVITY_LIMIT;
	}
	else	//上限行くまで入る
	{
		PlayerNextPosY += Player_Gravity_Speed;
	}

}
void Player::DrawPlayer()
{
	DrawRotaGraph(PlayerPosX, PlayerPosY, 1.0, 0.0, PlayerImgHndl, true);
	// デバッグ用のボックス
	/*DrawBox(PlayerPosX - PlayerWidth / 2, PlayerPosY - PlayerHeight / 2, PlayerPosX + PlayerWidth / 2, PlayerPosY + PlayerHeight / 2, GetColor(255, 255, 0), false);*/
}
void Player::FinPlayer()
{
	DeleteGraph(PlayerImgHndl);
}

void Player::SetJumpFlg(bool JumpFlg)
{
	PlayerJumpFlg = JumpFlg;
}
void Player::SetPlayerPos(int PosX, int PosY)
{
	PlayerPosX = PosX;
	PlayerPosY = PosY;
}
void Player::SetPlayerNextPos(int PosX, int PosY)
{
	PlayerNextPosX = PosX;
	PlayerNextPosY = PosY;
}

int Player::GetPosX()
{
	return PlayerPosX;
}
int Player::GetPosY()
{
	return PlayerPosY;
}
int Player::GetWidth()
{
	return PlayerWidth;
}
int Player::GetHeight()
{
	return PlayerHeight;
}
void Player::PlayerHitMapColision()
{
	// マップチップ表示処理
	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			// ★ここを考える
			// どの方向に進んでいたかチェック
			// ※Playerクラスに進む方向をチェックする関数を準備しています。

			bool dirArray[4] = { false,false,false,false };
			GetMoveDirection(dirArray);

			// ★ここを考える
			// 矩形の当たり判定用のデータを準備
			// プレイヤーの情報
			int Ax = PlayerPosX;
			int Ay = PlayerPosY;
			int Aw = PlayerWidth;
			int Ah = PlayerHeight;

			// オブジェクトの情報
			int Bx = x * 32;
			int By = y * 32;
			int Bw = MAPCHIP_SIZW;
			int Bh = MAPCHIP_SIZH;

			if (MapChipData1[y][x] == 0 /*|| MapChipData1[y][x] == 1 || MapChipData1[y][x] == 2 || MapChipData1[y][x] == 3 || MapChipData1[y][x] == 4*/)
			{
				DrawBox(Bx, By, Bx + Bw, By + Bh, GetColor(255, 255, 255), false);
				DrawBox(Ax, Ay, Ax + Aw, Ay + Ah, GetColor(255, 255, 255), false);
				// ※Y方向のみに移動したと仮定した座標で当たり判定をチェックします
				Ay = PlayerNextPosY;
				Ax = PlayerPosX;

				// 当たっているかチェック
				if (Collision::IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
					// 左方向の修正
					//マリオの左側
					if (dirArray[0]) {
						// ★ここを考える
						// めり込み量を計算する
						int overlap = By + Bh - Ay;
						PlayerNextPosY = (Ay + overlap);
					}
					// 右方向の修正
					//マリオの右側
					if (dirArray[1]) {
						// ★ここを考える
						// めり込み量を計算する
						PlayerJumpFlg = true;
						int overlap = Ay + Ah - By;
						PlayerNextPosY = (Ay - overlap);
					}
					
				}
			}
			
		}
	}
	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			// ★ここを考える
			// どの方向に進んでいたかチェック
			// ※Playerクラスに進む方向をチェックする関数を準備しています。

			bool dirArray[4] = { false,false,false,false };
			GetMoveDirection(dirArray);

			// ★ここを考える
			// 矩形の当たり判定用のデータを準備
			// プレイヤーの情報
			int Ax = PlayerPosX;
			int Ay = PlayerPosY;
			int Aw = PlayerWidth;
			int Ah = PlayerHeight;

			// オブジェクトの情報
			int Bx = x * 32;
			int By = y * 32;
			int Bw = MAPCHIP_SIZW;
			int Bh = MAPCHIP_SIZH;

			if (MapChipData1[y][x] == 0 /*|| MapChipData1[y][x] == 1 || MapChipData1[y][x] == 2 || MapChipData1[y][x] == 3 || MapChipData1[y][x] == 4*/)
			{
				Ay = PlayerPosY;
				Ax = PlayerNextPosX;
				if (Collision::IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh))
				{
					if (dirArray[2]) {
						// ★ここを考える
						// めり込み量を計算する
						int overlap = Bx + Bw - Ax;
						PlayerNextPosX = (Ax + overlap);
					}
					// 右方向の修正
					//マリオの右側
					if (dirArray[3]) {
						// ★ここを考える
						// めり込み量を計算する
						int overlap = Ax + Aw - Bx;
						PlayerNextPosX = (Ax - overlap);
					}
				}
			}
		}
	}
}
void Player::GetMoveDirection(bool* _dirArray)
{
	// 右方向のチェック
	if (PlayerNextPosX > PlayerPosX) {
		_dirArray[3] = true;
	}
	// 左方向のチェック
	if (PlayerNextPosX < PlayerPosX) {
		_dirArray[2] = true;
	}
	// 下方向のチェック
	if (PlayerNextPosY > PlayerPosY) {
		_dirArray[1] = true;
	}
	// 左方向のチェック
	if (PlayerNextPosY < PlayerPosY) {
		_dirArray[0] = true;
	}
}
void Player::UpdatePos()
{
	DrawFormatString(100, 30, GetColor(255, 0, 0), "kuribo.m_x = %d", PlayerPosX);
	DrawFormatString(100, 50, GetColor(255, 0, 0), "kuribo.m_x = %d", PlayerPosY);

	PlayerPosX = PlayerNextPosX;
	PlayerPosY = PlayerNextPosY;
}