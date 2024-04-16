#include "Result.h"

#define RESULT_PATH			"data/ResultImage/���ʔ��\.png"
#define SCORE_PATH			"data/ResultImage/�X�R�A.png"
#define MOLE_PATH			"data/ResultImage/�������@������.png"

Result::Result()
{
	ResultHndl = 0;		//���U���g��ʂ̃n���h��
	ScoreHndl = 0;		//�����̃n���h��
	MoleHndl = 0;		//�����̃n���h��

	Score_X = 0;		//�����̍��W
	Score_Y = 0;		//�����̍��W

	Mole_X = 0;			//�����̍��W
	Mole_Y = 0;			//�����̍��W
}
Result::~Result()
{

}
void Result::InitResult()
{
	Rate = Score / ClickCount;

	ResultHndl = LoadGraph(RESULT_PATH);
	ScoreHndl = LoadGraph(SCORE_PATH);
	MoleHndl = LoadGraph(MOLE_PATH);
	
	Score_X = 100;
	Score_Y = 250;

	Mole_X = 100;
	Mole_Y = 400;
}
void Result::StepResult()
{
	
}
void Result::DrawResult()
{
	DrawGraph(0, 0, ResultHndl, true);
	DrawGraph(Score_X, Score_Y, ScoreHndl, true);
	DrawGraph(Mole_X, Mole_Y, MoleHndl, true);

	DrawFormatString(700, 290, GetColor(255, 127, 255), "%d", Score);
	DrawFormatString(700, 435, GetColor(255, 127, 255), "%d", ClickCount);
}
void Result::FinResult() 
{
	DeleteGraph(ResultHndl);
	DeleteGraph(ScoreHndl);
	DeleteGraph(MoleHndl);
}