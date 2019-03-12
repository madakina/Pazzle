#include"Pazzle.h"

// メインゲームの処理
void SGameMain::Process() {

	switch (StageFlag) {
	case 0: ChangeGameState(GS_TITLE); break;
	case 1:	MapData.Map1(); break;
	case 2:	MapData.Map2(); break;
	case 3:	MapData.Map3(); break;
	case 4: ChangeGameState(GS_TITLE); break;
	}
	Draw();
}

// メインゲームの初期化処理
void SGameMain::Init() {
	BgmControl.ChangePlay(BGM_GAMEMAIN);
}

// 最初の変数の初期化
void SGameMain::FirstInit() {
	memset(this, 0, sizeof(SGameMain));
}

// ロード
void SGameMain::Load() {
	// 各pictureをロード
	//	Graphic[MG_BACK] = LoadGraph("picture/ゲーム画面背景picture未定.png");
	Graphic[MG_RESET] = LoadGraph("picture/やりなおし.png");
}

// 描画
void SGameMain::Draw() {
	DrawGraph(608, 448, Graphic[MG_RESET], TRUE);
//	DrawFormatString(10, 40, GetColor(255, 255, 255), "%d", StageFlag);
}
