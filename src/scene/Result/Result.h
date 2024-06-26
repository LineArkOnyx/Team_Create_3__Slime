#pragma once

#include "DxLib.h"
#include "../scene.h"
#include "../../Common.h"
#include "../../Input/Input.h"

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
	
	int ResultHndl;
	bool ResultDrawFlg;	//trueでタイトルへ移動,falseでゲームへ移動
	
};
extern Result result;