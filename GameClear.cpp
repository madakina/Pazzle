#include"Pazzle.h"

// ゲームクリア画面の処理
void SGameClear::Process() {
	Draw();
	// マウスの情報を取得
	GetMousePoint(&Mousex, &Mousey);
	// マウスの現在座標とブロックの座標を計算
	if (Mousex >= 120 && Mousey >= 300 && Mousex <= 280 && Mousey <= 320)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag--;	ChangeGameState(GS_MAIN);	}
	if (Mousex >= 380 && Mousey >= 300 && Mousex <= 540 && Mousey <= 320)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag++;	ChangeGameState(GS_MAIN);	}
	if (Mousex >= 250 && Mousey >= 350 && Mousex <= 410 && Mousey <= 370)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag = 0;	ChangeGameState(GS_MAIN);	}
}

// ゲームクリア画面の初期化
void SGameClear::Init() {
	BgmControl.ChangePlay(BGM_GAMECLEAR);
}

// 最初の変数の初期化
void SGameClear::FirstInit() {
	memset(this, 0, sizeof(SGameClear));
}

// ロード
void SGameClear::Load() {
	Graphic[CG_CLEAR] = LoadGraph("picture/GAME CLEAR.png");
	Graphic[CG_BACK] = LoadGraph("picture/BACK.png");
	Graphic[CG_NEXT] = LoadGraph("picture/NEXT.png");
	Graphic[CG_TOP] = LoadGraph("picture/TOP.png");
	Graphic[CG_MAP1] = LoadGraph("picture/ステージクリア(1-1).png");
	Graphic[CG_MAP2] = LoadGraph("picture/ステージクリア(1-2).png");
	Graphic[CG_MAP3] = LoadGraph("picture/ステージクリア(1-3).png");
}

// 描画
void SGameClear::Draw() {
	if (StageFlag == 1) DrawGraph(0, 0, Graphic[CG_MAP1], TRUE);
	if (StageFlag == 2) DrawGraph(0, 0, Graphic[CG_MAP2], TRUE);
	if (StageFlag == 3) DrawGraph(0, 0, Graphic[CG_MAP3], TRUE);
	DrawGraph(75, 200, Graphic[CG_CLEAR], TRUE);
	DrawGraph(120, 300, Graphic[CG_BACK], TRUE);
	DrawGraph(380, 300, Graphic[CG_NEXT], TRUE);
	DrawGraph(250, 350, Graphic[CG_TOP], TRUE);

//	DrawFormatString(10, 10, GetColor(255, 255, 255), "%d", Mousex);
//	DrawFormatString(10, 25, GetColor(255, 255, 255), "%d", Mousey);
//	DrawFormatString(10, 40, GetColor(255, 255, 255), "%d", StageFlag);
}