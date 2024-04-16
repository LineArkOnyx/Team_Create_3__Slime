
#ifndef __COLLISION_H__
#define __COLLISION_H__

#include <math.h>
#include "DxLib.h"
#include"../My_Math/My_Math.h"
class Collision
{
public:
	//IsHitRectのプロトタイプ宣言
	static bool IsHitRect(int n1_x, int n1_y, int n1_w, int n1_h, int n2_x, int n2_y, int n2_w, int n2_h);

	//IsHitCircleのプロトタイプ宣言
	static bool IsHitCircle(int c1_x, int c1_y, int c1_r, int c2_x, int c2_y, int c2_r);

	//円と線の当たり判定
	static bool IsHitCircle_Line(int circle_x, int circle_y, int circle_r, int linestart_x, int linestart_y, int lineend_x, int lineend_y);
};

#endif
