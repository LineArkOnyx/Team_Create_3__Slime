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
	ResultHndl = LoadGraph("");
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
	DrawGraph(0, 0, ResultHndl, true);
	if (ResultDrawFlg) {
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(255, 128, 0), "タイトルへ戻る");
	}
	else {
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(255, 128, 0), " リトライする ");
	}
}
void Result::FinResult() 
{
	DeleteGraph(ResultHndl);
	if (ResultDrawFlg) {
		sceneID = SCENE_INIT_TITLE;
	}
	else {
		sceneID = SCENE_INIT_PLAY;
	}
}
Result result;