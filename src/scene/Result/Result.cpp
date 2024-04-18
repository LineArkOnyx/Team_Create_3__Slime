#include "Result.h"



Result::Result()
{
	ResultHndl = -1;
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
	if (IsKeyPush(KEY_INPUT_RETURN)) {
		sceneID = SCENE_INIT_PLAY;
	}
}
void Result::DrawResult()
{
	DrawGraph(0, 0, ResultHndl, true);
}
void Result::FinResult() 
{
	DeleteGraph(ResultHndl);
}