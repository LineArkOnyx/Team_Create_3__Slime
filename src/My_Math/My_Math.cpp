//éˆã∆Ç≈çÏÇ¡ÇΩÇ‡ÇÃ
#include"My_Math.h"

VECTOR MyMath::VecCreate(VECTOR start, VECTOR end)
{
	VECTOR Vec;
	Vec.x = end.x - start.x;
	Vec.y = end.y - start.y;
	Vec.z = end.z - start.z;

	return Vec;
}

VECTOR MyMath::AddVec(VECTOR vec1, VECTOR vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;

	return vec1;
}

float MyMath::VecLong(VECTOR vec)
{
	float Vx = vec.x * vec.x;
	float Vy = vec.y * vec.y;
	float Vz = vec.z * vec.z;
	float Long = Vx + Vy + Vz;
	Long = sqrtf(Long);

	return Long;
}

VECTOR MyMath::VecNormalize(VECTOR vec)
{
	VECTOR _Vec;
	float Long = VecLong(vec);
	_Vec.x = vec.x / Long;
	_Vec.y = vec.y / Long;
	_Vec.z = vec.z / Long;

	return _Vec;
}

VECTOR MyMath::VecScale(VECTOR vec, float scale)
{
	VECTOR _Vec;
	_Vec.x = vec.x * scale;
	_Vec.y = vec.y * scale;
	_Vec.z = vec.z * scale;

	return _Vec;
}