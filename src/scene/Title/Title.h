#pragma once
#include "DxLib.h"

constexpr int button_W = 400;
constexpr int button_H = 100;


class Title
{
public:
	Title();
	~Title();
	void InitTitle();
	void StepTitle();
	void DrawTitle();
	void FinTitle();
private:
	int TitleImgaeHndl;
	int TitleButtonHndl;
	int TitlehammerHndl;

	int button_X;
	int button_Y;

	int hammer_X;
	int hammer_Y;

};