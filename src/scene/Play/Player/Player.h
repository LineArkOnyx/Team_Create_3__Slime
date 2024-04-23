#pragma once
#include "DxLib.h"
#include "../../../Input/Input.h"
#include "../../../Common.h"

class Player 
{
private:
	int PlayerPosX, PlayerPosY;		// ���W
	int PlayerNextPosX, PlayerNextPosY;//���̍��W
	int PlayerWidth, PlayerHeight;	//�v���C���[�̃T�C�Y
	int PlayerImgHndl;				// �摜�n���h��
	bool PlayerMoveVeFlg;			//�v���C���[�����E�ǂ���������Ă��邩��ݒ�
	int PlayerJumpPower;			// �W�����v��
	int Player_Gravity_Speed;
	bool PlayerJumpFlg;				// �W�����v�̉�(�ڒn�t���O)

public:
	Player();
	~Player();
	void InitPlayer();
	void MovePlayer();
	void GravityPlayer();
	void DrawPlayer();
	void FinPlayer();
	void PlayerHitMapColision();
	void dethline();
	void GetMoveDirection(bool* _dirArray);
	void UpdatePos();
	void SetJumpFlg(bool JumpFlg);	//��Ƀ}�b�v�`�b�v�Ƃ̓����蔻��Őڒn�����Ƃ��Ɏg��
	void SetPlayerPos(int PosX, int PosY);
	void SetPlayerNextPos(int PosX, int PosY);
	
	int GetPosX();		//�v���C���[��X���W
	int GetPosY();		//�v���C���[��Y���W
	int GetNextPosX();	//�v���C���[�̎���X���W
	int GetNextPosY();	//�v���C���[�̎���Y���W
	int GetWidth();		//�v���C���[�̉���
	int GetHeight();	//�v���C���[�̍���
};

extern Player player;