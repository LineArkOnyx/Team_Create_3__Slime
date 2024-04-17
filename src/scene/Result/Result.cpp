#include "Result.h"

#define RESULT_PATH			"data/ResultImage/結果発表.png"
#define SCORE_PATH			"data/ResultImage/スコア.png"
#define MOLE_PATH			"data/ResultImage/もぐらを叩いた数.png"

Result::Result()
{
	ResultHndl = 0;		//リザルト画面のハンドル
	ScoreHndl = 0;		//文字のハンドル
	MoleHndl = 0;		//文字のハンドル

	Score_X = 0;		//文字の座標
	Score_Y = 0;		//文字の座標

	Mole_X = 0;			//文字の座標
	Mole_Y = 0;			//文字の座標
}
Result::~Result()
{

}
void Result::InitResult()
{
	

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

	
}
void Result::FinResult() 
{
	DeleteGraph(ResultHndl);
	DeleteGraph(ScoreHndl);
	DeleteGraph(MoleHndl);
}