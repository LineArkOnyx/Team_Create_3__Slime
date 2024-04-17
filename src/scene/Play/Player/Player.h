#pragma once
#include "DxLib.h"
#include "../../../Input/Input.h"
#include "../../../Common.h"

class Player 
{
private:
	int PlayerPosX, PlayerPosY;		// ���W
	int PlayerWidth, PlayerHeight;	//�v���C���[�̃T�C�Y
	int PlayerImgHndl;				// �摜�n���h��
	int PlayerJumpPower;			// �W�����v��
	bool PlayerJumpFlg;				// �W�����v�̉�(�ڒn�t���O)

public:
	Player();
	~Player();
	void InitPlayer();
	void StepPlayer();
	void DrawPlayer();
	void FinPlayer();
	
	void SetJumpFlg(bool JumpFlg);	//��Ƀ}�b�v�`�b�v�Ƃ̓����蔻��Őڒn�����Ƃ��Ɏg��
	
	int GetPosX();		//�v���C���[��X���W
	int GetPosY();		//�v���C���[��Y���W
	int GetWidth();		//�v���C���[�̉���
	int GetHeight();	//�v���C���[�̍���
};

extern Player player;