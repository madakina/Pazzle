#ifndef _GAMECLEAR_H_
#define _GAMECLEAR_H_

const int CG_NUM = 8; //CLEAR_GRAPHIC_NUMの略
enum eCG_INDEX {
	CG_CLEAR,
	CG_BACK,CG_NEXT, CG_TOP,
	CG_MAP1, CG_MAP2, CG_MAP3,
};

struct SGameClear {
	int Graphic[CG_NUM];	// グラフィック

	void Process();			// この中でループする
	void Init();			// 初期化
	void FirstInit();		// コンストラクタ
	void Load();			// ロード
	void Draw();			// 描画系をここにまとめる
};

#endif