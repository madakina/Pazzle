#include"Pazzle.h"

// 全体の処理
void STitle::Process() 
{
	Draw();							// 描画をする
	// マウスの情報を取得
	GetMousePoint(&Mousex, &Mousey);
	// マウスの現在座標とブロックの座標を計算
	if (Mousex >= 110 && Mousey >= 110 && Mousex <= 160 && Mousey <= 160)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag = 1;	ChangeGameState(GS_MAIN);	}
	if (Mousex >= 290 && Mousey >= 110 && Mousex <= 340 && Mousey <= 160)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag = 2;	ChangeGameState(GS_MAIN);	}
	if (Mousex >= 470 && Mousey >= 110 && Mousex <= 520 && Mousey <= 160)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag = 3;	ChangeGameState(GS_MAIN);	}
}

// タイトル画面の初期化処理
void STitle::Init() 
{
	BgmControl.ChangePlay(BGM_TITLE);
}

// 最初の変数の初期化
void STitle::FirstInit() 
{
	memset(this, 0, sizeof(STitle));
}

void STitle::Load() 
{
	Graphic[TG_BACK] = LoadGraph("picture/背景画像未定.png");	// タイトルの背景画像をロード
	Graphic[TG_Stage1] = LoadGraph("picture/ステージ1-1.png");	// ステージ1-1
	Graphic[TG_Stage2] = LoadGraph("picture/ステージ1-2.png");	// ステージ1-2
	Graphic[TG_Stage3] = LoadGraph("picture/ステージ1-3.png");	// ステージ1-3
	Graphic[TG_Stage1View] = LoadGraph("picture/ステージ1-1View.png");	// ステージ1-1の情報を公開
	Graphic[TG_Stage2View] = LoadGraph("picture/ステージ1-2View.png");	// ステージ1-2の情報を公開
	Graphic[TG_Stage3View] = LoadGraph("picture/ステージ1-3View.png");	// ステージ1-3の情報を公開
}

// 描画
void STitle::Draw() 
{
	DrawGraph(0, 0, Graphic[TG_BACK], FALSE);

	DrawGraph(100, 100, Graphic[TG_Stage1], TRUE);
	DrawGraph(280, 100, Graphic[TG_Stage2], TRUE);
	DrawGraph(460, 100, Graphic[TG_Stage3], TRUE);
	// マウスの情報を取得
	GetMousePoint(&Mousex, &Mousey);
	// マウスの現在座標とブロックの座標を計算
	if (Mousex >= 110 && Mousey >= 110 && Mousex <= 160 && Mousey <= 160)
	{
		const char *lv = "かんたん";
		centerx = CalcCenterX(lv);
		DrawFormatString(centerx, 25, White, lv);
		DrawGraph(50, 50, Graphic[TG_Stage1View], TRUE);
	}
	if (Mousex >= 290 && Mousey >= 110 && Mousex <= 340 && Mousey <= 160)
	{
		const char *lv = "ふつう";
		centerx = CalcCenterX(lv);
		DrawFormatString(centerx, 25, White, lv);
		DrawGraph(50, 50, Graphic[TG_Stage2View], TRUE);
	}

	if (Mousex >= 470 && Mousey >= 110 && Mousex <= 520 && Mousey <= 160)
	{
		const char *lv = "むずかしい";
		centerx = CalcCenterX(lv);
		DrawFormatString(centerx, 25, White, lv);
		DrawGraph(50, 50, Graphic[TG_Stage3View], TRUE);
	}

	// 各ステージ選択の選択範囲確認用
//	DrawFormatString(10, 10, GetColor(255, 255, 255), "%d", Mousex);
//	DrawFormatString(10, 25, GetColor(255, 255, 255), "%d", Mousey);
//	DrawFormatString(10, 40, GetColor(255, 255, 255), "%d", StageFlag);
}