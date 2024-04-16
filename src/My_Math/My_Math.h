#pragma once
#include"DxLib.h"
#include <math.h>

class MyMath
{
public:
	static VECTOR VecCreate(VECTOR start, VECTOR end);
	static VECTOR AddVec(VECTOR vec1, VECTOR vec2);
	static float VecLong(VECTOR vec);
	static VECTOR VecNormalize(VECTOR vec);
	static VECTOR VecScale(VECTOR vec, float scale);
};
