//ウィンドウを表示するプログラム（ひな形）

#include "DxLib.h"	//DXライブラリのインクルード
#include "Common.h"
#include "Input/Input.h"
#include "scene/scene.h"
#include "scene/Title/Title.h"
#include "scene/Play/Play.h"
#include "scene/Result/Result.h"
#include"scene/Enemy/Enemy.h"



SCENE_ID sceneID;
int Score;
int ClickCount;

//設定フレームレート (60FPS)
#define FRAME_RATE (60)

//1フレームの時間 (ミリ秒)
#define FRAME_TIME (1000/FRAME_RATE)


struct FrameRateInfo
{
	int currentTime;    //現在の時間
	int lastFrameTime;  //前回のフレーム実行時の時間
	int count;          //フレームカウント用
	int calcFpsTime;    //FPSを計算した時間
	float fps;          //計測したFPS (表示用)
};

//フレームレート情報変数
FrameRateInfo frameRateInfo;

//FPS計算
void CalcFPS();

//FPS表示 (デバック用)
void DrawFPS();

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);

	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く
	Title title;
	Play play;
	Result result;

	sceneID = SCENE_INIT_TITLE;
	int SE_result = 0;
	int SE_space = 0;
	int SE_click = 0;

	SE_result = LoadSoundMem(SE_RESULT_);
	SE_space = LoadSoundMem(SE_INPUT_SPASE);
	SE_click = LoadSoundMem(SE_INPUT_CLICK);
	//入力制御初期化
	InitInput();

	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{

		Sleep(1);  //システムに処理を返す

		//現在の時間を取得
		frameRateInfo.currentTime = GetNowCount();

		//最初のループなら
		//現在の時間を、FPSの計算をした時間に設定
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}


		//現在の時間が、前回のフレーム時より
		//1000/60ミリ秒(1/60秒)以上経過していたら処理を実行する
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//フレーム実行時の時間を更新
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//フレーム数をカウント
			frameRateInfo.count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//エスケープキーが押されたら終了
				break;
			}

			//画面に表示されたものを初期化
			ClearDrawScreen();

			StepInput();

			//-----------------------------------------
			//ここからゲームの本体を書くことになる
			switch (sceneID)
			{
			//-----------------------------------------
			case SCENE_INIT_TITLE:
			{
				title.InitTitle();

				sceneID = SCENE_LOOP_TITLE;
			}
				break;

			case SCENE_LOOP_TITLE:
			{
				title.StepTitle();

				title.DrawTitle();

				if (IsKeyPush(KEY_INPUT_SPACE)) {
					sceneID = SCENE_FIN_TITLE;
				}
			}
				break;

			case SCENE_FIN_TITLE:
			{
				title.FinTitle();

				sceneID = SCENE_INIT_PLAY;
			}
				break;

			case SCENE_INIT_PLAY:
			{

				play.InitPlay();
				enemy.InitEnemy();
				Score = 0;
				ClickCount = 0;
				sceneID = SCENE_LOOP_PLAY;
			}
				break;

			case SCENE_LOOP_PLAY:
			{
				play.StepPlay();
				enemy.Stepenemy();
				//下描画
				enemy.DrawEnemy();
				play.DrawPlay();

				
			}
				break;

			case SCENE_FIN_PLAY:
			{
				play.FinPlay();

				sceneID = SCENE_INIT_RESULT;
			}
				break;

			case SCENE_INIT_RESULT:
			{
				PlaySoundMem(SE_result, DX_PLAYTYPE_BACK);
				result.InitResult();

				sceneID = SCENE_LOOP_RESULT;
			}
				break;

			case SCENE_LOOP_RESULT:
			{
				result.StepResult();

				result.DrawResult();

				if (IsKeyPush(KEY_INPUT_SPACE)) {
					sceneID = SCENE_FIN_RESULT;
				}
			}
				break;

			case SCENE_FIN_RESULT:
			{
				result.FinResult();

				sceneID = SCENE_INIT_TITLE;
			}
				break;

			default:
				break;

			}

			if (IsKeyPush(KEY_INPUT_SPACE)) {
				PlaySoundMem(SE_space, DX_PLAYTYPE_BACK);
			}
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && player.GetPlayerAttack())
			{
				PlaySoundMem(SE_click, DX_PLAYTYPE_BACK);
			}

			//-----------------------------------------

			//FPS計算
			CalcFPS();

			//FPS表示
			DrawFPS();


			//ループの終わりに
			//フリップ関数
			ScreenFlip();
		}
	}

	

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く

	DeleteSoundMem(SE_result);
	DeleteSoundMem(SE_space);
	DeleteSoundMem(SE_click);
	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

	void CalcFPS()
	{
		//前回のFPSを計算した時間からの経過時間を求める
		int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

		//前回のFPSを計算した時間から
		//1秒以上経過していたらFPSを計算する
		if (difTime > 1000)
		{
			//フレーム回数をミリ秒に合わせる
			//少数まで出したいのでfloatにキャスト
			float frameCount = (float)(frameRateInfo.count * 1000.0f);

			//FPSを求める
			//理想の数値は 60000 / 1000 で 60 となる
			frameRateInfo.fps = frameCount / difTime;

			//フレームレートカウントをクリア
			frameRateInfo.fps = frameCount / difTime;

			//フレームレートカウントをクリア
			frameRateInfo.count = 0;

			//FPSを計算した時間を更新
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
		}
	}

	//FPS表示 (デバック用)
	void DrawFPS()
	{
		unsigned int color = GetColor(255, 30, 30);
		DrawFormatString(1100, 600, color, "FPS[%.2f]", frameRateInfo.fps);

	}

