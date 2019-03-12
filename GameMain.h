
#ifndef _GAMEMAIN_H_
#define _GAMEMAIN_H_

const int MG_NUM = 10;		 //MAIN_GRAPHIC_NUMの略
enum eMG_INDEX {
	//MG_BACK,
	MG_RESET,
};

struct SGameMain {
	int Graphic[MG_NUM];	// グラフィック

	void Process();			// この中でループする
	void Init();			// 初期化
	void FirstInit();		// コンストラクタ
	void Load();			// ロード
	void Draw();			// 描画系をここにまとめる
};

#endif