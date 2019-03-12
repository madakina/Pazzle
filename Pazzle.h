#ifndef DEF_PAZZLE_H
#define DEF_PAZZLE_H

#include"DxLib.h"
#include"Define.h"
#include"Fps.h"
#include"GameClear.h"
#include"GameMain.h"
#include"Map.h"
#include"MapConts.h"
#include"MapData.h"
#include"Sound.h"
#include"Title.h"
#include"Global.h"

// Mainの関数
// 最初に一度だけ初期化する関数
void FirstInit();
// ゲームを無限ループで表示させ続ける関数
void MainLoop();

// Systenの関数
// キーの入力状態を更新する関数(キーが押された瞬間を取得するために必要な関数)
void KeyCount(int *KeyBuf);
// ファイルを読み込む関数
void LoadFiles();
// ゲームの状態を変更する関数
void ChangeGameState(int NewGameState);
// ループ毎に行う必要のある処理を行う関数、各処理でエラーが発生した場合-1を返す(異常終了)
int ProcessLoop();
// 文字列を中央に表示する
int CalcCenterX(const char *str);


#endif