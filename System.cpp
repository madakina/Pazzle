#include "Pazzle.h"

//キーの入力状態を更新する関数(キーが押された瞬間を取得するために必要な関数)
void KeyCount(int *KeyBuf)
{
	char tmpKey[256];				//現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey);		//全てのキーの入力状態を得る
	for (int i = 0; i < 256; i++)
	{

		if (tmpKey[i] != 0)			//i番のキーコードに対応するキーが押されていたら
			KeyBuf[i]++;			//加算
		else               			//押されていなければ
			KeyBuf[i] = 0;			//0にする
	}
}

// ファイルを読み込む関数
void LoadFiles() {
	Title.Load();
	GameMain.Load();
	GameClear.Load();
	MapData.Load();

	BgmControl.Load();
	SeControl.Load();
}

// ゲームの状態を変更する関数
void ChangeGameState(int NewGameState) {
	GameState = NewGameState;			// ゲームの状態を更新
	switch (GameState) {				// 新しいゲームの状態の初期化を行うための分岐
	case GS_TITLE:Title.Init();		break;
	case GS_MAIN: GameMain.Init();	break;
	case GS_CLEAR:GameClear.Init();	break;
	}
}
//ループ毎に行う必要のある処理を行う関数、各処理でエラーが発生した場合-1を返す(異常終了)
int ProcessLoop()
{
	if (ScreenFlip() != 0)	return -1;		//裏画面を表画面に反映します
	if (ProcessMessage() != 0)	return -1;	//メッセージ処理を行います
	if (ClearDrawScreen() != 0) return -1;	//画面を消去します

	return 0;	//全ての処理が正常に終了した場合0を返す(正常終了)
}
// 文字列を中央に表示する
int CalcCenterX(const char *str)
{
	const int x1 = 0;
	const int x2 = 640;
	int StrLen, StrWidth;

	StrLen = (int)strlen(str);
	StrWidth = GetDrawStringWidth(str, StrLen);
	return (int)((x1 + ((x2 - x1) / 2)) - (StrWidth / 2));
}