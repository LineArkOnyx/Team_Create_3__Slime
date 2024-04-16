#include "Title.h"
#include "../scene.h"


#define TITLE_PATH				"data/TitleImage/Click shot.png"
#define TITLE_BUTTON_PATH		"data/TitleImage/PleaseClick.png"

Title::Title() 
{
	TitleImgaeHndl = 0;		//�^�C�g���̃n���h��
	TitleButtonHndl = 0;	//�{�^���̃n���h��

	button_X = 0;			//�{�^���̍��W
	button_Y = 0;			//�{�^���̍��W
}
Title::~Title() 
{

}
void Title::InitTitle()
{
	TitleImgaeHndl = LoadGraph(TITLE_PATH);
	TitleButtonHndl = LoadGraph(TITLE_BUTTON_PATH);
	button_X = 330;
	button_Y = 550;

	SetMouseDispFlag(true);
}
void Title::StepTitle()
{
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		sceneID = SCENE_INIT_PLAY;
	}
}
void Title::DrawTitle()
{
	DrawGraph(0, 0, TitleImgaeHndl, true);
	DrawGraph(button_X, button_Y, TitleButtonHndl, true);
}
void Title::FinTitle()
{
	DeleteGraph(TitleImgaeHndl);
	DeleteGraph(TitleButtonHndl);
}