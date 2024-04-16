#include "Title.h"
#include "../scene.h"


#define TITLE_PATH				"data/TitleImage/Click shot.png"
#define TITLE_BUTTON_PATH		"data/TitleImage/PleaseClick.png"

Title::Title() 
{
	TitleImgaeHndl = 0;		//タイトルのハンドル
	TitleButtonHndl = 0;	//ボタンのハンドル

	button_X = 0;			//ボタンの座標
	button_Y = 0;			//ボタンの座標
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