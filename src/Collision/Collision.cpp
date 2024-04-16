//円と線の当たり判定製作:野田
//それ以外は授業で作ったもの
#include "Collision.h"

//IsHitRectの定義
bool Collision::IsHitRect(int n1_x, int n1_y, int n1_w, int n1_h, int n2_x, int n2_y, int n2_w, int n2_h) {
	if (n1_x < n2_x + n2_w && n1_x + n1_w > n2_x && n1_y < n2_y + n2_h && n1_y + n1_h > n2_y) {
		return true;
	}
	return false;
}

//IsHitCircleの定義
bool Collision::IsHitCircle(int c1_x, int c1_y, int c1_r, int c2_x, int c2_y, int c2_r){
	if ((c1_r + c2_r) * (c1_r + c2_r) > ((c1_x - c2_x) * (c1_x - c2_x) + (c1_y - c2_y) * (c1_y - c2_y))){
		return true;
	}
	return false;
}

//円と線の当たり判定
bool Collision::IsHitCircle_Line(int circle_x, int circle_y, int circle_r, int linestart_x, int linestart_y,int lineend_x,int lineend_y)
{
	VECTOR S_to_C = { 0.0,0.0,0.0 };	//線の始まりから円の中心のベクトル
	VECTOR E_to_C = { 0.0,0.0,0.0 };;	//線の終わりから円の中心のベクトル
	VECTOR S_to_E = { 0.0,0.0,0.0 };;	//線の始まりから線の終わりのベクトル
	VECTOR N_S_to_E = { 0.0,0.0,0.0 };;	//線の始まりから線の終わりの単位ベクトル

	float Distance;//線と円の最短距離

	S_to_C.x = circle_x - linestart_x;
	S_to_C.y = circle_y - linestart_y;
	E_to_C.x = circle_x - lineend_x;
	E_to_C.y = circle_y - lineend_y;
	S_to_E.x = lineend_x - linestart_x;
	S_to_E.y = lineend_y - linestart_y;

	N_S_to_E = MyMath::VecNormalize(S_to_E);
	
	Distance = (S_to_C.x * N_S_to_E.y) - (N_S_to_E.x * S_to_C.y);

	if (fabs(Distance) < circle_r) {
		
		//始点から終点と始点から円の中心の内積
		float dot1 = (S_to_C.x * S_to_E.x) + (S_to_C.y * S_to_E.y);
		//始点から終点と終点から円の中心の内積
		float dot2 = (E_to_C.x * S_to_E.x) + (E_to_C.y * S_to_E.y);

		if (dot1 * dot2 <= 0.0f){
			return true;
		}
	}
	else {
		float len1 = MyMath::VecLong(S_to_C);
		float len2 = MyMath::VecLong(E_to_C);
		if (len1 < circle_r || len2 < circle_r) {
			return true;
		}
	}

	return false;
}
