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

	//
	void EnemyHitHammer();
private:
	int TimeLimit = 60 * 20;//�Q�[���̃^�C�����~�b�g (20�b) fps60
	int Rate;
};