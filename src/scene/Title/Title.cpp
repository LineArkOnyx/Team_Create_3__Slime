#include "Title.h"

Title::Title() 
{
	TitleDrawFlg = true;
	TitleImgaeHndl = -1;
	SelectImageHndl = -1;
}
Title::~Title() 
{

}
void Title::InitTitle()
{
	TitleDrawFlg = true;
	TitleImgaeHndl = LoadGraph("");
	SelectImageHndl = LoadGraph("");
	StageIndex = 1;
}
void Title::StepTitle()
{
	if (TitleDrawFlg) {
		if (IsKeyPush(KEY_INPUT_RETURN)) {
			TitleDrawFlg = false;
		}
	} 
	else {
		if (IsKeyPush(KEY_INPUT_RETURN)) {
			sceneID = SCENE_INIT_PLAY;
		}
		if (IsKeyPush(KEY_INPUT_A) || IsKeyPush(KEY_INPUT_LEFT)) {
			if (StageIndex <= 1) {
				StageIndex = STAGE_MAX_NUM;
			} 
			else {
				StageIndex--;
			}
		}
		if (IsKeyPush(KEY_INPUT_D) || IsKeyPush(KEY_INPUT_RIGHT)) {
			if (StageIndex >= STAGE_MAX_NUM) {
				StageIndex = 1;
			} 
			else {
				StageIndex++;
			}
		}
	}
}
void Title::DrawTitle()
{
	if (TitleDrawFlg) {
		DrawGraph(0, 0, TitleImgaeHndl, true);
	}
	else {
		DrawGraph(0, 0, SelectImageHndl, true);
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(127, 127, 255), "STAGE : %d", sceneID);
	}
}
void Title::FinTitle()
{
	DeleteGraph(TitleImgaeHndl);
	DeleteGraph(SelectImageHndl);
}