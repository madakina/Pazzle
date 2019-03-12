#define _GLOBAL_SET_
#include"Pazzle.h"
#include"MapConts.h"
// DXライブラリのプログラムはWinMainから始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("パズル");						// ウィンドウタイトル
	ChangeWindowMode(TRUE); SetGraphMode(640, 480, 16);	// ウィンドウモードに変更
	if (DxLib_Init() == -1)return -1;					// DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);						// 描画先画面を裏画面にセット

	FirstInit();										// 起動時に一度だけ初期化;

	MainLoop();											// メインループ

	InitGraph();										// 読み込んだ画像データを削除する
	InitSoundMem();										// 読み込んだ音声データを削除する

	DxLib_End();										// DXライブラリ終了処理

	return 0;											// プログラムを終了する
}

void FirstInit()
{
	// 変数の初期化
	Title.FirstInit();
	GameMain.FirstInit();
	GameClear.FirstInit();
	BgmControl.FirstInit();
	SeControl.FirstInit();

	FpsControl.FirstInit();

	LoadFiles();										// 画像、音声データなどを読み込む

	FpsControl.PreCount = GetNowCount();
	ChangeGameState(GS_TITLE);							// 最初のゲーム状態をタイトルにセット
}

void MainLoop()
{
	// メインループ、ProcessLoop関数が異常終了するかESCキーが押されるとループから抜ける
	while (ProcessLoop() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();							// 画面を初期化
		KeyCount(Key);								// キーボードの押下状況を調べる

		// ゲームステートによって処理する関数を選択する
		switch (GameState) {
		case GS_TITLE:	Title.Process();	break;
		case GS_MAIN:	GameMain.Process();	break;
		case GS_CLEAR:	GameClear.Process();break;
		}
		BgmControl.Process();						// BGMの管理
		SeControl.Process();						// 効果音の管理
		FpsControl.Process();

		ScreenFlip();								// 裏画面の処理を表に反映
	}
}