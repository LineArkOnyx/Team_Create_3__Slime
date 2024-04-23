#pragma once
#include "DxLib.h"
#include "Player/Player.h"
#include "../../Collision/Collision.h"
#include "../../Common.h"
#include "../scene.h"



class Play
{
public:
	Play();
	~Play();
	void InitPlay();
	void StepPlay();
	void DrawPlay();
	void FinPlay();

private:
	int BackGroundHndl;//”wŒi‰æ‘œƒnƒ“ƒhƒ‹
};
extern Play play;