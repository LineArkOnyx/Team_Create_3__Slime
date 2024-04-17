#include "Player.h"


Player player;
Player::Player()
{
	PlayerPosX = 0;
	PlayerPosY = 0;
	PlayerWidth = 32;
	PlayerHeight = 32;
	PlayerImgHndl = -1;
	PlayerJumpPower = 0;
	PlayerJumpFlg = true;
}
Player::~Player()
{

}
void Player::InitPlayer()
{
	PlayerImgHndl = LoadGraph("");
}
void Player::StepPlayer()
{
	PlayerJumpPower -= GRAVITY;		//�W�����v�͂��d�͂Ō��Z
	if (PlayerJumpFlg) {
		PlayerJumpPower = 0;		//�ڒn���Ă����Y���ړ���0��
	}
	if (IsKeyDown(KEY_INPUT_W) == 1 || IsKeyDown(KEY_INPUT_UP) == 1) {
		PlayerJumpPower = 16;		//�W�����v�����u�Ԃɐڒn�t���O��܂�
		PlayerJumpFlg = false;
	}
	if (IsKeyDown(KEY_INPUT_A) == 1 || IsKeyDown(KEY_INPUT_LEFT) == 1) {
		PlayerPosX += 2;
	}
	if (IsKeyDown(KEY_INPUT_D) == 1 || IsKeyDown(KEY_INPUT_RIGHT) == 1) {
		PlayerPosX -= 2;
	}
	PlayerPosY += PlayerJumpPower;	//Y���ړ����m��
}
void Player::DrawPlayer()
{
	DrawRotaGraph(PlayerPosX, PlayerPosY, 1.0, 0.0, PlayerImgHndl, true);
	// �f�o�b�O�p�̃{�b�N�X
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