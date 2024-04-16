#include "Player.h"
#include "../../../Common.h"

Player player;
Player::Player()
{
	PlayerPosH = 8, PlayerPosW = 8;//H��W��������^\^
	PlayerPosX = PlayerPosY = 0;	//�v���C���[�̍��W
	PlayerIdleHndl = PlayerAttackHndl = 0;	//�v���C���[�̉摜�n���h��
	CurrentClickFlg = NextClickFlg = 0;//���N���b�N����Ă��邩�����m����
}
Player::~Player()
{

}
void Player::InitPlayer()
{
	PlayerPosX = SCREEN_SIZE_X / 2; 
	PlayerPosY = SCREEN_SIZE_Y / 2;//�v���C���[�̏������W�Z�b�g
	SetMousePoint(PlayerPosX, PlayerPosY);//�v���C���[�ɔ�����
	PlayerIdleHndl = LoadGraph(""); //�v���C���[�̉摜�ǂݍ��� <-- ���
	PlayerAttackHndl = LoadGraph("");
}
void Player::StepPlayer()
{

	CurrentClickFlg = NextClickFlg;	//�J�����g���X�V

	GetMousePoint(&PlayerPosX, &PlayerPosY);//�}�E�X�|�C���^�̈ʒu�Ƀv���C���[�z�u

	NextClickFlg = GetMouseInput() & MOUSE_INPUT_LEFT;//���N���b�N�����m

	if (NextClickFlg != 0 && CurrentClickFlg == 0){	// ���t���[���ŉ�����Ă��邩�O�t���[���ŉ�����Ă��Ȃ�
		AttackFlg = true;	//�@��
	}
	else {	//���Ă͂܂�Ȃ�(������ĂȂ��A�܂��͉��������Ă���ꍇ)
		AttackFlg = false;	//�@���Ȃ�
	}
}
void Player::DrawPlayer()
{
	if (NextClickFlg != 0) {	//�����ꑱ���Ă���ꍇ
		DrawGraph(PlayerPosX, PlayerPosY, PlayerAttackHndl, true);	//�U�����̉摜�\��
	}
	else {
		DrawGraph(PlayerPosX, PlayerPosY, PlayerIdleHndl, true);	//�ҋ@�摜�\��
	}
	DrawFormatString(0, 0, GetColor(255, 255, 0), "X : %d Y : %d\nclick C: %d N: %d\nATK : %d",PlayerPosX,PlayerPosY,CurrentClickFlg,NextClickFlg, AttackFlg);
}
void Player::FinPlayer()
{
	DeleteGraph(PlayerAttackHndl);
	DeleteGraph(PlayerIdleHndl);
}

bool Player::GetPlayerAttack()	//�@���t���O���擾
{
	return AttackFlg;
}
int Player::GetPlayerPosX()	//���W�擾
{
	return PlayerPosX;
}
int Player::GetPlayerPosY()	//���W�擾
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