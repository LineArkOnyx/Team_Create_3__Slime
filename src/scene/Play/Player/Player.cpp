#include "Player.h"
#include"../../../Collision/Collision.h"
#include"../../../Map/Map.h"
#include "../../scene.h"
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
	PlayerNextPosY = 300;
	PlayerWidth = 32;
	PlayerHeight = 32;
	PlayerImgHndl = -1;
	PlayerJumpPower = 0;
	Player_Gravity_Speed = 0;
	PlayerJumpFlg = false;
	PlayerMoveVeFlg = false;
}
Player::~Player()
{

}
void Player::InitPlayer()
{
	PlayerImgHndl = LoadGraph("Data/�X���C��.png");
	PlayerPosX = 0;
	PlayerPosY = 0;
	PlayerNextPosX = 400;
	PlayerNextPosY = 300;
	if (map.GetMaplevel()==3)
	{
		PlayerNextPosX = 10;
		PlayerNextPosY = 10;
	}
}
void Player::MovePlayer()
{
	//�W�����v
  	if (IsKeyPush(KEY_INPUT_W) || IsKeyPush(KEY_INPUT_SPACE)&& PlayerJumpFlg == true )
	{
		Player_Gravity_Speed -= PLAYER_JUNP;
	}
	if (IsKeyRelease(KEY_INPUT_W) || IsKeyRelease(KEY_INPUT_SPACE))
	{
		PlayerJumpFlg = false;
	}
	if (IsKeyKeep(KEY_INPUT_A))
	{
		PlayerMoveVeFlg = true;
		PlayerNextPosX -= PLAYER_SPEED;
	}
	if (IsKeyKeep(KEY_INPUT_D))
	{
		PlayerMoveVeFlg = false;
		PlayerNextPosX += PLAYER_SPEED;
	}
}
void Player::GravityPlayer()
{
	Player_Gravity_Speed += PLAYER_GRAVITY;
	if (Player_Gravity_Speed >= PLAYER_GRAVITY_LIMIT)	//�d�͂̏�������߂�
	{
		PlayerNextPosY += PLAYER_GRAVITY_LIMIT;
		Player_Gravity_Speed = PLAYER_GRAVITY_LIMIT;
	}
	else	//����s���܂œ���
	{
		PlayerNextPosY += Player_Gravity_Speed;
	}

}
void Player::DrawPlayer()
{
	DrawRotaGraph(PlayerPosX + 18, PlayerPosY + 14, 1.0, 0.0, PlayerImgHndl, true, PlayerMoveVeFlg);
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
			if (MapChipData1[y][x] == 11 || MapChipData1[y][x] == 3)
				continue;

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
						PlayerJumpFlg = true;
						if (MapChipData1[y][x] == 1)
						{
							toumei[y][x] = true;
						}
						int overlap = Ay + Ah - By;
						PlayerNextPosY = (Ay - overlap);
					}	
				}
			}
			if (toumei[y][x] == true)
			{
				mapFramecount[y][x]++;
				if (mapFramecount[y][x] == 50)
				{
					MapChipData1[y][x] = 11;
					mapFramecount[y][x] = 0;
				}
			}
		}
	}
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

			if (MapChipData1[y][x] == 11|| MapChipData1[y][x] == 3)		//0�Ԗڂ��������蔻������
				continue;

			{
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
	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			int Ax = PlayerPosX;
			int Ay = PlayerPosY;
			int Aw = PlayerWidth;
			int Ah = PlayerHeight;

			// �I�u�W�F�N�g�̏��
			int Bx = x * 32;
			int By = y * 32;
			int Bw = MAPCHIP_SIZW;
			int Bh = MAPCHIP_SIZH;
			if (MapChipData1[y][x] == 3)
			{
				DrawBox(Bx, By, Bx + Bw, By + Bh, GetColor(255, 255, 255), false);
				if (Collision::IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh))
				{
					DrawFormatString(100, 70, GetColor(255, 0, 0), "�S�[���q�b�g");
					sceneID = SCENE_FIN_PLAY;
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
	DrawFormatString(100, 70, GetColor(255, 0, 0), "kuribo.m_x = %d", PlayerJumpFlg);

	PlayerPosX = PlayerNextPosX;
	PlayerPosY = PlayerNextPosY;
}