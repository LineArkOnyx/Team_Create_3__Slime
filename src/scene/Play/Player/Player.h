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
	bool GetPlayerAttack();	//�@���t���O���擾
	int GetPlayerPosX();	//���W�擾
	int GetPlayerPosY();	//���W�擾
	int GetPlayerPosH();	//���W�擾
	int GetPlayerPosW();	//���W�擾

private:
	int PlayerPosH, PlayerPosW;	//�v���C���[�̍��W^\^
	int PlayerPosX,PlayerPosY;	//�v���C���[�̍��W
	int PlayerIdleHndl;	//�v���C���[�̉摜�n���h��(�ҋ@)
	int PlayerAttackHndl;	//�v���C���[�̉摜�n���h��(�U��)
	int CurrentClickFlg, NextClickFlg;	//���N���b�N����Ă��邩�����m����
	bool AttackFlg;	//���O����@���t���O

};

extern Player player;