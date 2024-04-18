#pragma once
#include "DxLib.h"
#include "../scene.h"
#include "../../Input/Input.h"
#include "../../Common.h"

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
	int SelectImageHndl;
	bool TitleDrawFlg;	//true�Ń^�C�g����\��,false�ŃZ���N�g��ʕ\��
};