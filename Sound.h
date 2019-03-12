#ifndef _SOUND_H_
#define _SOUND_H_

enum eBGM_INDEX {
	BGM_TITLE, BGM_GAMEMAIN, BGM_GAMECLEAR, BGM_GAMEOVER
};

// BGMコントロール
const int BGM_NUM = 16;						// BGMの数
struct SBgmControl {
	bool PlayFlag;							// 再生中かどうか
	int NowPlayIndex;						// 再生中の添え字
	struct {
		int Handle;							// ハンドル
		int Count;							// 再生時間(フレーム)
	}Bgm[BGM_NUM];							// BGMの数だけ用意する

	void Process();							// 全体処理
	void FirstInit();						// 最初の初期化
	void ChangePlay(int HandleIndex = -1);	// 引数のBGMを再生する。
	void Load();							// ファイルロード
};

enum eSE_INDEX {
	SE_PIPIPI, SE_BELL, SE_BOM_LONG, SE_BOM_SHORT
};

// SEコントロール
const int SE_NUM = 16;						// SEの数
struct SSeControl {
	struct {
		int Handle;
		int Interval;
		int Count;
	}Se[SE_NUM];
	void Process();							// 全体処理
	void FirstInit();						// 最初の初期化
	void Play(int HandleIndex);
	void Load();							// ファイルロード
};

#endif