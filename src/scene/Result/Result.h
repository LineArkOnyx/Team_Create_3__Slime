#pragma once

#include "DxLib.h"
#include "../../Common.h"

class Result
{
public:
	Result();
	~Result();
	void InitResult();
	void StepResult();
	void DrawResult();
	void FinResult();
private:
	int Rate; //キルレート (スコア / クリック回数)

	int ResultHndl;
	int ScoreHndl;
	int MoleHndl;

	int Score_X;
	int Score_Y;
	int Mole_X;
	int Mole_Y;
};

