#pragma once

//入力制御初期化
void InitInput();

//入力制御ステップ
//他のStepより早く呼ぶ
void StepInput();

//今押された
bool IsKeyPush(int Key_code);

//押し続けられている
bool IsKeyKeep(int Key_code);

//今離されたか
bool IsKeyRelease(int Key_code);

bool IsKeyDown(int Key_code);