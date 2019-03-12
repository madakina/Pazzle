#include"Pazzle.h"

// フレームコントロール
void SFpsControl::Process() {
	int Difference = GetNowCount() - PreCount;
	PreCount = GetNowCount();
	RemTime[Index] += Difference;
	Index++;

	if (Index == 60) {					// 60回ループしてきたなら
		Index = 0;						// 添え字初期化
		Fps = 0;						// 初期化
		for (int i = 0; i < 60; i++)	// 60回でどれだけの時間が経過したか
			Fps += RemTime[i];
		One = (int)(Fps / 60);			// 平均で1フレームに何ミリ秒かかったか
		if (Fps != 0)					// ０で割らないための処理
			Fps = ((60 / Fps) * 1000);	// Fpsをもとめる
		memset(RemTime, 0, sizeof(RemTime));
	}

	int WaitCount = 16 - Difference;
	if (WaitCount > 0) {				// 早くここにきたら
		RemTime[Index] += WaitCount;
		Sleep(WaitCount);				// 待つ
	}
//	DrawFormatString(0, 0, White, "%3.1f", Fps);
//	DrawFormatString(0, 20, White, "%d", One);
}

void SFpsControl::FirstInit() {
	memset(this, 0, sizeof(SFpsControl));
}

