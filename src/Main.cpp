//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include "Common.h"
#include "Input/Input.h"
#include "scene/scene.h"
#include "scene/Title/Title.h"
#include "scene/Play/Play.h"
#include "scene/Result/Result.h"
#include"scene/Enemy/Enemy.h"



SCENE_ID sceneID;
int Score;
int ClickCount;

//�ݒ�t���[�����[�g (60FPS)
#define FRAME_RATE (60)

//1�t���[���̎��� (�~���b)
#define FRAME_TIME (1000/FRAME_RATE)


struct FrameRateInfo
{
	int currentTime;    //���݂̎���
	int lastFrameTime;  //�O��̃t���[�����s���̎���
	int count;          //�t���[���J�E���g�p
	int calcFpsTime;    //FPS���v�Z��������
	float fps;          //�v������FPS (�\���p)
};

//�t���[�����[�g���ϐ�
FrameRateInfo frameRateInfo;

//FPS�v�Z
void CalcFPS();

//FPS�\�� (�f�o�b�N�p)
void DrawFPS();

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���
	Title title;
	Play play;
	Result result;

	sceneID = SCENE_INIT_TITLE;
	int SE_result = 0;
	int SE_space = 0;
	int SE_click = 0;

	SE_result = LoadSoundMem(SE_RESULT_);
	SE_space = LoadSoundMem(SE_INPUT_SPASE);
	SE_click = LoadSoundMem(SE_INPUT_CLICK);
	//���͐��䏉����
	InitInput();

	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{

		Sleep(1);  //�V�X�e���ɏ�����Ԃ�

		//���݂̎��Ԃ��擾
		frameRateInfo.currentTime = GetNowCount();

		//�ŏ��̃��[�v�Ȃ�
		//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}


		//���݂̎��Ԃ��A�O��̃t���[�������
		//1000/60�~���b(1/60�b)�ȏ�o�߂��Ă����珈�������s����
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//�t���[�������J�E���g
			frameRateInfo.count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			//��ʂɕ\�����ꂽ���̂�������
			ClearDrawScreen();

			StepInput();

			//-----------------------------------------
			//��������Q�[���̖{�̂��������ƂɂȂ�
			switch (sceneID)
			{
			//-----------------------------------------
			case SCENE_INIT_TITLE:
			{
				title.InitTitle();

				sceneID = SCENE_LOOP_TITLE;
			}
				break;

			case SCENE_LOOP_TITLE:
			{
				title.StepTitle();

				title.DrawTitle();

				if (IsKeyPush(KEY_INPUT_SPACE)) {
					sceneID = SCENE_FIN_TITLE;
				}
			}
				break;

			case SCENE_FIN_TITLE:
			{
				title.FinTitle();

				sceneID = SCENE_INIT_PLAY;
			}
				break;

			case SCENE_INIT_PLAY:
			{

				play.InitPlay();
				enemy.InitEnemy();
				Score = 0;
				ClickCount = 0;
				sceneID = SCENE_LOOP_PLAY;
			}
				break;

			case SCENE_LOOP_PLAY:
			{
				play.StepPlay();
				enemy.Stepenemy();
				//���`��
				enemy.DrawEnemy();
				play.DrawPlay();

				
			}
				break;

			case SCENE_FIN_PLAY:
			{
				play.FinPlay();

				sceneID = SCENE_INIT_RESULT;
			}
				break;

			case SCENE_INIT_RESULT:
			{
				PlaySoundMem(SE_result, DX_PLAYTYPE_BACK);
				result.InitResult();

				sceneID = SCENE_LOOP_RESULT;
			}
				break;

			case SCENE_LOOP_RESULT:
			{
				result.StepResult();

				result.DrawResult();

				if (IsKeyPush(KEY_INPUT_SPACE)) {
					sceneID = SCENE_FIN_RESULT;
				}
			}
				break;

			case SCENE_FIN_RESULT:
			{
				result.FinResult();

				sceneID = SCENE_INIT_TITLE;
			}
				break;

			default:
				break;

			}

			if (IsKeyPush(KEY_INPUT_SPACE)) {
				PlaySoundMem(SE_space, DX_PLAYTYPE_BACK);
			}
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && player.GetPlayerAttack())
			{
				PlaySoundMem(SE_click, DX_PLAYTYPE_BACK);
			}

			//-----------------------------------------

			//FPS�v�Z
			CalcFPS();

			//FPS�\��
			DrawFPS();


			//���[�v�̏I����
			//�t���b�v�֐�
			ScreenFlip();
		}
	}

	

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���

	DeleteSoundMem(SE_result);
	DeleteSoundMem(SE_space);
	DeleteSoundMem(SE_click);
	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

	void CalcFPS()
	{
		//�O���FPS���v�Z�������Ԃ���̌o�ߎ��Ԃ����߂�
		int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

		//�O���FPS���v�Z�������Ԃ���
		//1�b�ȏ�o�߂��Ă�����FPS���v�Z����
		if (difTime > 1000)
		{
			//�t���[���񐔂��~���b�ɍ��킹��
			//�����܂ŏo�������̂�float�ɃL���X�g
			float frameCount = (float)(frameRateInfo.count * 1000.0f);

			//FPS�����߂�
			//���z�̐��l�� 60000 / 1000 �� 60 �ƂȂ�
			frameRateInfo.fps = frameCount / difTime;

			//�t���[�����[�g�J�E���g���N���A
			frameRateInfo.fps = frameCount / difTime;

			//�t���[�����[�g�J�E���g���N���A
			frameRateInfo.count = 0;

			//FPS���v�Z�������Ԃ��X�V
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
		}
	}

	//FPS�\�� (�f�o�b�N�p)
	void DrawFPS()
	{
		unsigned int color = GetColor(255, 30, 30);
		DrawFormatString(1100, 600, color, "FPS[%.2f]", frameRateInfo.fps);

	}

