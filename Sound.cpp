#include"Pazzle.h"

//	BGM-----------------------------------------
// 全体処理
void SBgmControl::Process() {
	if (PlayFlag == true) {							// 再生中なら
		Bgm[NowPlayIndex].Count++;					// 再生時間を更新
	}
}

// 再生ＢＧＭを変える、とめる
void SBgmControl::ChangePlay(int HandleIndex) {
	if (HandleIndex == -1) {						// 引数の指定が無ければ
		PlayFlag = false;							// 再生停止
		StopSoundMem(Bgm[NowPlayIndex].Handle);		// 音声を止める
		return;
	}
	else {
		if (PlayFlag == true)							// 今まで何か再生していたか
			StopSoundMem(Bgm[NowPlayIndex].Handle);		// 再生していたのなら停止する
		PlayFlag = true;								// 再生中
		NowPlayIndex = HandleIndex;						// 新しいハンドルを格納
		PlaySoundMem(Bgm[NowPlayIndex].Handle, DX_PLAYTYPE_BACK);	// 再生
		Bgm[NowPlayIndex].Count = 0;					// 再生時間を初期化
	}
}

// 最初の初期化
void SBgmControl::FirstInit() {
	memset(this, 0, sizeof(SBgmControl));
}

// 音楽ファイルをロードする
void SBgmControl::Load() {
	Bgm[BGM_TITLE].Handle = LoadSoundMem("music/title.mp3");
	SetLoopPosSoundMem(0, Bgm[BGM_TITLE].Handle);

	Bgm[BGM_GAMEMAIN].Handle = LoadSoundMem("music/game_main.mp3");
	SetLoopPosSoundMem(0, Bgm[BGM_GAMEMAIN].Handle);

	Bgm[BGM_GAMECLEAR].Handle = LoadSoundMem("music/game_clear.mp3");
	SetLoopPosSoundMem(0, Bgm[BGM_GAMECLEAR].Handle);

}



// SE------------------------------------------------
// 全体処理
void SSeControl::Process() {
	for (int i = 0; i < SE_NUM; i++) {					// 全ての効果音
		if (Se[i].Count != 0) {							// 再生したのなら
			Se[i].Count--;								// インターバル更新
		}
	}

//	DrawString(20, 20, "１～４を押すことで効果音が鳴ります", Black);
	if (Key[KEY_INPUT_1] == 1) {
		Play(SE_PIPIPI);
	}
	if (Key[KEY_INPUT_2] == 1) {
		Play(SE_BELL);
	}
	if (Key[KEY_INPUT_3] == 1) {
		Play(SE_BOM_LONG);
	}
	if (Key[KEY_INPUT_4] == 1) {
		Play(SE_BOM_SHORT);
	}
}

// 最初の初期化
void SSeControl::FirstInit() {
	memset(this, 0, sizeof(SSeControl));				// 全ての変数を０にする
}

// 再生する
void SSeControl::Play(int HandleIndex) {
	if (Se[HandleIndex].Count == 0) {					// 再生可能時間なら
		PlaySoundMem(Se[HandleIndex].Handle, DX_PLAYTYPE_BACK);		// 再生
		Se[HandleIndex].Count = Se[HandleIndex].Interval;	// 最小待ち時間を指定
	}
}

// 音楽ファイルをロードする
void SSeControl::Load() {
	Se[SE_PIPIPI].Handle = LoadSoundMem("music/pipipi.wav");	// ロード
	Se[SE_PIPIPI].Interval = 5;									// 最低待ち時間

	Se[SE_BELL].Handle = LoadSoundMem("music/bell.wav");
	Se[SE_BELL].Interval = 5;

	Se[SE_BOM_LONG].Handle = LoadSoundMem("music/bom_long.wav");
	Se[SE_BOM_LONG].Interval = 5;

	Se[SE_BOM_SHORT].Handle = LoadSoundMem("music/bom_short.wav");
	Se[SE_BOM_SHORT].Interval = 5;
}

