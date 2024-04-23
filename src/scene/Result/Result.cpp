#include "Result.h"



Result::Result()
{
	ResultHndl = -1;
	ResultDrawFlg = true;
}
Result::~Result()
{

}
void Result::InitResult()
{
	ResultHndl = LoadGraph("Data/GoalFlag.png");
}
void Result::StepResult()
{
	if (IsKeyPush(KEY_INPUT_A) || IsKeyPush(KEY_INPUT_LEFT) || IsKeyPush(KEY_INPUT_D) || IsKeyPush(KEY_INPUT_RIGHT)) {
		if (ResultDrawFlg) {
			ResultDrawFlg = false;
		}
		else {
			ResultDrawFlg = true;
		}
	}
	if (IsKeyPush(KEY_INPUT_RETURN)) {
		sceneID = SCENE_FIN_RESULT;
	}
}
void Result::DrawResult()
{
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(223, 191, 127), true);
	DrawRotaGraph(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, 2.0, 0.0, ResultHndl, true);
	
	if (ResultDrawFlg) {
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(255, 128, 0), "   ƒ^ƒCƒgƒ‹‚Ö–ß‚é >>");
	}
	else {
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(255, 128, 0), "<<   ŽŸ‚Ö‚·‚·‚Þ     ");
	}
}
void Result::FinResult() 
{
	DeleteGraph(ResultHndl);
	if (ResultDrawFlg) {
		StageIndex = 1;
		sceneID = SCENE_INIT_TITLE;
	}
	else {
		StageIndex++;
		if (StageIndex >= 3) {
			StageIndex = 0;
		}
		sceneID = SCENE_INIT_PLAY;
	}
}
Result result;