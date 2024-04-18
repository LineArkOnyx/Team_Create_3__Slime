#include "Player.h"
#include"../../../Collision/Collision.h"
#include"../../../Map/Map.h"
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
	PlayerNextPosY += PlayerJumpPower;	//Y���ړ����m��
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
	// �}�b�v�`�b�v�\������
	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			// ���������l����
			// �ǂ̕����ɐi��ł������`�F�b�N
			// ��Player�N���X�ɐi�ޕ������`�F�b�N����֐����������Ă��܂��B

			bool dirArray[4] = { false,false,false,false };
			GetMoveDirection(dirArray);

			// ���������l����
			// ��`�̓����蔻��p�̃f�[�^������
			// �v���C���[�̏��
			int Ax = PlayerPosX;
			int Ay = PlayerPosY;
			int Aw = PlayerWidth;
			int Ah = PlayerHeight;

			// �I�u�W�F�N�g�̏��
			int Bx = x * 32;
			int By = y * 32;
			int Bw = MAPCHIP_SIZW;
			int Bh = MAPCHIP_SIZH;
		

			if (MapChipData1[y][x] == 0 /*|| MapChipData1[y][x] == 1 || MapChipData1[y][x] == 2 || MapChipData1[y][x] == 3 || MapChipData1[y][x] == 4*/)
			{
				DrawBox(Bx, By, Bx + Bw, By + Bh, GetColor(255, 255, 255), false);
				DrawBox(Ax, Ay, Ax + Aw, Ay + Ah, GetColor(255, 255, 255), false);
				// ��Y�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N���܂�
				Ay = PlayerNextPosY;
				Ax = PlayerPosX;

				// �������Ă��邩�`�F�b�N
				if (Collision::IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
					// �������̏C��
					//�}���I�̍���
					if (dirArray[0]) {
						// ���������l����
						// �߂荞�ݗʂ��v�Z����
						int overlap = By + Bh - Ay;
						PlayerNextPosY = (Ay + overlap);
					}
					// �E�����̏C��
					//�}���I�̉E��
					if (dirArray[1]) {
						// ���������l����
						// �߂荞�ݗʂ��v�Z����
						int overlap = Ay + Ah - By;
						PlayerNextPosY = (Ay - overlap);
					}
					Ay = PlayerPosY;
					Ax = PlayerNextPosX;
					if (Collision::IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh))
					{
						if (dirArray[2]) {
							// ���������l����
							// �߂荞�ݗʂ��v�Z����
							int overlap = Bx + Bw - Ax;
							PlayerNextPosX = (Ax + overlap);
						}
						// �E�����̏C��
						//�}���I�̉E��
						if (dirArray[3]) {
							// ���������l����
							// �߂荞�ݗʂ��v�Z����
							int overlap = Ax + Aw - Bx;
							PlayerNextPosX = (Ax - overlap);
						}
					}
				}
			}
			
		}
	}
}
void Player::GetMoveDirection(bool* _dirArray)
{
	// �E�����̃`�F�b�N
	if (PlayerNextPosX > PlayerPosX) {
		_dirArray[3] = true;
	}
	// �������̃`�F�b�N
	if (PlayerNextPosX < PlayerPosX) {
		_dirArray[2] = true;
	}
	// �������̃`�F�b�N
	if (PlayerNextPosY > PlayerPosY) {
		_dirArray[1] = true;
	}
	// �������̃`�F�b�N
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